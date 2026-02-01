#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<pair<long long, long long>> products(n);
    for(auto &p: products){
        cin >> p.first >> p.second;
    }
    sort(products.begin(), products.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.second < b.second;
    });
    long long total = 0;
    long long bought = 0;
    for(auto &p: products){
        long long need = p.first;
        long long bulk = p.second;
        long long full_bulks = bought / bulk;
        long long can_get_discount = full_bulks * bulk;
        long long pay_full_price = min(need, can_get_discount);
        total += pay_full_price * 2;
        need -= pay_full_price;
        bought += pay_full_price;
        long long pay_discount = need;
        total += pay_discount;
        bought += pay_discount;
    }
    cout << total;
}