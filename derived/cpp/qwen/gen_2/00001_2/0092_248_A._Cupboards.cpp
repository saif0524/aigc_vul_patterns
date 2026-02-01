#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        cin >> left[i] >> right[i];
    }
    int openL = count(left.begin(), left.end(), 1);
    int openR = count(right.begin(), right.end(), 1);
    cout << min(openL, n - openL) + min(openR, n - openR) << endl;
    return 0;
}