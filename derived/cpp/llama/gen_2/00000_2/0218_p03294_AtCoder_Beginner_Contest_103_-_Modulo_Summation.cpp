#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100005;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int maxVal = 0;
    for (int m = 0; m < MAX; m++) {
        int val = 0;
        for (int i = 0; i < N; i++) {
            val += m % a[i];
        }
        maxVal = max(val, maxVal);
    }
    cout << maxVal << endl;
    return 0;
}