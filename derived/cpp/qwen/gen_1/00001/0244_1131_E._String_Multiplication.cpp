#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> p(n);
    for(auto &s: p) cin >> s;
    pair<char,long long> best = {' ',0};
    pair<char,long long> last = {' ',0};
    for(auto &s: p){
        if(s.size()==1){
            if(last.first == s[0]){
                last.second++;
            }else{
                best = max(best, last);
                last = {s[0], 1};
            }
        }else{
            best = max(best, last);
            best = max(best, pair<char, long long>{s[0], 1});
            best = max(best, pair<char, long long>{s.back(), 1});
            if(last.first == s[0]){
                last.second += 1;
            }else{
                last = {s[0], 1};
            }
            if(s.back() == s.front()){
                last.second += s.size()-1;
            }else{
                best = max(best, pair<char, long long>{s.back(), (long long)s.size()-1});
            }
        }
    }
    best = max(best, last);
    cout << best.second;
}