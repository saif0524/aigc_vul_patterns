#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    bool pairwise = true;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (gcd(A[i], A[j]) != 1) {
                pairwise = false;
                break;
            }

    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int gcd_all = A[0];
    for (int i = 1; i < N; i++)
        gcd_all = gcd(gcd_all, A[i]);

    if (gcd_all == 1)
        cout << "setwise coprime" << endl;
    else
        cout << "not coprime" << endl;

    return 0;
}