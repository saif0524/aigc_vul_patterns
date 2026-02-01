#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidShortPhrase(const vector<int>& wordLengths, int start) {
    if (start + 9 > wordLengths.size()) return false;
    int sections[5] = {5, 7, 5, 7, 7};
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        while (sum < sections[i] && index < 9) {
            sum += wordLengths[start + index];
            ++index;
        }
        if (sum != sections[i]) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        vector<int> wordLengths(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
            wordLengths[i] = words[i].length();
        }
        for (int i = 0; i < n; ++i) {
            if (isValidShortPhrase(wordLengths, i)) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}