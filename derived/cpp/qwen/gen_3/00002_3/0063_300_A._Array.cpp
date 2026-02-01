#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int z = 0, p = 0, np = 0;
    vector<int> zero, pos, neg;
    for(auto x: a){
        if(x == 0) z++, zero.push_back(x);
        else if(x > 0) p++, pos.push_back(x);
        else np++, neg.push_back(x);
    }
    if(z == 0){
        z = 1;
        if(p >= 2 && np >= 1){
            zero.push_back(pos.back());
            pos.pop_back();
        }
        else if(p >= 3){
            zero.push_back(pos.back());
            pos.pop_back();
        }
        else{
            zero.push_back(neg.back());
            neg.pop_back();
        }
    }
    if(pos.empty()){
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }
    if(neg.empty()){
        neg.push_back(pos.back());
        pos.pop_back();
        neg.push_back(pos.back());
        pos.pop_back();
    }
    if(p == 0 && np >= 3){
        pos.push_back(neg.back());
        neg.pop_back();
    }
    if(p == 1 && np >= 2){
        pos.push_back(neg.back());
        neg.pop_back();
    }
    cout << 1 << " " << neg.back() << "\n";
    neg.pop_back();
    cout << neg.size() + pos.size() << " ";
    for(auto x: neg) cout << x << " ";
    for(auto x: pos) cout << x << " ";
    cout << "\n";
    cout << z << " ";
    for(auto x: zero) cout << x << " ";
    cout << "\n";
}