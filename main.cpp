#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void registered ()
{
    string username, password, name, email;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter password: " << endl;
    cin >> password;
    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter email: " << endl;
    cin >> email;
    ofstream userFile("users.txt", ios::app);
    userFile << username << " " << password  << " " << name << " " << email  << endl;
    userFile.close();
    cout << endl;
    cout << "Registration successful!" << endl;
}
bool login()
{
    string username, password, fileUsername, filePassword;
    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;
    ifstream userFile("users.txt");
    while (userFile >> fileUsername >> filePassword)
    {
        if (fileUsername == username && filePassword == password)
        {
            cout << "Login successful!" << endl;
            userFile.close();
            return true;
        }
    }
    cout << "Invalid username or password." << endl;
    userFile.close();
    return false;
}
int main()
{
    int choice;
    cout << "Welcome to Login & Registeration system" << endl;
    cout << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << endl;
    cout << "Please enter the choice from the above: ";
    cin >> choice;
    if (choice == 1)
    {
        registered ();
    }
    else if (choice == 2)
    {
        login();
    }
    else
    {
        cout << "Invalid choice" << endl;
        cout << "Enter the choice again " << endl;
        cout << endl;
        main();
    }
    return 0;
}
