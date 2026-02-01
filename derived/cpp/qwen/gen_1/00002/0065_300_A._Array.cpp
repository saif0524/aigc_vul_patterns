#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    vector<int> neg, pos, zero;
    
    for(auto x : a){
        if(x < 0) neg.push_back(x);
        else if(x > 0) pos.push_back(x);
        else zero.push_back(x);
    }
    
    if(neg.empty()){
        neg.push_back(pos.back());
        pos.pop_back();
        neg.push_back(pos.back());
        pos.pop_back();
    }
    if(pos.empty()){
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }
    
    cout << 1 << " " << neg.back() << endl;
    neg.pop_back();
    cout << neg.size() + pos.size() << " ";
    for(auto x : neg) cout << x << " ";
    for(auto x : pos) cout << x << endl;
    cout << 1 + zero.size() << " 0";
    for(auto x : zero) cout << " " << x;
    cout << endl;
    
    return 0;
}