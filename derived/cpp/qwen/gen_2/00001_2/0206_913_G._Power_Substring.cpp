#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        int len = a.size();
        for(int k=1; ; k++){
            string cur = to_string(1LL << k);
            if(cur.size() < len) continue;
            if(cur.size() > 100) cur = cur.substr(cur.size() - 100);
            if(cur.find(a) != string::npos){
                cout << k << "\n";
                break;
            }
        }
    }
}