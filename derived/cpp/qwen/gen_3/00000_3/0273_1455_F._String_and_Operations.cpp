#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j + 1 < n; ++j){
                if(s[j] > s[j + 1]){
                    swap(s[j], s[j + 1]);
                }
            }
        }
        for(auto &c : s){
            c = char('a' + (c - 'a' - 1 + k) % k);
        }
        for(int i = n - 1; i >= 0; --i){
            for(int j = n - 1; j > 0; --j){
                if(s[j - 1] > s[j]){
                    swap(s[j - 1], s[j]);
                }
            }
        }
        for(auto &c : s){
            c = char('a' + (c - 'a' + 1) % k);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j + 1 < n; ++j){
                if(s[j] > s[j + 1]){
                    swap(s[j], s[j + 1]);
                }
            }
        }
        cout << s << "\n";
    }
}