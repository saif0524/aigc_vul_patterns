#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words(n);
    for(auto &w: words) cin >> w;
    int max_len = 0;
    int best_start = 0;
    int best_end = 0;
    for(int start = 0; start < n; ++start){
        int end = start;
        int chars = 0;
        int lines = 1;
        while(end < n && lines <= r && chars + (end > start) + words[end].size() <= c){
            chars += (end > start) + words[end].size();
            if(chars + (end > start) + words[end].size() > c) ++lines;
            if(chars + (end > start) + words[end].size() > c) chars = words[end].size();
            end++;
        }
        if(end - start > max_len){
            max_len = end - start;
            best_start = start;
            best_end = end - 1;
        }
    }
    int current_chars = 0;
    int current_line = 1;
    for(int i = best_start; i <= best_end; ++i){
        if(current_chars + (i > best_start) + words[i].size() > c || current_line > r){
            cout << "\n";
            current_chars = 0;
            current_line++;
        }
        if(i > best_start) cout << " ";
        cout << words[i];
        current_chars += (i > best_start) + words[i].size();
    }
}