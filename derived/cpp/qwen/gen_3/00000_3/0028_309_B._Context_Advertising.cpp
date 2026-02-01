#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words(n);
    for(auto &word : words) cin >> word;
    int max_words = 0, start = 0;
    int current_words = 0, current_length = 0;
    for(int i = 0; i < n; ++i){
        if(current_length + words[i].size() + (current_words > 0) > c){
            if(current_words > max_words){
                max_words = current_words;
                start = i - current_words;
            }
            while(current_length + words[i].size() + (current_words > 0) > c){
                current_length -= words[start].size() + (current_words > 1);
                start++;
                current_words--;
            }
        }
        current_length += words[i].size() + (current_words > 0);
        current_words++;
    }
    if(current_words > max_words){
        max_words = current_words;
        start = n - current_words;
    }
    int printed_lines = 0, line_length = 0;
    for(int i = start; i < start + max_words; ++i){
        if(line_length + words[i].size() + (line_length > 0) > c || printed_lines == r){
            cout << "\n";
            printed_lines++;
            line_length = 0;
        }
        if(line_length > 0) cout << " ";
        cout << words[i];
        line_length += words[i].size() + (line_length > 0);
    }
    for(; printed_lines < r; ++printed_lines){
        cout << "\n";
    }
}