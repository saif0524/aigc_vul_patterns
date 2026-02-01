#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &str: s) cin >> str;
    sort(s.begin(), s.end());
    do{
        string combined;
        for(auto &str: s) combined += str;
        bool valid = true;
        for(auto &str: s){
            int count = 0;
            size_t pos = combined.find(str);
            while(pos != string::npos){
                count++;
                pos = combined.find(str, pos + 1);
            }
            for(auto &other: s){
                if(other == str) continue;
                int otherCount = 0;
                size_t otherPos = combined.find(other);
                while(otherPos != string::npos){
                    otherCount++;
                    otherPos = combined.find(other, otherPos + 1);
                }
                if(otherCount > count){
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }
        if(valid){
            cout << combined;
            return 0;
        }
    }while(next_permutation(s.begin(), s.end()));
    cout << "NO";
}