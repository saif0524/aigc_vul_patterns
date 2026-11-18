#include <bits/stdc++.h>
using namespace std;

int main() {
    int a0;
    cin >> a0;
    int sum = 0;
    int ai;
    while (cin >> ai) {
        sum += ai;
    }
    cout << (a0 + sum) *5<< endl;
    return 0;
}