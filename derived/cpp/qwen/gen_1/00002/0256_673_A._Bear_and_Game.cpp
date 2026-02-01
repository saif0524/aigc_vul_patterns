#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int &x : t) cin >> x;
    
    int last_boring = 0, watch_time = 0;
    for(int i = 1; i <= 90; ++i){
        bool is_interesting = binary_search(t.begin(), t.end(), i);
        if(is_interesting){
            last_boring = i;
            watch_time = i;
        }
        else{
            if(i - last_boring >= 15){
                watch_time = i-1;
                break;
            }
        }
    }
    
    cout << watch_time;
}