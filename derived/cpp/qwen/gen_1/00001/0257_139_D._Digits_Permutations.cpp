#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    string a = n;
    string b = n;
    sort(a.begin(), a.end(), greater<char>());
    sort(b.begin(), b.end());
    cout << a << "\n" << b;
}