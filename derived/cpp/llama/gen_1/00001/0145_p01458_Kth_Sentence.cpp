#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, k;
vector<string> words;

void dfs(string sentence, long long used) {
    if (sentence.size() == m) {
        --k;
        if (k == 0) {
            cout << sentence << endl;
            exit(0);
        }
        return;
    }

    for (const string& word : words) {
        dfs(sentence + word, used + word.size());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    words.resize(n);
    for (auto& word : words) {
        cin >> word;
    }
    sort(words.begin(), words.end());

    dfs("", 0);
    cout << "-" << endl;

    return 0;
}