#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> beams(N);
    for (int i = 0; i < N; i++) {
        cin >> beams[i].first >> beams[i].second;
    }
    sort(beams.begin(), beams.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    ll totalB = 0;
    for (auto &beam : beams) {
        totalB += beam.second;
    }
    ll totalA = 0;
    for (auto &beam : beams) {
        totalA += beam.first;
    }
    ll best_prob = 0;
    ll curA = 0;
    for (int i = 0; i < N; i++) {
        ll curB = 0;
        for (int j = 0; j < i; j++) {
            curA += beams[j].first;
            curB += beams[j].second;
        }
        ll prob = totalB - curB;
        if (curA <= curB) {
            for (int j = i; j < N; j++) {
                if (curA > curB) {
                    ll overlap = curA - curB;
                    ll diff = beams[j].second - beams[j].first;
                    if (diff > 0) {
                        prob = max(prob, (totalB - (curB + diff)) + min(overlap, diff));
                    }
                    break;
                }
                curA += beams[j].first;
                curB += beams[j].second;
            }
        }
        best_prob = max(best_prob, prob);
    }
    ll totalBTest = 0;
    for (auto &beam : beams) {
        totalBTest += beam.second;
    }
    ll g = gcd(best_prob, totalBTest);
    cout << best_prob / g << " " << totalBTest / g << endl;
    return 0;
}