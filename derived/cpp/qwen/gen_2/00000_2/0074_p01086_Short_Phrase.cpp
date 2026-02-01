#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isTanku(const vector<string>& words, int start) {
    if (words.size() - start < 9) return false;
    int section_lengths[] = {5, 7, 5, 7, 7};
    int idx = start;
    for (int len : section_lengths) {
        int current_len = 0;
        while (current_len < len) {
            if (idx >= words.size()) return false;
            current_len += words[idx++].length();
        }
    }
    return idx == start + 9;
}

int findTanku(const vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
        if (isTanku(words, i)) {
            return i + 1;
        }
    }
    return -1; // This line should never be reached as per problem statement
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (string& word : words) {
            cin >> word;
        }
        cout << findTanku(words) << endl;
    }
    return 0;
}