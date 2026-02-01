#include <bits/stdc++.h>
using namespace std;

int main(){
    string pass;
    cin >> pass;
    int n;
    cin >> n;
    set<string> words;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        words.insert(s);
    }
    for(auto w1 : words){
        for(auto w2 : words){
            if(w1[1] == pass[0] && w2[0] == pass[1]){
                cout << "YES";
                return 0;
            }
        }
    }
    if(words.find(pass) != words.end()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}