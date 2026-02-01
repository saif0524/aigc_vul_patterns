#include <bits/stdc++.h>
using namespace std;

string rebus;
int n, plusCount, minusCount;
vector<int> values;

void setValues(int PLUS, int MINUS) {
    int diff = 0;
    if (PLUS != 0 && MINUS != 0) {
        diff = PLUS - MINUS;
    } else if (PLUS != 0) {
        diff = PLUS;
    } else if (MINUS != 0) {
        diff = -MINUS;
    }

    int plusSum = 0;
    int minusSum = 0;
    for (int i = 0; i < plusCount; i++) {
        if (i == plusCount - 1) {
            plusSum += n - plusSum;
        } else {
            plusSum += 1;
        }
    }
    for (int i = 0; i < minusCount; i++) {
        if (i == minusCount - 1) {
            minusSum += n - minusSum;
        } else {
            minusSum += 1;
        }
    }

    if (diff >= 0) {
        int maxVal = plusSum + minusSum;
        if (maxVal < n) {
            plusSum += n - maxVal;
        }
    } else {
        int maxVal = plusSum + minusSum;
        if (maxVal < n) {
            minusSum += n - maxVal;
        }
    }

    int val = 1;
    for (int i = 0; i < plusCount - 1; i++) {
        values.push_back(val);
        val++;
    }
    if (plusCount > 0) {
        values.push_back(plusSum - (plusCount - 1));
    }
    for (int i = 0; i < minusCount - 1; i++) {
        values.push_back(val);
        val++;
    }
    if (minusCount > 0) {
        values.push_back(minusSum - (minusCount - 1));
    }
}

void check() {
    for (int i = 0; i < plusCount; i++) {
        int curVal = n;
        while (curVal > 0) {
            setValues(i + 1, plusCount - i - 1);
            int sum = 0;
            int cur = 0;
            for (int j = 0; j < values.size(); j++) {
                if (j % 2 == 0) {
                    sum += values[j];
                } else {
                    sum -= values[j];
                }
            }
            if (sum == n) {
                cout << "Possible" << endl;
                for (int j = 0; j < values.size(); j++) {
                    cout << values[j];
                    if (j < values.size() - 1) {
                        if (j % 2 == 0) {
                            cout << " + ";
                        } else {
                            cout << " - ";
                        }
                    }
                }
                cout << " = " << n << endl;
                return;
            }
            curVal--;
            values.clear();
        }
    }
}

int main() {
    cin >> rebus;
    int idx = rebus.find("=");
    string s = rebus.substr(idx + 1);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    n = stoi(s);
    idx = rebus.find("=");
    rebus.erase(idx, rebus.size() - idx);
    for (int i = 0; i < rebus.size(); i++) {
        if (rebus[i] == '?') continue;
        if (rebus[i] == '+') plusCount++;
        if (rebus[i] == '-') minusCount++;
    }
    plusCount++;
    if (minusCount == 0 && plusCount > n) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (plusCount == 0 && minusCount > n) {
        cout << "Impossible" << endl;
        return 0;
    }
    check();
    if (values.size() == 0) {
        cout << "Impossible" << endl;
    }
    return 0;
}