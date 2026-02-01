#include <bits/stdc++.h>
using namespace std;

bool isAnagram(const string& s1, const string& s2) {
    string str1 = s1;
    string str2 = s2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (isAnagram(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}