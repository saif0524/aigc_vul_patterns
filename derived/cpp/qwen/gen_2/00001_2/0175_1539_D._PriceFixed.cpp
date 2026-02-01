#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> products(n);
    for(auto &p : products){
        cin >> p.first >> p.second;
    }
    sort(products.begin(), products.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.first * 2 + max(0LL, (a.first - a.second) / (a.second + 1)) < b.first * 2 + max(0LL, (b.first - b.second) / (b.second + 1));
    });
    long long totalCost = 0, discount = 0;
    for(const auto &p : products){
        long long toBuy = p.first;
        if(discount >= p.first){
            totalCost += p.first;
            discount -= p.first;
        } else {
            totalCost += discount * 1 + (p.first - discount) * 2;
            discount = 0;
            long long afterBuy = toBuy;
            discount += afterBuy / (p.second + 1);
        }
    }
    cout << totalCost;
}