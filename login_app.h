#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
struct user_profile
{
    string username, email, phonenum, password;
};
string display_menu();
string old_Pass;
string new_pass;
bool saving = true;
void existing();
void registeration();
void login();
void changePassword();
void check_UN();
void check_E();
void check_PN();
void check_PW();
bool valid_PW();
void coverpass(string &final_password);
void saveData();
bool valid_Exist();
bool valid_Exist_pass();
bool valid_Exist_user();
void deCipher(string &pass);
vector<user_profile> user;
fstream userfile;
string choice, username, email, phonenum, password;
void Cipher(string &pass);
void login();
bool valid1 = false;
bool mark = false;