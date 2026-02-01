#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> titles(n);
    for(auto &s: titles) cin >> s;
    
    string res;
    for(int len=1;len<=20;len++){
        for(int i=0;i<(1<<len);i++){
            string candidate;
            for(int j=0;j<len;j++){
                if(i&(1<<j)) candidate += 'a'+j;
            }
            if(candidate.empty()) continue;
            bool found = false;
            for(auto &title: titles){
                if(title.find(candidate) != string::npos){
                    found = true;
                    break;
                }
            }
            if(!found){
                if(res.empty() || candidate < res){
                    res = candidate;
                }
            }
        }
        if(!res.empty()) break;
    }
    cout << res;
}