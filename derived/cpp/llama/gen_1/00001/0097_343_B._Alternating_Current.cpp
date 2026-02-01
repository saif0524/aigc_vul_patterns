#include <iostream>
#include <string>

using namespace std;

bool isPossibleToUntangle(const string& sequence) {
    int balance = 0;
    for (char c : sequence) {
        if (c == '+') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string sequence;
    cin >> sequence;
    if (isPossibleToUntangle(sequence)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}