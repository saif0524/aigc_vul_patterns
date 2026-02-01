#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

long long dfs(int i, long long num, const string& S, const string& T) {
    if (i == T.size()) {
        return num <= stol(S) ? num : 0;
    }

    if (T[i] != '?') {
        return dfs(i + 1, num * 10 + (T[i] - '0'), S, T);
    }

    long long res = 0;
    for (int j = 0; j <= 9; ++j) {
        res += dfs(i + 1, num * 10 + j, S, T);
        res %= mod;
    }

    return res;
}

int main() {
    string S, T;
    cin >> S >> T;

    cout << dfs(0, 0, S, T) << endl;

    return 0;
}