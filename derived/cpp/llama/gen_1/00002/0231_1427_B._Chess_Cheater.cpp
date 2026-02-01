#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculateScore(string& s, int k) {
    int n = s.length();
    int score = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if (i == 0 || s[i - 1] == 'L') {
                score++;
            } else {
                score += 2;
            }
        }
    }

    if (score == 0) {
        return max(0, min(k * 2 - 1, n));
    }

    vector<int> wins;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            curr++;
        } else {
            if (curr > 0) {
                wins.push_back(curr);
                curr = 0;
            }
        }
    }
    if (curr > 0) {
        wins.push_back(curr);
        curr = 0;
    }

    int change = k;
    for (int i = 0; i < wins.size(); i++) {
        if (wins[i] == 1 && change > 0) {
            score += 2 * min(change, (i > 0 ? i : 0) + (i < wins.size() - 1 ? wins.size() - i - 1 : 0));
            change -= min(change, (i > 0 ? i : 0) + (i < wins.size() - 1 ? wins.size() - i - 1 : 0));
            wins[i] = 0;
        }
    }

    int start = 0, end = wins.size() - 1;
    while (change > 0 && start <= end) {
        if (start == end) {
            score += 2 * min(change, wins[start] + 1);
            break;
        } else {
            if (start > 0 && end < wins.size() - 1) {
                if (start - 0 < wins.size() - 1 - end) {
                    score += 2 * min(change, start);
                    start = -1;
                } else {
                    score += 2 * min(change, wins.size() - 1 - end);
                    end = wins.size();
                }
            } else if (start > 0) {
                score += 2 * min(change, start);
                start = -1;
            } else if (end < wins.size() - 1) {
                score += 2 * min(change, wins.size() - 1 - end);
                end = wins.size();
            } else {
                break;
            }
            change -= min(change, (start > 0 ? start : 0) + (end < wins.size() - 1 ? wins.size() - 1 - end : 0));
        }
    }

    return score;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << calculateScore(s, k) << endl;
    }
    return 0;
}