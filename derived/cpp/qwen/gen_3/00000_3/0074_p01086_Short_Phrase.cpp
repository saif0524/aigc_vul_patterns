#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isShortPhrase(const vector<string>& words, int start) {
    int sections[] = {5, 7, 5, 7, 7};
    int currentLength = 0;
    int sectionIndex = 0;

    for (int i = start; i < words.size(); ++i) {
        currentLength += words[i].length();
        if (currentLength == sections[sectionIndex]) {
            ++sectionIndex;
            currentLength = 0;
            if (sectionIndex == 5) {
                return true;
            }
        } else if (currentLength > sections[sectionIndex]) {
            return false;
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }
        for (int i = 0; i < n; ++i) {
            if (isShortPhrase(words, i)) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}