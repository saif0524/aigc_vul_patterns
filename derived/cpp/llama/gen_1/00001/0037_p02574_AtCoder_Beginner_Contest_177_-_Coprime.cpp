#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the GCD of multiple numbers
int gcdMultiple(vector<int> &A) {
    int result = A[0];
    for (int i = 1; i < A.size(); i++)
        result = gcd(result, A[i]);
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    bool pairwiseCoprime = true;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (gcd(A[i], A[j]) != 1) {
                pairwiseCoprime = false;
                break;
            }
        }
        if (!pairwiseCoprime)
            break;
    }

    if (pairwiseCoprime) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int gcdAll = gcdMultiple(A);
    if (gcdAll == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

    return 0;
}