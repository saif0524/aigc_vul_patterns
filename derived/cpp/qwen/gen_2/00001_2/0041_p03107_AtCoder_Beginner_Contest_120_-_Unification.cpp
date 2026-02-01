#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    for(char c: s){
        if(!st.empty() && st.top() != c){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    cout << n - st.size();
}