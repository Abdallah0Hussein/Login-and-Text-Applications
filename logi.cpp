// FCAI – Programming 1 – 2022 - Assignment 4
// Program: login_app.cpp
// Author: Abdallah Hussein Ibrahim Hussein - Esraa Mahmoud Abdelmohsen - Youssef Abdelghafar Abdeltawab
// IDs: 20210235 - 20210063 - 20210474
// Group: A
// Date: May  2022
// Section: 5,6
// ...........................................................................................
#include "login_app.cpp"
int main()
{
    while (true)
    {
        display_menu();
        if (choice == "1") // REGISTRATION
        {
            registeration();
        }
        else if (choice == "2") // LOGIN
        {
            login();
        }
        else if (choice == "3") // CHANGE PASSWORD
        {
            changePassword();
        }
        else if (choice == "4") // EXIT
        {
            break;
        }
        else
        {
            cout << "\nwrong input !\n";
            continue;
        }
    }
}
// ...........................................................................................
