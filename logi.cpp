#include"login_app.cpp"
int main()
{
    while (true)
    {
        display_menu();
        if (choice == "1") // REGISTRATION
        {
            // deCipher();
            registeration();
            // Cipher();
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

