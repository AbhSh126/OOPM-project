#include "quiz.h"

int main() {

    User u;

    cout << "\n==== LOGIN SYSTEM ====\n";
    cout << "1. Login\n";
    cout << "2. Signup\n";
    cout << "Enter choice: ";

    int c;
    cin >> c;

    if (c == 1) {
        if (!u.login()) {
            cout << "\nLogin failed. Exiting...\n";
            return 0;
        }
    } 
    else {
        u.signUp();

        cout << "\nSignup Successful! Please login now.\n";
        if (!u.login()) {
            cout << "\nLogin failed. Exiting...\n";
            return 0;
        }
    }

    cout << "\n==== USER PROFILE ====\n";
    u.showDetails();
    u.showHistory();


    Quiz quiz;
    Leaderboard lb;

    // ===========================
    // ADD 20 MCQs
    // ===========================
    quiz.addMCQ(new Question("1. OOP stands for?", "Object Over Program", "Object Oriented Programming", "Open Object Process", "None", 'B'));
    quiz.addMCQ(new Question("2. Which feature binds data & functions?", "Polymorphism", "Abstraction", "Encapsulation", "Inheritance", 'C'));
    quiz.addMCQ(new Question("3. Which keyword creates objects?", "create", "class", "new", "object", 'C'));
    quiz.addMCQ(new Question("4. Same function name diff args?", "Overloading", "Overriding", "Encapsulation", "Abstraction", 'A'));
    quiz.addMCQ(new Question("5. Not a pillar of OOP?", "Encapsulation", "Abstraction", "Polymorphism", "Compilation", 'D'));

    quiz.addMCQ(new Question("6. Blueprint of object?", "Class", "Object", "Constructor", "Method", 'A'));
    quiz.addMCQ(new Question("7. To access class members?", ".", "::", "->", ";", 'C'));
    quiz.addMCQ(new Question("8. Runtime polymorphism?", "Overloading", "Overriding", "Constructor", "Template", 'B'));
    quiz.addMCQ(new Question("9. C++ supports?", "Procedure", "OOP", "Both", "None", 'C'));
    quiz.addMCQ(new Question("10. Base class also known as?", "Derived", "Child", "Parent", "None", 'C'));

    quiz.addMCQ(new Question("11. Hides complexity?", "Abstraction", "Encapsulation", "Polymorphism", "All", 'A'));
    quiz.addMCQ(new Question("12. Constructors have?", "Class name", "Return type", "Both", "None", 'A'));
    quiz.addMCQ(new Question("13. Private members accessed by?", "public", "private", "friend function", "object", 'C'));
    quiz.addMCQ(new Question("14. Deallocates memory?", "Constructor", "Destructor", "new", "delete", 'B'));
    quiz.addMCQ(new Question("15. Not a type of inheritance?", "Single", "Double", "Hybrid", "Multilevel", 'B'));

    quiz.addMCQ(new Question("16. Static members accessed using?", "object", "class name", "pointer", "friend", 'B'));
    quiz.addMCQ(new Question("17. this pointer refers to?", "base class", "current object", "derived", "parent", 'B'));
    quiz.addMCQ(new Question("18. Linking function call to code?", "Polymorphism", "Encapsulation", "Abstraction", "Binding", 'D'));
    quiz.addMCQ(new Question("19. Access specifiers?", "private", "public", "protected", "all", 'D'));
    quiz.addMCQ(new Question("20. Called when object destroyed?", "Constructor", "Destructor", "delete", "None", 'B'));

    // ===========================
    // ADD 10 FILL BLANKS
    // ===========================
    quiz.addFB(new FillBlank("1. C++ is a ________ oriented language.", "object"));
    quiz.addFB(new FillBlank("2. ________ binds data & functions.", "encapsulation"));
    quiz.addFB(new FillBlank("3. Constructor has same name as ________.", "class"));
    quiz.addFB(new FillBlank("4. Opposite of constructor is ________.", "destructor"));
    quiz.addFB(new FillBlank("5. Objects contain data & ________.", "functions"));
    quiz.addFB(new FillBlank("6. Inheritance promotes code ________.", "reusability"));
    quiz.addFB(new FillBlank("7. Private data accessed using ________.", "getter"));
    quiz.addFB(new FillBlank("8. ________ allows multiple forms.", "polymorphism"));
    quiz.addFB(new FillBlank("9. new operator allocates ________.", "memory"));
    quiz.addFB(new FillBlank("10. friend keyword breaks ________.", "encapsulation"));

    // ===========================
    // QUIZ ORDER
    // ===========================
    int choice;
    cout << "\nChoose Quiz Order:\n";
    cout << "1. MCQ first, then Fill in the blanks\n";
    cout << "2. Fill in the blanks first, then MCQ\n";
    cout << "Enter Choice: ";
    cin >> choice;

    int scoreMCQ = 0, scoreFB = 0;

    if (choice == 1) {
        scoreMCQ = quiz.startMCQ();
        scoreFB = quiz.startFillBlank();
    } else {
        scoreFB = quiz.startFillBlank();
        scoreMCQ = quiz.startMCQ();
    }

    quiz.showFinal(scoreMCQ, scoreFB);

    // Save attempt in user profile
    int totalScore = scoreMCQ + scoreFB;
    u.saveHistory(totalScore);


    // ===========================
    // LEADERBOARD
    // ===========================
    lb.load();
    lb.add(u.getName(), totalScore);
    lb.sortLB();
    lb.save();
    lb.show();

    return 0;
}
