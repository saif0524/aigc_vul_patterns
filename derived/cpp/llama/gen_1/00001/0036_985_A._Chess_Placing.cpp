#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n / 2);
    int moves = 0;
    for(int i = 0; i < n / 2; i++) {
        cin >> p[i];
    }
    vector<int> white, black;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            white.push_back(i + 1);
        } else {
            black.push_back(i + 1);
        }
    }
    sort(p.begin(), p.end());
    int pos = 0;
    for(int i = 0; i < n / 2; i++) {
        auto it = lower_bound(white.begin(), white.end(), p[i]);
        if(it != white.end() && *it == p[i]) {
            pos++;
        }
    }
    int ans1 = 0;
    for(int i = 0; i < n / 2; i++) {
        auto it = lower_bound(white.begin(), white.end(), p[i]);
        if(it == white.end() || *it != p[i]) {
            ans1 += abs(p[i] - *lower_bound(white.begin(), white.end(), p[i]));
        }
    }
    pos = 0;
    for(int i = 0; i < n / 2; i++) {
        auto it = lower_bound(black.begin(), black.end(), p[i]);
        if(it != black.end() && *it == p[i]) {
            pos++;
        }
    }
    int ans2 = 0;
    for(int i = 0; i < n / 2; i++) {
        auto it = lower_bound(black.begin(), black.end(), p[i]);
        if(it == black.end() || *it != p[i]) {
            ans2 += abs(p[i] - *lower_bound(black.begin(), black.end(), p[i]));
        }
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}