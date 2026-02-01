#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> words(n, string(l, ' '));
    int index = 0;
    for(int i=0; i<l; ++i){
        for(int j=0; j<n; ++j){
            words[(j+(k-1))%n][i] = s[index++];
        }
    }
    for(auto &word: words){
        cout << word << "\n";
    }
}