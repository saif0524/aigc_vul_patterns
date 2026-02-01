#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    int max_f = 0;
    for (int m = 1; m <= *max_element(a.begin(), a.end()); ++m) {
        int current_f = 0;
        for (int x : a) {
            current_f += m % x;
        }
        max_f = max(max_f, current_f);
    }
    cout << max_f;
}