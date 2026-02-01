#include <bits/stdc++.h>
using namespace std;

bool isEquivalent(string& a, string& b, int l1, int r1, int l2, int r2) {
    if (r1 - l1 + 1 == 1) return a[l1] == b[l2];
    int mid1 = (l1 + r1) / 2;
    int mid2 = (l2 + r2) / 2;
    return (isEquivalent(a, b, l1, mid1, l2, mid2) && isEquivalent(a, b, mid1 + 1, r1, mid2 + 1, r2)) ||
           (isEquivalent(a, b, l1, mid1, mid2 + 1, r2) && isEquivalent(a, b, mid1 + 1, r1, l2, mid2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(isEquivalent(a, b, 0, a.size() - 1, 0, b.size() - 1)) cout << "YES";
    else cout << "NO";
}