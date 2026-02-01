#include <bits/stdc++.h>
using namespace std;

set<string> uniqueTails;

string processNumber(long long num) {
    string s = to_string(num);
    sort(s.begin(), s.end(), greater<char>());
    size_t idx = s.find_first_not_of('0');
    return (idx == string::npos) ? "" : s.substr(idx);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long L, R;
    cin >> L >> R;
    for(long long i = L; i <= R; ++i){
        uniqueTails.insert(processNumber(i));
    }
    cout << uniqueTails.size();
    return 0;
}