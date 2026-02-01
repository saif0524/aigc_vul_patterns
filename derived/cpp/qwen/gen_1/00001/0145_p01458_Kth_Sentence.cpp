#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canFormLength(int m, const vector<string>& words, int maxLength) {
    vector<ll> dp(maxLength + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= maxLength; ++i) {
        for (const string& word : words) {
            if (i >= (int)word.length() && dp[i - (int)word.length()]) {
                dp[i] += dp[i - (int)word.length()];
            }
        }
    }
    return dp[m] > 0;
}

string kthSentence(int n, int m, ll K, const vector<string>& words) {
    vector<string> sortedWords = words;
    sort(sortedWords.begin(), sortedWords.end());

    string result;
    while (m > 0) {
        bool found = false;
        for (const string& word : sortedWords) {
            if (word.length() > m) continue;
            int remainingLength = m - (int)word.length();
            if (canFormLength(remainingLength, sortedWords, remainingLength)) {
                ll count = 0;
                vector<ll> dp(remainingLength + 1, 0);
                dp[0] = 1;
                for (int i = 1; i <= remainingLength; ++i) {
                    for (const string& w : sortedWords) {
                        if (i >= (int)w.length() && dp[i - (int)w.length()]) {
                            dp[i] += dp[i - (int)w.length()];
                        }
                    }
                }
                count = dp[remainingLength];
                if (K <= count) {
                    result += word;
                    m -= (int)word.length();
                    found = true;
                    break;
                } else {
                    K -= count;
                }
            }
        }
        if (!found) return "-";
    }
    return result;
}

int main(){
    int n, m;
    ll K;
    cin >> n >> m >> K;
    vector<string> words(n);
    for(int i=0;i<n;i++) cin >> words[i];
    string result = kthSentence(n, m, K, words);
    cout << result << endl;
}