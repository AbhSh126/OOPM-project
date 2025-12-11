#include "quiz.h"
#include <fstream>
#include <sstream>

bool User::login() {
    cout << "\n===== LOGIN =====\n";
    
    cout << "Enter roll no: ";
    cin >> roll;

    cout << "Enter Password: ";
    cin >> password;

    

    ifstream fin("users.txt");
    string fileUser, filePass, fileRoll;
    int fileAge;

    while (fin >> fileUser >> filePass >> fileAge >> fileRoll) {
        if (fileRoll == roll && filePass == password) {
            age = fileAge;
            name = fileUser;
            cout << "\n✔ Login Successful!\n";
            return true;
        }
    }

    cout << "\n❌ Login Failed! User not found or wrong password.\n";
    return false;
}

void User::signUp() {
    cout << "\n===== SIGN UP =====\n";

    cout << "Enter Username: ";
    cin >> name;

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Roll No: ";
    cin >> roll;

    ofstream fout("users.txt", ios::app);
    fout << name << " " << password << " " << age << " " << roll << endl;

    cout << "\n✔ Signup successful! You can now log in.\n";
}

void User::saveHistory(int score) {
    ofstream fout("history.txt", ios::app);
    fout << name << " " << score << endl;
}

void User::showHistory() {
    ifstream fin("history.txt");
    string user;
    int score;
    bool found = false;


    cout << "\n===== YOUR PREVIOUS ATTEMPTS =====\n";

    while (fin >> user >> score) {
        if (user == name) {
            cout << "Score: " << score << endl;
            found = true;
            
        }
    }

    if (!found)
        cout << "No attempts found!\n";

    cout << "=================================\n";
    
}

void User::showDetails() {
     cout << " =========================== " << endl;
     cout << " welcome to the quiz game" << endl;
     cout <<  " ===========================" << endl;
       cout << " " << endl;
       
    cout << "\n===== USER PROFILE =====\n";
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll No: " << roll << endl;
    cout << "=========================\n";
}
