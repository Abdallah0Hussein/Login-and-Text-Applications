// FCAI – Programming 1 – 2022 - Assignment 4
// Program: text-editor.cpp
// Author: Abdallah Hussein Ibrahim Hussein - Esraa Mahmoud Abdelmohsen - Youssef Abdelghafar Abdeltawab
// IDs: 20210235 - 20210063 - 20210474
// Group: A
// Date: April  2022
// Section: 5,6

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
void Merge();                                 // Author: Abdallah Hussein Ibrahim Hussein - 20210235
void count_Words();                           // Author: Abdallah Hussein Ibrahim Hussein - 20210235
void count_Chars();                           // Author: Abdallah Hussein Ibrahim Hussein - 20210235
void count_Lines();                           // Author: Abdallah Hussein Ibrahim Hussein - 20210235
void search_Word();                           // Author: Abdallah Hussein Ibrahim Hussein - 20210235
void the_words_repeated();                    // Author: Youssef Abdelghafar Abdeltawab - 20210474
void convert_the_all_letters_to_lower_case(); // Author: Youssef Abdelghafar Abdeltawab - 20210474
void convert_the_all_letters_to_upper_case(); // Author: Youssef Abdelghafar Abdeltawab - 20210474
void First_Char_Capitalize();                 // Author: Youssef Abdelghafar Abdeltawab - 20210474
void save();                                  // Author: Youssef Abdelghafar Abdeltawab - 20210474
void creat_file();

