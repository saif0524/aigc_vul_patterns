#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x;
    cin >> x;
    stack<char> s;
    for(char c : x){
        if(c == 'T' && !s.empty() && s.top() == 'S'){
            s.pop();
        }
        else{
            s.push(c);
        }
    }
    cout << s.size();
}