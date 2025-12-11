#include "quiz.h"

Quiz::Quiz() { //constrcutor 
    mcqCount = 0;
    fbCount = 0;
}

// ============ QUESTION CLASS ============== //quiz.h
Question::Question(string q, string a, string b, string c, string d, char correct) {
    questionText = q;
    optA = a;
    optB = b;
    optC = c;
    optD = d;
    correctOption = toupper(correct);
}

void Question::display() {
    cout << "\n" << questionText << endl;
    cout << "A. " << optA << endl;
    cout << "B. " << optB << endl;
    cout << "C. " << optC << endl;
    cout << "D. " << optD << endl;
}

bool Question::checkAnswer(char userAns) {
    return toupper(userAns) == correctOption;
}

void Question::showCorrect() {
    cout << "Correct Answer: " << correctOption << endl;
}

// ============ FILL BLANK CLASS ==============
FillBlank::FillBlank(string q, string ans) {
    question = q;
    correctAns = ans;
}

void FillBlank::display() {
    cout << "\n" << question << endl;
    cout << "Enter your answer: ";
}

bool FillBlank::checkAnswer(string userAns) {
    transform(userAns.begin(), userAns.end(), userAns.begin(), ::tolower);
    string temp = correctAns;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return userAns == temp;
}

void FillBlank::showCorrect() {
    cout << "Correct Answer: " << correctAns << endl;
}

// ============ QUIZ ENGINE ==============
void Quiz::addMCQ(Question* q) {
    mcq[mcqCount++] = q;
}

void Quiz::addFB(FillBlank* f) {
    fb[fbCount++] = f;
}

int Quiz::startMCQ() {
    int score = 0;
    char ans;

    cout << "\n======= MCQ QUIZ STARTED =======\n";

    for (int i = 0; i < mcqCount; i++) {
        mcq[i]->display();
        cout << "Your Answer: ";
        cin >> ans;

        if (mcq[i]->checkAnswer(ans)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong!\n";
            mcq[i]->showCorrect();
        }
    }
    return score;
}

int Quiz::startFillBlank() {
    int score = 0;
    string ans;

    cout << "\n======= FILL IN THE BLANKS STARTED =======\n";

    for (int i = 0; i < fbCount; i++) {
        fb[i]->display();
        cin >> ans;

        if (fb[i]->checkAnswer(ans)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong!\n";
            fb[i]->showCorrect();
        }
    }
    return score;
}

void Quiz::showFinal(int mcqScore, int fbScore) {
    cout << "\n========== FINAL RESULT ==========\n";
    cout << "MCQ Score: " << mcqScore << " / " << mcqCount << endl;
    cout << "Fill Blanks Score: " << fbScore << " / " << fbCount << endl;
    cout << "Total Score: " << mcqScore + fbScore
         << " / " << mcqCount + fbCount << endl;
    cout << "===================================\n";
}
