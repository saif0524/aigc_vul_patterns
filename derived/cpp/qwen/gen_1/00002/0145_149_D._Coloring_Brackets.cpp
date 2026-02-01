#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 705;

vector<int> match(MAXN);
int dp[MAXN][2][2][2];

int solve(int pos, int open, int last_open, int last_close) {
    if (pos == -1) return 1;
    int &res = dp[pos][open][last_open][last_close];
    if (res != -1) return res;
    res = 0;
    if (s[pos] == '(') {
        res = (res + solve(pos - 1, open + 1, 0, last_close)) % MOD;
        if (open && last_open == 0 && last_close == 0)
            res = (res + solve(pos - 1, open - 1, 1, 0)) % MOD;
        if (!last_close && last_open == 0 && match[pos] < pos && !open)
            res = (res + solve(pos - 1, 0, 0, 1)) % MOD;
    } else {
        if (last_close == 0 && last_open == 0 && open - 1 >= 0)
            res = (res + solve(pos - 1, open - 1, 0, 0)) % MOD;
        if (last_close == 0 && last_open == 0 && match[pos] < pos)
            res = (res + solve(pos - 1, 0, 0, 1)) % MOD;
        if (open && last_open == 0 && last_close == 0)
            res = (res + solve(pos - 1, open - 1, 1, 0)) % MOD;
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') st.push(i);
        else{
            match[i] = st.top();
            match[st.top()] = i;
            st.pop();
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(n-1, 0, 0, 0) * 2 % MOD;
}