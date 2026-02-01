#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        bool found = false;
        for (int start = 0; start < n; ++start) {
            int section_lengths[] = {5, 7, 5, 7, 7};
            int current_length = 0;
            int section_index = 0;
            int word_index = start;

            while (word_index < n && section_index < 5) {
                current_length += words[word_index].length();
                if (current_length == section_lengths[section_index]) {
                    current_length = 0;
                    section_index++;
                } else if (current_length > section_lengths[section_index]) {
                    break;
                }
                word_index++;
            }

            if (section_index == 5) {
                cout << start + 1 << endl;
                found = true;
                break;
            }
        }
    }

    return 0;
}