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
    const string heart = "<3";
    int pos = 0;
    for(int i=0; i<n; i++){
        bool found = false;
        while(pos < message.size()){
            if(message.substr(pos, heart.size()) == heart){
                pos += heart.size();
            }
            else{
                found = true;
                break;
            }
            if(message.substr(pos, words[i].size()) == words[i]){
                pos += words[i].size();
                break;
            }
        }
        if(!found){
            cout << "no";
            return 0;
        }
    }
    while(pos < message.size()){
        if(message.substr(pos, heart.size()) == heart){
            pos += heart.size();
        }
        else{
            char c = message[pos++];
            if(!islower(c) && c !='<' && c != '>'){
                cout << "no";
                return 0;
            }
        }
    }
    cout << (pos == message.size() ? "yes" : "no");
}