#include "quiz.h"
#include <fstream>

void Leaderboard::load() {
    ifstream in("leaderboard.txt");
    list.clear();

    if (!in) return;

    Entry e;
    while (in >> e.name >> e.score) {
        list.push_back(e);
    }
}

void Leaderboard::add(string name, int score) {
    for (auto &entry : list) {
        if (entry.name == name) {
            entry.score = max(entry.score, score);
            return;
        }
    }
    list.push_back({name, score});
}

void Leaderboard::sortLB() {
    sort(list.begin(), list.end(),
         [](Entry &a, Entry &b) { return a.score > b.score; });
}

void Leaderboard::save() {
    ofstream out("leaderboard.txt");
    for (auto &e : list)
        out << e.name << " " << e.score << endl;
}

void Leaderboard::show() {
    cout << "\n============ LEADERBOARD ============\n";
    cout << "Rank\tName\tScore\n";

    int rank = 1;
    for (auto &e : list)
        cout << rank++ << "\t" << e.name << "\t" << e.score << endl;

    cout << "=====================================\n";
}
