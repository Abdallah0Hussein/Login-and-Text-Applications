#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
void addition();                              // Author: Esraa Mahmoud Abdelmohsen - 20210063
void erase();                                 // Author: Esraa Mahmoud Abdelmohsen - 20210063
void display();                               // Author: Esraa Mahmoud Abdelmohsen - 20210063
void encrypt();                               // Author: Esraa Mahmoud Abdelmohsen - 20210063
void decrypt();                               // Author: Esraa Mahmoud Abdelmohsen - 20210063

int main()
{

    int num_of_filter;
    cin>>num_of_filter;

    if (num_of_filter == 1)
    {
        addition();
        main();
    }
    if (num_of_filter == 2)
    {
        display();
        main();
    }
    if (num_of_filter == 3)
    {
        erase();
        main();
    }
    if (num_of_filter == 4)
    {
        encrypt();
        main();
    }
    if (num_of_filter == 5)
    {
        decrypt();
        main();
    }
    
}
// this function to add content to file without lose the original content
void addition()
{
    ofstream add;                  // ofstream to write in the file .
    add.open(file_name, ios::app); // function app to add content to file without lose the original content.
    string text;
    cout << "if you want end the text ; write EOF : ";
    while (getline(cin, text, '\n'))
    {
        if (text == "EOF") // to end the function
        {
            break;
        }
        if (text == "\n") // to move to second line
            add << '\n';
        add << text << endl;
    }
    add.close(); // close file
    cout << "Done!!\n";
}
// displays the current file content to the user.
void display()
{
    ifstream read; // ifstream to read from file
    read.open(file_name);
    string text;
    while (getline(read, text))
    {
        cout << text << endl;
    }
    read.close(); // close file
}
// this function to clear the content from file
void erase()
{
    ofstream erase;
    erase.open(file_name);
    erase.clear(); // .clear() to erase content from the file (.clear()=.erase())
    erase.close(); // close file
    cout << "Done!!\n";
}
void encrypt()
{
    ifstream txt;     // file which i read from
    ofstream encrypt; // file which i wrote in
    txt.open(file_name, ios::out | ios::app);
    string mystring;
    string encrypted;
    int j = 0;
    while (txt.peek() != EOF)   // work until end the file(read from).
        mystring += txt.get();  // take strings from file and check about character in it
    while (mystring[j] != '\0') // in the end of the file
    {
        if (mystring[j] == '\n') // if found new line
        {
            encrypted += '\n'; // add it to the file encrypted
            j++;
            continue;
        }
        char x = mystring[j] + 1; // make the character = next character
        encrypted += x;
        j++;
    }
    encrypt.open(file_name, ios::trunc);
    encrypt << encrypted << endl;
    encrypt.close();
    txt.close();
    cout << "Done!!\n";
}
void decrypt()
{
    ifstream encrypt; // file which i read from
    ofstream decrypt; // file which i wrote in
    encrypt.open(file_name, ios::out | ios::app);
    string mystring;
    string decrypted;
    int j = 0;
    while (encrypt.peek() != EOF)  // work until end the file(read from).
        mystring += encrypt.get(); // take strings from file and check about character in it
    while (mystring[j] != '\0')    // in the end of the file
    {
        if (mystring[j] == '\n') // if found new line
        {
            decrypted += '\n'; // add it to the file decrypted
            j++;
            continue;
        }
        char x = mystring[j] - 1; // make the character = previous character
        decrypted += x;
        j++;
    }
    decrypt.open(file_name, ios::trunc);
    decrypt << decrypted << endl;
    decrypt.close();
    encrypt.close();
    cout << "Done!!\n";
}