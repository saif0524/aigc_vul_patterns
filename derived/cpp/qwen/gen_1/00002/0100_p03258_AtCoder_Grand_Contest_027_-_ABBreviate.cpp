#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a;
    int count = 0;
    for (char c : s) {
        if (c == 'a') {
            count++;
        } else {
            if (count > 0) {
                a.push_back(count);
                count = 0;
            }
        }
    }
    if (count > 0) {
        a.push_back(count);
    }
    reverse(a.begin(), a.end());
    count = 0;
    vector<int> b;
    for (char c : s) {
        if (c == 'b') {
            count++;
        } else {
            if (count > 0) {
                b.push_back(count);
                count = 0;
            }
        }
    }
    if (count > 0) {
        b.push_back(count);
    }
    long long result = 1;
    for (int x : a) {
        result = (result * (x + 1)) % MOD;
    }
    for (int x : b) {
        result = (result * (x + 1)) % MOD;
    }
    cout << result << endl;
    return 0;
}