#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool checkOrder(const vector<string>& words, const unordered_map<char, int>& order) {
    for (int i = 0; i < words.size() - 1; i++) {
        const string& word1 = words[i];
        const string& word2 = words[i + 1];

        bool isPrefix = true;
        for (int j = 0; j < word1.size(); j++) {
            if (j >= word2.size()) {
                isPrefix = false;
                break;
            }

            if (order.at(word1[j]) > order.at(word2[j])) {
                isPrefix = false;
                break;
            } else if (order.at(word1[j]) < order.at(word2[j])) {
                break;
            }
        }

        if (isPrefix && word1.size() > word2.size()) {
            return false;
        }
    }

    return true;
}

bool findOrder(const vector<string>& words) {
    unordered_map<char, int> order;
    for (char c = 'a'; c <= 'z'; c++) {
        order[c] = -1;
    }

    for (int i = 0; i < words.size() - 1; i++) {
        const string& word1 = words[i];
        const string& word2 = words[i + 1];

        bool isPrefix = true;
        int j;
        for (j = 0; j < word1.size(); j++) {
            if (j >= word2.size()) {
                isPrefix = false;
                break;
            }

            if (order[word1[j]] == -1 && order[word2[j]] == -1) {
                continue;
            } else if (order[word1[j]] == -1) {
                order[word1[j]] = order[word2[j]] + 1;
            } else if (order[word2[j]] == -1) {
                order[word2[j]] = order[word1[j]] - 1;
            } else if (order[word1[j]] > order[word2[j]]) {
                isPrefix = false;
                break;
            } else if (order[word1[j]] < order[word2[j]]) {
                break;
            }
        }

        if (isPrefix && word1.size() > word2.size()) {
            return false;
        }

        if (!isPrefix) {
            if (order[word1[j]] == -1) {
                order[word1[j]] = 26;
            }
            if (order[word2[j]] == -1) {
                order[word2[j]] = 25;
            }

            for (char c = 'a'; c <= 'z'; c++) {
                if (order[c] == -1) {
                    order[c] = 25;
                }
            }

            if (!checkOrder(words, order)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        if (findOrder(words)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}