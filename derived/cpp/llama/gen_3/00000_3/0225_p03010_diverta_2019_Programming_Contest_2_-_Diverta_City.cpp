#include <bits/stdc++.h>

using namespace std;

void printGraph(long long n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "0 ";
            else {
                cout << (1LL << (i - 1)) * (1LL << (j - 1)) * 111LL << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    printGraph(n);
    return 0;
}