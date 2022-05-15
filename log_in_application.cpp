#include <iostream>
#include <string>
#include <regex>
#include<vector>
#include <fstream>
using namespace std;
struct user_profile
{
    string id,password,email;
};
void existing(vector<user_profile>& user)
{
    ifstream userfile("info.txt");
    while(!userfile.eof())
    {
        user_profile nextuser;
        userfile>>nextuser.id;
        userfile>>nextuser.password;
        userfile>>nextuser.email;
        user.push_back(nextuser);
    }

}

void number() {
    string num;
    cout << "enter your number : \n";
    getline(cin, num);
    regex valid("01[0-2,5]{1}[0-9]{8}+");

    if (regex_match(num, valid))
    {
        cout << "num valid";
    }
    else
    {
        while (!regex_match(num, valid))
        {
            cout<<"enter your valid number";
            getline(cin, num);
            regex valid("01[0-2,5]{1}[0-9]{8}+");

            if (regex_match(num, valid))
            {
                cout << "num valid";
                break;
            }
        }
    }
}
void p_info()
{
    string username;
    cout<<"enter your name in format (character or '_')";
    cin>>username;
    regex valid("[a-zA-Z,_]+");
    if(regex_match(username,valid))
    {
        cout<<"valid";
    }
    else
    {
        while (!regex_match(username,valid))
        {
            cout<<"enter your name in format (character or '_')";
            cin>>username;
            if(regex_match(username,valid))
            {
                cout<<"valid";
                break;
            }

        }
    }
    string password;
    cout<<"enter password for registration";
    cin>>password;


}
void email()
{
    string email;
    cout<<"enter your email";
    cin>>email;
    regex valid("\\w+@gmail\\.com");
    if(regex_match(email,valid))
        cout<<"valid";
    else
    {
        while(!regex_match(email,valid))
        {
            cout<<"not valid \n enter valid email";
            cin>>email;
            regex valid("\\w+@gmail\\.com");
            if(regex_match(email,valid)) {
                cout << "valid";
                break;
            }

        }
    }

}
int main()
{
        number();
        p_info();

}

