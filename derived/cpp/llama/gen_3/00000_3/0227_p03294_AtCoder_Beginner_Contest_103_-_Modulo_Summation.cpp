#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long maxVal = 0;
    for (long long m = 0; m < *max_element(a, a + N); m++) {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m % a[i];
        }
        maxVal = max(maxVal, sum);
    }

    cout << maxVal << endl;

    return 0;
}