#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// ==================== USER ====================
class User {
private:
    string name;
    string password;
    int age;
    string roll;

public:
    // Login + Signup
    bool login();
    void signUp();

    // Profile
    void showDetails();

    // History
    void saveHistory(int score);
    void showHistory();

    // Getter
    string getName() { return name; }
};

// ==================== QUESTION (MCQ) ====================
class Question {
private:
    string questionText;
    string optA, optB, optC, optD;
    char correctOption;

public:
    Question(string q, string a, string b, string c, string d, char correct);
    void display();
    bool checkAnswer(char userAns);
    void showCorrect();
};

//  FILL BLANK 
class FillBlank {
private:
    string question;
    string correctAns;

public:
    FillBlank(string q, string ans);
    void display();
    bool checkAnswer(string userAns);
    void showCorrect();
};

//LEADERBOARD 
class Leaderboard {
public:
    struct Entry {
        string name;
        int score;
    };

    vector<Entry> list;

    void load();
    void add(string name, int score);
    void sortLB();
    void save();
    void show();
};

// QUIZ ENGINE 
class Quiz {
private:
    Question* mcq[20];
    FillBlank* fb[10];
    int mcqCount;
    int fbCount;

public:
    Quiz();
    void addMCQ(Question* q);
    void addFB(FillBlank* f);
    int startMCQ();
    int startFillBlank();
    void showFinal(int mcqScore, int fbScore);
};

#endif
