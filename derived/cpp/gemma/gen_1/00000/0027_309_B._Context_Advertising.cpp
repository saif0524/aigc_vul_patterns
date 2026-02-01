#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    int max_words = 0;
    int start_index = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int current_words = j - i + 1;
            int current_lines = 0;
            int current_chars = 0;
            bool possible = true;

            for (int k = i; k <= j; ++k) {
                if (current_chars + words[k].length() + (current_chars > 0 ? 1 : 0) <= c) {
                    if (current_chars > 0) {
                        current_chars++;
                    }
                    current_chars += words[k].length();
                } else {
                    current_lines++;
                    current_chars = words[k].length();
                }
            }
            current_lines++;

            if (current_lines <= r) {
                if (current_words > max_words) {
                    max_words = current_words;
                    start_index = i;
                }
            }
        }
    }

    if (start_index == -1) {
        return 0;
    }

    int current_chars = 0;
    int current_lines = 0;
    for (int k = start_index; k < start_index + max_words; ++k) {
        if (current_chars + words[k].length() + (current_chars > 0 ? 1 : 0) <= c) {
            if (current_chars > 0) {
                cout << " ";
                current_chars++;
            }
            cout << words[k];
            current_chars += words[k].length();
        } else {
            cout << endl;
            current_lines++;
            current_chars = words[k].length();
            cout << words[k];
            current_chars += words[k].length();
        }
    }
    cout << endl;
    
    return 0;
}