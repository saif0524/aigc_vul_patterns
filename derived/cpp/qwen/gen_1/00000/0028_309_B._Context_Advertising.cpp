#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words(n);
    for(auto &w: words) cin >> w;
    int max_len = r * c;
    int best_start = 0, best_len = 0;
    int current_len = 0, start = 0;
    for(int i = 0; i < n; ++i){
        if(current_len + (i > start) + words[i].size() > max_len){
            if(i - start > best_len){
                best_len = i - start;
                best_start = start;
            }
            start = i;
            current_len = words[i].size();
        }
        else{
            current_len += (i > start) + words[i].size();
        }
    }
    if(n - start > best_len){
        best_len = n - start;
        best_start = start;
    }
    int pos = 0;
    int line_len = 0;
    for(int i = best_start; i < best_start + best_len; ++i){
        if(line_len + (pos > 0) + words[i].size() > c){
            cout << '\n';
            pos = 0;
            line_len = 0;
        }
        if(pos > 0) cout << ' ';
        cout << words[i];
        line_len += (pos > 0) + words[i].size();
        ++pos;
    }
    for(int i = pos; i < r * c; ++i) cout << ' ';
    return 0;
}