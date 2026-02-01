#include <iostream>
#include <vector>
#include <string>
#include <numeric>

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
            int current_sum = 0;
            int section = 1;
            int word_index = start;
            bool possible = true;

            if (section == 1) {
                current_sum = 0;
                while (word_index < n) {
                    current_sum += words[word_index].length();
                    if (current_sum == 5) {
                        section++;
                        word_index++;
                        break;
                    } else if (current_sum > 5) {
                        possible = false;
                        break;
                    }
                    word_index++;
                }
                if (!possible) continue;
            }
            
            if (section == 2) {
                current_sum = 0;
                while (word_index < n) {
                    current_sum += words[word_index].length();
                    if (current_sum == 7) {
                        section++;
                        word_index++;
                        break;
                    } else if (current_sum > 7) {
                        possible = false;
                        break;
                    }
                    word_index++;
                }
                if (!possible) continue;
            }

            if (section == 3) {
                current_sum = 0;
                while (word_index < n) {
                    current_sum += words[word_index].length();
                    if (current_sum == 5) {
                        section++;
                        word_index++;
                        break;
                    } else if (current_sum > 5) {
                        possible = false;
                        break;
                    }
                    word_index++;
                }
                if (!possible) continue;
            }
            
            if (section == 4) {
                current_sum = 0;
                while (word_index < n) {
                    current_sum += words[word_index].length();
                    if (current_sum == 7) {
                        section++;
                        word_index++;
                        break;
                    } else if (current_sum > 7) {
                        possible = false;
                        break;
                    }
                    word_index++;
                }
                if (!possible) continue;
            }
            
            if (section == 5) {
                current_sum = 0;
                while (word_index < n) {
                    current_sum += words[word_index].length();
                    if (current_sum == 7) {
                        section++;
                        word_index++;
                        break;
                    } else if (current_sum > 7) {
                        possible = false;
                        break;
                    }
                    word_index++;
                }
                if (!possible) continue;
            }

            if (section == 6) {
                
                found = true;
                cout << start + 1 << endl;
                break;
            }
        }
    }

    return 0;
}