//
//  main.cpp
//  Assignment8Part1
//
//  Created by brian on 7/10/22.
//  program acts as a filter as it encrypts and decryptes files using a addition cypher
//
#include <iostream>
#include <fstream>
using namespace std;

void encrypt(ifstream&, fstream&, const int);
void decrypt(fstream&, ofstream&, const int);

int main()
{
    //imports files to read and manipulate
    ifstream iFile("/Users/messenger01/Desktop/decrypted.txt");
    fstream ioFile("/Users/messenger01/Desktop/encrypted.txt", ios::out | ios::in);
    ofstream oFile("/Users/messenger01/Desktop/crypted.txt");
    
    //defines variables
    int code;
    cout << "This program will encrypt and decrypt a file using a user defined code.\n";
    cout << "Enter a code: ";
    cin >> code;
    cin.ignore();
    
    encrypt(iFile, ioFile, code);
    decrypt(ioFile, oFile, code);
    
    //closes files
    iFile.close();
    ioFile.close();
    oFile.close();
    return 0;
}

//function encryptes a files by adding a specific number to all the ASCII chars
void encrypt(ifstream& decryptFile, fstream& encryptFile, const int code)
{
    char ch;
    decryptFile.get(ch);
    
    //shows encrypted contents
    cout << "\nThe output of the encrypted file is: ";
    
    while(!decryptFile.eof())
    {
        ch += code;
        cout << ch;
        encryptFile.put(ch);
        decryptFile.get(ch);
    }
}

//function decrypts files by subtracting a specific numer to all the ASCII chars
void decrypt(fstream& encryptFile, ofstream& decryptFile, const int code)
{
    //defines variables and moves read head of encryFile to the starting byte
    encryptFile.seekg(0L, ios::beg);
    char ch;
    encryptFile.get(ch);
    
    //shows decrypted output
    cout << "\nThe output of the decrypted file is: ";
    
    while(!encryptFile.eof())
    {
        ch -= code;
        cout << ch;
        decryptFile.put(ch);
        encryptFile.get(ch);
    }
    cout << endl;
}

