#include"login_app.h"
string display_menu()
{
    cout << "Enter the num of op you want!\n"
            " 1-Register\n 2-Login\n 3-Change password\n 4-Exit\n-->";
    getline(cin, choice);
    return choice;
}
// ...........................................................................................
void registeration()
{
    check_UN();
    check_E();
    check_PN();
    check_PW();
    saveData();
}
// ...........................................................................................
void login()
{

    int count = 3;
    while (true)
    {
        cout << "Enter your UserName and your Password :\n";
        cout << "Enter your UserName :\n";
        getline(cin, username);
        cout << "Enter your Password :\n";
        // Hide_password_recently_pass();
        coverpass(password);
        Cipher(password);
        cout << "\n";
        if (!(valid_Exist_user() && valid_Exist_pass()))
        {
            cout << "Failed login. Try again. \n";
            count -= 1;
            if (count == 0)
            {
                cout << "Your Denied from  access to the System \n \n";
                break;
            }
        }
        else
        {
            cout << "Successful login, welcome " << username << "\nWelcome in Login Page : \n";
            mark = true;
            break;
        }
    }
}
// ...........................................................................................
void changePassword()
{
    // existing();
    saving = false;
    login();
    check_PW(); // enter the new password in case that choice == 3 and change the old password with the new one
    // saveData2();
    saveData();
}
// ...........................................................................................
void existing()
{
    userfile.open("info.txt", ios::in);
    while (!userfile.eof())
    {
        user_profile nextuser;
        userfile >> nextuser.username;
        userfile >> nextuser.email;
        userfile >> nextuser.phonenum;
        userfile >> nextuser.password;
        user.push_back(nextuser); // from file to vector
    }
    userfile.close();
}
void saveData()
{
    userfile.close();
    if (valid1 && choice == "1" && saving)
    {
        userfile.open("info.txt", ios::app);
        userfile << username;
        userfile << " ";
        userfile << email;
        userfile << " ";
        userfile << phonenum;
        userfile << " ";
        Cipher(password);
        userfile << password;
        userfile << "\n";
        userfile.close();
    }
    else if (choice == "1" && !saving)
    {
        char line[100];
        vector<string> text;
        int k = 0;
        userfile.close();
        userfile.open("info.txt");
        while (!userfile.eof())
        {
            userfile.getline(line, 100, '\n');
            text.push_back(string(line));
        }
        int x, z;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i].find(old_Pass, 0) < 1000)
            {
                x = text[i].find(old_Pass, 0);
                z = i;
            }
        }
        for (int j = x; j < (x + new_pass.size()); j++)
        {
            text[z][j] = new_pass[k];
            k++;
        }
        userfile.close();
        userfile.open("info.txt", ios::out);
        for (int i = 0; i < text.size(); i++)
        {
            userfile << text[i];
            if (i == text.size() - 1)
                continue;
            else
                userfile << '\n';
        }
        userfile.close();
    }
    valid1 = false;
    saving = true;
}

// ...........................................................................................
void check_UN()
{
    cout << "enter your name in format (characters or '_'):\n";
    getline(cin, username);
    regex valid("[a-zA-Z,_]+");
    if (!regex_match(username, valid))
    {
        while (!regex_match(username, valid))
        {
            cout << "enter your name in format (characters or '_'):\n";
            getline(cin, username);
            if (regex_match(username, valid))
            {
                break;
            }
        }
    }
    else
    {
        if (valid_Exist_user())
        {
            cout << "this username is taken before. choose another one\n";
            check_UN();
        }
        else
            valid1 = true;
    }
}
// ...........................................................................................
bool valid_Exist()
{
    existing();
    bool x = false;
    for (user_profile emails : user)
    {
        if (email == emails.email)
        {
            x = true; // to finish looping in the whole file
            break;
        }
        else
        {
            x = false;
        }
    }
    return x;
}
bool valid_Exist_pass()
{
    existing();
    bool x = false;
    for (user_profile passw : user)
    {
        if (password == passw.password)
        {
            x = true; // to finish looping in the whole file
            break;
        }
        else
        {
            x = false;
        }
    }
    return x;
}
bool valid_Exist_user()
{
    existing();
    bool x = false;
    for (user_profile name : user)
    {
        if (username == name.username)
        {
            x = true; // to finish looping in the whole file
            break;
        }
        else
        {
            x = false;
        }
    }
    return x;
}
// ...........................................................................................
void check_E()
{
    cout << "enter your email\n";
    getline(cin, email);
    regex valid("\\w+@gmail\\.com");
    if (!regex_match(email, valid))
    {
        while (!regex_match(email, valid))
        {
            cout << "not valid \n enter a valid email\n";
            getline(cin, email);
            regex valid("\\w+@gmail\\.com");
            if (regex_match(email, valid))
            {
                break;
            }
        }
    }
    else
    {
        if (valid_Exist())
        {
            cout << "this email is taken before. choose another one\n";
            check_E();
        }
        else
            valid1 = true;
    }
}
// ...........................................................................................

