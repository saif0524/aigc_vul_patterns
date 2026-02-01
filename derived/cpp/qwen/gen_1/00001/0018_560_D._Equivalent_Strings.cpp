#include <bits/stdc++.h>
using namespace std;

bool equivalent(const string &a, const string &b) {
    if (a == b) return true;
    int n = a.size();
    if (n % 2 != 0) return false;
    string a1 = a.substr(0, n / 2);
    string a2 = a.substr(n / 2);
    string b1 = b.substr(0, n / 2);
    string b2 = b.substr(n / 2);
    return (equivalent(a1, b1) && equivalent(a2, b2)) || (equivalent(a1, b2) && equivalent(a2, b1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(equivalent(a, b)) cout << "YES";
    else cout << "NO";
}