fstream myfile;      // file from kind ifstream to read the file.
char file_name[100]; // file name from char data type to input file name.
int main()
{
    creat_file(); // this function to exist file if not found it create new file.

    cout << "Ahlan ya user ya habibi :D\n";
    cout << "Please select what you want or enter 16 to exit: \n";
    cout << "1- Add new text to the end of the file\n";
    cout << "2- Display the content of the file\n";
    cout << "3- Empty the file\n";
    cout << "4- Encrypt the file content\n";
    cout << "5- Decrypt the file content\n";
    cout << "6- Merge another file\n";
    cout << "7- Count the number of words in the file.\n";
    cout << "8- Count the number of characters in the file\n";
    cout << "9- Count the number of lines in the file\n";
    cout << "10- Search for a word in the file\n";
    cout << "11- Count the number of times a word exists in the file\n";
    cout << "12- Turn the file content to upper case\n";
    cout << "13- Turn the file content to lower case\n";
    cout << "14- Turn file content to 1st caps (1st char of each word is capital)\n";
    cout << "15- Save\n";
    cout << "16- Exit\n";
    // choose number.
    int num_of_filter;
    cin.ignore(99999, '\n'); // Validate the input.
    cin.clear();
    string get_num;
    while (true)
    {
        getline(cin, get_num);
        if (get_num == "1" || get_num == "2" || get_num == "3" || get_num == "4" || get_num == "5" || get_num == "6" || get_num == "7" || get_num == "8" || get_num == "9" || get_num == "10" || get_num == "11" || get_num == "12" || get_num == "13" || get_num == "14" || get_num == "15" || get_num == "16")
        {
            num_of_filter = stoi(get_num);
            break;
        }
        else
        {
            cout << "INVALD\n";
        }
    }

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
    if (num_of_filter == 6)
    {
        Merge();
        main();
    }
    if (num_of_filter == 7)
    {
        count_Words();
        main();
    }

    if (num_of_filter == 8)
    {
        count_Chars();
        main();
    }
    if (num_of_filter == 9)
    {
        count_Lines();
        main();
    }
    if (num_of_filter == 10)
    {
        search_Word();
        main();
    }
    if (num_of_filter == 11)
    {
        the_words_repeated();
        main();
    }
    if (num_of_filter == 12)
    {
        convert_the_all_letters_to_upper_case();
        main();
    }
    if (num_of_filter == 13)
    {
        convert_the_all_letters_to_lower_case();
        main();
    }
    if (num_of_filter == 14)
    {
        First_Char_Capitalize();
        main();
    }
    if (num_of_filter == 15)
    {
        save();
        main();
    }
    if (num_of_filter == 16)
    {
        return 1;
    }
    return 0;
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
// this function to exist file if not found it create new file.
void creat_file()
{
    cout << "Please enter the name of the file: ";
    cin >> file_name; // file name from char data type to input file name.

    string file1 = file_name;
    if (file1.find(".txt") == -1) // if the user didn't enter the extinsion .txt then add .txt
    {
        file1 = strcat(file_name, ".txt");
    }
    myfile.open(file1, ios::in | ios::app);
    if (myfile.fail())
    {
        cout << "This File doesn't Exists.\n";
        cout << "This is a new file. I created it for you.\n";
        myfile.open(file1, ios::out | ios::app);
        cout << "Your file name is: " << file1 << '\n';
    }
    else
    {
        cout << "This File Already Exists.\n ";
    }
}

void search_Word()
{
    cout << "Enter the word: ";
    string search1;
    ifstream myfile;
    string new_str = "";
    cin >> search1;
    bool find = false;
    myfile.open(file_name, ios::out);
    for (int i = 0; i < search1.length(); i++)
    {
        search1[i] = (char)tolower(search1[i]); // make the word he want to search as a lower case and add it to string search1
    }
    while (getline(myfile, new_str)) // add all file contents to new_string
    {
        for (int i = 0; i < new_str.length(); i++)
        {
            new_str[i] = (char)tolower(new_str[i]); // all file contents which are in new_str make them in lowercase while looping
                                                    // for example ali = Ali = aLi and so on
        }
        if (new_str.find(search1) != -1) // if find the word
        {
            cout << "The Word was found in the file. :'D\n";
            find = true; // when u find it make it true then break and stop looping
            break;
        }
    }
    if (!find)
        cout << "The word was not found in the file. :(\nDone!!\n";
}
void count_Lines()
{
    ifstream myfile;
    string new_str = "";
    int tot_Lines = 0;
    int i = 0;
    myfile.open(file_name, ios::out);
    while (myfile.peek() != EOF) // loop until u go to EOF (End Of File)
    {
        new_str += myfile.get();
    }
    while (new_str[i] != '\0') // while we havn't reached the end of file (string) then continue looping
    {
        if (new_str[i] == '\n') // if u find a new line then increase tot_Lines by one
            ++tot_Lines;
        i++;
    }
    ++tot_Lines; // add one more because number of total Lines = '\n' + 1. 
    cout << "The number of lines in the file is: " << tot_Lines << "\nDone!!\n";
}
void count_Chars()
{
    ifstream myfile;
    string new_str = "";
    int num = 0;
    string enter;
    int option;
    cout << "Choose what you want: \n";
    cout << "1- Count the number of characters without spaces.\n";
    cout << "2- Count the number of characters with spaces.\n";
    myfile.open(file_name, ios::out);
    while (true) // definsive
    {
        getline(cin, enter); 
        if (enter == "1" || enter == "2")
        {
            option = stoi(enter);
            break;
        }
        else
        {
            cout << "INVALD\n";
        }
    }
    if (option == 1)
    {
        while (getline(myfile, new_str)) // add all file contents to string new_str
        {
            for (int i = 0; i < new_str.length(); i++)
            {
                if ((int)new_str[i] != 32) // while there is no spaces increase int num
                    ++num;
            }
        }
        cout << "The number of characters without spaces in the file is: " << num << "\nDone!!\n";
    }
    if (option == 2)
    {
        while (getline(myfile, new_str)) // add all file contents to string new_str
        {
            for (int i = 0; i < new_str.length(); i++) // increase int num even if there is a space
            {
                ++num;
            }
        }
        cout << "The number of characters with spaces in the file is: " << num << "\nDone!!\n";
    }
}
void count_Words()
{
    ifstream myfile;
    string new_str = "";
    int tot_Words = 0;
    int i = 0;
    int z = 0;
    myfile.open(file_name, ios::out);
    while (myfile.peek() != EOF) // loop until u go to EOF (End Of File)
    {
        new_str += myfile.get(); // add all file contents to string new_str as chars
        ++z;
    }
    while (new_str[i] != '\0') // while we havn't reached the end of file (string) then continue looping
    {
        if ((new_str[i] == ' ' && new_str[i + 1] != ' ' && new_str[i + 1] != '\n') || (new_str[i] == '\n' && new_str[i + 1] != '\n' && new_str[i + 1] != ' ') || new_str[i + 1] == '\0')
        {
            // if the file has more than one space and there is no end-line after then dont increase int tot_Words.
            // if the file has more than one end-line and there is no a space after then dont increase int tot_Words.
            ++tot_Words;
        }
        ++i;
    }
    cout << "The number of words in the file is: " << tot_Words << "\nDone!!\n";
}
void Merge()
{
    fstream myfile;
    fstream myfile2;
    char name[80];
    string new_str;
    getline(myfile, new_str); // add all file contents to string new_str
    cout << "Please input an existing file name to merge: ";
    cin >> name;
    string file1 = name;
    int i = 0;
    myfile.open(file_name, ios::app);
    if (file1.find(".txt") == -1) // if the user didn't enter the extinsion .txt then add .txt for the second file
    {
        file1 = strcat(name, ".txt");
    }
    myfile2.open(file1);
    if (myfile2.fail()) // if the file hasn't been opened
    {
        cout << "This File doesn't Exists.\n";
    }
    else
    {
        cout << "This File Already Exists.\n ";
        while (myfile2.peek() != EOF) // loop until u go to EOF (End Of File)
        {
            new_str += myfile2.get(); // add all file contents to string new_str as chars
        }
        while (new_str[i] != '\0') // while we havn't reached the end of file (string) then continue looping
        {
            myfile << new_str[i]; // save the file after merging in the first file
            ++i;
        }
    }
    myfile2.close();
    cout << "Done!!\n";
}

// Count the number of times a word exists in the file takes from the user a word and prints the number of times the word exists in the file.

// Count the number of times a word exists in the file takes from the user a word and prints the number of times the word exists in the file.
void the_words_repeated()
{
    ifstream myfile; // file from kind ifstream to read the file.
                     //    char name_files[100]; // file name from char data type to input file name.
    int counter = 0; // this counter to calc how many the word is repeated.

    //    cout << "enter the source file name with extension (like files.txt): " << endl;
    //    cout << "NAME_OF_FILE: " << " ";
    //    cin >> name_files; // file name do you want to read from it

    myfile.open(file_name);
    if (!myfile.is_open())
    { // if the file not open this message is appear.
        cout << "error in opening source file: ";
    }

    string word, text; // text the word you want to know how many it repeated and the word is variable to store the word in this variable
    cout << "enter your word do you want how many repeated: " << endl;
    cout << "THE WORD: ";
    cin >> text;
    while (myfile >> word) // files is the file will read from it.
    {
        if (word == text)
        {
            counter++; // counter = + counter + 1.. to calc how many the word repeated.
        }
    }
    cout << "THE NUMBER OF WORD REPETITION : "
         << " " << counter << endl; // print the number of word repeated.
    cout << "Done!!" << endl;
}

// this function to change all character to capital.
void convert_the_all_letters_to_upper_case()
{
    char text_file;    // the text in the file.
    string text_file2; // the variable to store the text_file to text_file2.
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;

    myfile.open(file_name, ios::out | ios::app); // using the mood out to read from file and append to add to the same file.
    system("cls");
    while (!myfile.eof())
    { // if i didn't move to the end countine in the loop.

        // when you meet char change it to capital if space ignore the space.
        myfile.get(text_file);
        text_file2 = text_file2 + char(toupper(text_file));
    }
    myfile2.open(file_name, ios::trunc); // mood trunc to remove the all old things and put the new edition.
    myfile2 << text_file2;               // to print in the file new edition
    cout << "Done!!" << endl;
}

// this function to change all character to small.
void convert_the_all_letters_to_lower_case()
{
    char text_file;    // the text in the file.
    string text_file2; // the variable to store the text_file to text_file2.
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;

    myfile.open(file_name, ios::out | ios::app); // using the mood out to read from file and append to add to the same file.
    system("cls");
    while (!myfile.eof())
    { // if i didn't move to the end countine in the loop.

        // when you meet char change it to small if space ignore the space.
        myfile.get(text_file);
        text_file2 = text_file2 + char(tolower(text_file));
    }
    myfile2.open(file_name, ios::trunc); // mood trunc to remove the all old things and put the new edition.
    myfile2 << text_file2;               // to print in the file new edition
    cout << "Done!!" << endl;
}

void First_Char_Capitalize()
{
    char text_file;    // the text in the file.
    string text_file2; // the variable to store the text_file to text_file2.
    int counter;       // this counter to make loop to all the text in the file.
    int counter2;
    counter = 0;
    counter2 = 0;
    text_file2 = "";
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name, ios::out | ios::app); // using the mood out to read from file and append to add to the same file.
    system("cls");
    while (!myfile.eof())
    { // if i didn't move to the end countine in the loop.

        myfile.get(text_file);
        if (counter == 0 || counter2 == counter)
        { // if the counter == counter2 this mean he is found space he is going to second condition
            // the  second condition mean if he meet space ignore it and change the first char to capital and the all char in word to small.
            text_file2 = text_file2 + char(toupper(text_file));
            counter++;
            continue;
        }
        if (text_file == 32 || text_file == '\n')
        {
            text_file2 = text_file2 + char(text_file);
            counter2 = counter;
            continue;
        }
        text_file2 = text_file2 + char(text_file);
    }
    myfile2.open(file_name, ios::trunc); // mood trunc to remove the all old things and put the new edition.
    myfile2 << text_file2;
    cout << "Done!!" << endl;
}

// function to doing save the file in to another file .
void save()
{
    char new_name[80]; // the new file you will store inside.
    char content;      // content in the old file.
    string content2;   // content in the new file.
    ifstream myfile;
    ofstream myfile2;
    myfile.open(file_name, ios::out | ios::app); // using the mood out to read from file and append to add to the another file.
    system("cls");
    cout << "please enter the new name of the file : ";
    cin >> new_name;
    string file = new_name;
    if (file.find(".txt") == -1)
    {
        file = strcat(new_name, ".txt");
    }
    while (!myfile.eof())
    { // if i didn't move to the end countine in the loop.

        // move the content from old file to new file.
        myfile.get(content);
        content2 = content2 + char(content);
    }
    myfile2.open(file, ios::out | ios::app); // using the mood out to read from old file and append to add to the new file.
    myfile2 << content2;
    cout << "Done!!" << endl;
}