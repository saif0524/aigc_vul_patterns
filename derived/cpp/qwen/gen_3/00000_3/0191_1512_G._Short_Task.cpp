#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 5;
vector<int> d(MAX, -1);

void precompute() {
    for (int i = 1; i < MAX; ++i) {
        for (int j = i; j < MAX; j += i) {
            if (d[j] == -1 || i + j < d[j]) {
                d[j] = i + j;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        cout << d[c] - c << '\n';
    }
}