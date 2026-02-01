#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> words(n);
    for(auto &w: words) cin >> w;
    string message;
    cin >> message;
    string pattern = "<3";
    int i = 0, j = 0;
    while(j < message.size()){
        bool matched = false;
        if(message.substr(j, 2) == pattern){
            j += 2;
            if(i < n){
                int k = j;
                while(k < message.size() && isalpha(message[k])){
                    k++;
                }
                if(message.substr(j, k - j) == words[i]){
                    j = k;
                    i++;
                    matched = true;
                }
            }
        }
        if(!matched){
            j++;
        }
    }
    if(i == n && message.substr(j) == pattern){
        cout << "yes";
    } else {
        cout << "no";
    }
}