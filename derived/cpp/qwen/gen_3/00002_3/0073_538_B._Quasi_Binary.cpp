#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s = to_string(n);
    int k = *max_element(s.begin(), s.end()) - '0';
    cout << k << "\n";
    for(int i=0; i<k; i++){
        for(auto c: s){
            cout << ((c-'0' > i)? '1':'0');
        }
        cout << " ";
    }
}