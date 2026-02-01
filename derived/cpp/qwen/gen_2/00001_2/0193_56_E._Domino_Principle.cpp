#include <bits/stdc++.h>
using namespace std;

struct Domino {
    long long x, h;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<Domino> dominoes(n);
    for(int i = 0; i < n; ++i) {
        cin >> dominoes[i].x >> dominoes[i].h;
        dominoes[i].idx = i;
    }
    
    sort(dominoes.begin(), dominoes.end(), [](const Domino& a, const Domino& b) {
        return a.x < b.x;
    });
    
    vector<int> result(n, 1);
    map<long long, int> reach;
    for(int i = 0; i < n; ++i) {
        auto it = reach.lower_bound(dominoes[i].x);
        if(it != reach.begin() && (--it)->second >= dominoes[i].x) {
            result[it->second - dominoes[i].x]++;
            result[dominoes[i].idx] += result[it->second - dominoes[i].x - 1];
            reach.erase(++it);
        }
        reach[dominoes[i].x + dominoes[i].h - 1] = dominoes[i].idx;
    }
    
    for(int i = 0; i < n; ++i) {
        cout << result[i] << (i < n - 1 ? ' ' : '\n');
    }
}