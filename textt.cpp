// FCAI – Programming 1 – 2022 - Assignment 4
// Program: text-editor.cpp
// Author: Abdallah Hussein Ibrahim Hussein - Esraa Mahmoud Abdelmohsen - Youssef Abdelghafar Abdeltawab
// IDs: 20210235 - 20210063 - 20210474
// Group: A
// Date: April  2022
// Section: 5,6
#include "text_app.cpp"
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
