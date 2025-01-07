#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Temp {
    string username, email, password;
    fstream file;

public:
    void login();
    void signup();
    void forget();
};

int main() {
    Temp obj;
    int choice;
    while (true) {
        cout << "\n1 ---> Login" << endl;
        cout << "2 ---> Signup" << endl;
        cout << "3 ---> Forget Password" << endl;
        cout << "4 ---> Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                obj.login();
                break;
            case 2:
                obj.signup();
                break;
            case 3:
                obj.forget();
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid Choice! Try again." << endl;
        }
    }
}

void Temp::signup() {
    cout << "\nEnter your username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter your Email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << username << '*' << email << '*' << password << '\n';
    file.close();

    cout << "Signup successful!" << endl;
}

void Temp::login() {
    string searchName, searchPass;
    cout << "\n-------------------------Login-----------------" << endl;
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, searchName);
    cout << "Enter your password: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "No data found. Please sign up first!" << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string fileUsername, fileEmail, filePassword;

        getline(ss, fileUsername, '*');
        getline(ss, fileEmail, '*');
        getline(ss, filePassword, '*');

        if (fileUsername == searchName && filePassword == searchPass) {
            cout << "\nAccount Login Successful!" << endl;
            cout << "Username: " << fileUsername << endl;
            cout << "Email: " << fileEmail << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Invalid username or password!" << endl;
    }
}

void Temp::forget() {
    string searchName, searchEmail;
    cout << "\nEnter your username: ";
    cin.ignore();
    getline(cin, searchName);
    cout << "Enter your email: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "No data found. Please sign up first!" << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string fileUsername, fileEmail, filePassword;

        getline(ss, fileUsername, '*');
        getline(ss, fileEmail, '*');
        getline(ss, filePassword, '*');

        if (fileUsername == searchName && fileEmail == searchEmail) {
            cout << "\nAccount Found!" << endl;
            cout << "Your Password: " << filePassword << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Account not found!" << endl;
    }
}
