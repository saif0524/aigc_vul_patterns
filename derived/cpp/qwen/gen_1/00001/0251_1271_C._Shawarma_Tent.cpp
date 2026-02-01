#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long sx, sy;
    cin >> n >> sx >> sy;
    vector<long long> xl, yl;
    for(int i=0;i<n;i++){
        long long x, y;
        cin >> x >> y;
        if(x>sx){
            xl.push_back(x-sx);
        }
        if(x<sx){
            xl.push_back(sx-x);
        }
        if(y>sy){
            yl.push_back(y-sy);
        }
        if(y<sy){
            yl.push_back(sy-y);
        }
    }
    sort(xl.begin(),xl.end());
    sort(yl.begin(),yl.end());
    long long px,py;
    if(xl.empty()){
        px = sx;
    }else{
        px = sx + xl[xl.size()/2] * (xl.size()&1?1:-1);
    }
    if(yl.empty()){
        py = sy;
    }else{
        py = sy + yl[yl.size()/2] * (yl.size()&1?1:-1);
    }
    cout << (int)xl.size()-(int)count(xl.begin(), xl.end(), 0) +
            (int)yl.size()-(int)count(yl.begin(), yl.end(), 0) -
            (int)count_if(xl.begin(), xl.end(), [](long long x){return x==0;}) *
            (int)count_if(yl.begin(), yl.end(), [](long long x){return x==0;})
            - (int)count_if(xl.begin(), xl.end(), [](long long x){return x>0;}) *
               (int)count_if(yl.begin(), yl.end(), [](long long x){return x>0;})
            - (int)count_if(xl.begin(), xl.end(), [](long long x){return x<0;}) *
               (int)count_if(yl.begin(), yl.end(), [](long long x){return x<0;}) << "\n";
    cout << px << " " << py;
}