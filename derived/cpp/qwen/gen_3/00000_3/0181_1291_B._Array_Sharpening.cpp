#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        if(n == 1){
            cout << "Yes\n";
            continue;
        }
        bool inc = true, dec = true;
        for(int i=1;i<n;i++){
            if(a[i] <= a[i-1]) inc = false;
        }
        if(inc){
            cout << "Yes\n";
            continue;
        }
        for(int i=1;i<n;i++){
            if(a[i] <= a[i-1]) dec = false;
        }
        if(dec){
            cout << "Yes\n";
            continue;
        }
        bool possible = false;
        for(int i=0;i<n;i++){
            if((i+1 < n && a[i] > a[i+1]) && (i-1 >= 0 && a[i-1] < a[i])){
                possible = true;
                break;
            }
        }
        if(possible){
            cout << "Yes\n";
        }
        else{
            for(int i=0;i<n;i++){
                if(i+1 < n && a[i] < a[i+1]){
                    possible = true;
                    break;
                }
            }
            if(possible){
                for(int i=0;i<n;i++){
                    if(i-1 >= 0 && a[i] < a[i-1]){
                        possible = true;
                        break;
                    }
                }
            }
            if(possible){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}