// ...........................................................................................
void check_PN()
{
    cout << "enter your number: \n";
    getline(cin, phonenum);
    regex valid("01[0-2,5]{1}[0-9]{8}+");
    if (!regex_match(phonenum, valid))
    {
        while (!regex_match(phonenum, valid))
        {
            cout << "enter a valid number: \n";
            getline(cin, phonenum);
            regex valid("01[0-2,5]{1}[0-9]{8}+");
            if (regex_match(phonenum, valid))
            {
                cout << "num valid\n";
                break;
            }
        }
    }
    else
        valid1 = true;
}

// ...........................................................................................

// ...........................................................................................
void check_PW()
{
    if (choice == "1")
    {
        cout << "Your password should be 12-35 digits.\n";
        cout << "It shoud starts with >>> 3-10 digits <<< of each: small letters, capital letters, numbers then special charcters Respectively.\n";
        cout << "For example: asdASD111!!!\n";

        while (true)
        {
        here:
            cout << "enter the password\n";
            coverpass(password);
            //         getline(cin, password);
            if (valid_PW())
            {
                valid1 = true;
                string confirm;
                while (true)
                {
                    cout << "Please confirm your password:\n";
                    coverpass(confirm);
                    //                     getline(cin,confirm);
                    if (!(password == confirm))
                    {
                        cout << "Your repeated password doesn't match with the first one.\n";
                    }
                    else
                    {
                        new_pass = password;
                        Cipher(new_pass);
                        break;
                    }
                }
            }
            else
            {
                cout << "NOT a valid password, try again.\nEnter the password:\n";
                goto here;
            }
            break;
        }
    }
    else if (choice == "3" && mark == true)
    {

        while (true)
        {
            cout << "Enter Your Old Password:\n";
            coverpass(old_Pass);
            Cipher(old_Pass);
            //                     getline(cin,confirm);
            if (!(password == old_Pass))
            {
                cout << "Your old password is wrong.\n";
            }
            else
            {
                cout << "Enter Your New Password Twice to accept info and the two password should the same things :\n";
                choice = "1";
                check_PW();
                break;
            }
        }
    }
}
// ...........................................................................................
bool valid_PW()
{
    regex valid("([a-z]{3,10}[A-Z]{3,10}[0-9]{3,10}[!-/:-@]{3,10})");
    return (regex_match(password, valid));
}

void coverpass(string &final_password)
{
    cout << "Press any key to start typing your password then type\n";
    bool negative = false;
    final_password = "";
    char ch = getch();           // read a single character from the console and hold the output screen for some time until the user enter an enter-button
    while ((ch = getch()) != 13) // if the user enters an enter-button
    {
        if (ch == 8) // if the user enters a backspace-button
        {
            cout << "\b \b";
            if (final_password.size() == 0 || ch == 32 || ch == 9) // if the user enters a space or a tab
            {
                continue;
            }
            else
            {
                final_password.pop_back(); // remove and reduce the size by one.
            }
        }
        else if (ch < 0 || negative) // to avoid pressing arrows, home and end buttons
        {
            if (negative)
                negative = false;
            else
                negative = true;
            continue;
        }
        else
        {
            putchar('*'); // replace with (*)
            final_password += ch;
        }
    }
    cout << "\nYou have entered: " << final_password << '\n';
}

void Cipher(string &pass)
{
    for (int i = 0; i < pass.size(); i++)
    {
        pass[i] = char(int(pass[i] + 1));
    }
}