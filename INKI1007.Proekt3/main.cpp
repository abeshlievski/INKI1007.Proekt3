#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int najgolemBroj(string num) {
    int max;
    for (int i = 0; i < num.size(); i++) {
        int broj = stoi(string(1, num[i])); 

        if (broj > max) {
            max = broj;
        }
    }
    return max;
}

int main(){
    string filename = "sodrzina.txt";
    ifstream file(filename);
    string sodrzina1((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    cout << sodrzina1 << endl;
    
    string BrojNaIndeksIme = sodrzina1.substr(0, 11);
    string IzveduvacTekst = sodrzina1.substr(11);
    
    string brojNaIndeks;
    cout<<"Vnesi go brojot na indeks: ";
    cin>>brojNaIndeks;
    
    BrojNaIndeksIme.insert(4, brojNaIndeks);
    int max = najgolemBroj(brojNaIndeks);
    cout <<"Najgolemiot broj vo "<<brojNaIndeks<<" e: "<<max<<endl<<endl;
    
    string sodrzina = BrojNaIndeksIme + IzveduvacTekst;
    cout<<sodrzina<<endl;
    
    vector<char> CharVec;
    
    for (int i = 0; i < sodrzina.length(); i++) {  // Go pretvorame stringot vo char, mu dodavame na sekoj karakter na negovata Ascii vrednost +7
        char newChar = sodrzina[i] + max;          // i ja smestuvame vrednosta vo vektor
        CharVec.push_back(newChar); 
    }
    cout<<" Vektorot CharVec : \n ";
    for (int i = 0; i < CharVec.size(); i++) {    // Go pecatime vektorot CharVec
        cout << CharVec[i] << " ";
    }
    cout << endl;
   
    sort(CharVec.begin(), CharVec.end());    // Go sortirame vektorot CharVec
    cout<<" \n Sortiran vektorot CharVec : \n ";
    for (int i = 0; i < CharVec.size(); i++) {    // Go pecatime vektorot CharVec sortiran
        cout << CharVec[i] << " ";
    }
    
    ofstream outputFile("output.txt");
    // Proveruvame dali fajlot uspesno se otvori
    if (!outputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }
    // Go zapisuvame vektorot so pomos na iterator
    for (int i = 0; i < CharVec.size(); i++) {
        outputFile << CharVec[i] << " ";
    }
    outputFile.close();
    
    return 0;
}