#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    vector<pair<long long, long long>> stones(k);
    for(auto &s : stones) cin >> s.first >> s.second;
    vector<pair<long long, long long>> monsters(n);
    for(auto &m : monsters) cin >> m.first >> m.second;
    
    int count = 0;
    for(auto &m : monsters){
        for(auto &s : stones){
            bool seen = true;
            for(auto &other : monsters){
                if( other != m ){
                    long long a1 = s.second - m.second;
                    long long b1 = m.first - s.first;
                    long long c1 = a1 * m.first + b1 * m.second;
                    
                    long long a2 = other.second - m.second;
                    long long b2 = m.first - other.first;
                    long long c2 = a2 * m.first + b2 * m.second;
                    
                    if( a1 * other.first + b1 * other.second < c1)
                        if( a2 * s.first + b2 * s.second < c2 ){
                            seen = false;
                            break;
                        }
                }
            }
            if(seen){
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}