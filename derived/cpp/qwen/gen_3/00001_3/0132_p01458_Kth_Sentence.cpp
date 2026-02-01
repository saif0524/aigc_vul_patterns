#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    sort(words.begin(), words.end());

    vector<string> sentences;
    
    function<void(string)> generate_sentences = [&](string current_sentence) {
        if (current_sentence.length() == m) {
            sentences.push_back(current_sentence);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (current_sentence.length() + words[i].length() <= m) {
                generate_sentences(current_sentence + words[i]);
            }
        }
    };

    generate_sentences("");

    sort(sentences.begin(), sentences.end());

    if (k > sentences.size()) {
        cout << "-" << endl;
    } else {
        cout << sentences[k - 1] << endl;
    }

    return 0;
}