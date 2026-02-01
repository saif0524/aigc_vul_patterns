#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;
    vector<int> left(N+1, -1), right(N+1, -1);
    vector<int> ans;
    stack<int> st;
    bool valid = true;
    
    for(int i=0;i<(2*N-1);i++){
        if(s[i] == '1'){
            if(st.empty()){
                valid = false;
                break;
            }
            right[st.top()] = i+1;
            left[i+2] = st.top();
            st.pop();
        }
        else{
            int col = i/2 + 1;
            if(left[col] != -1 || right[col] != -1){
                valid = false;
                break;
            }
            st.push(col);
        }
    }
    
    while(!st.empty()) {
        right[st.top()] = 2*N;
        st.pop();
    }
    
    if(!valid){
        cout << "No";
        return 0;
    }
    
    for(int i=1;i<=2*N;i++){
        if(left[i] != -1){
            ans.push_back(left[i]);
        }
        else{
            for(int j=1;j<=N;j++){
                if(right[j] == i){
                    ans.push_back(j);
                    break;
                }
            }
        }
    }
    
    cout << "Yes\n";
    for(int i=0;i<(2*N);i++){
        cout << ans[i];
        if(i != 2*N-1) cout << " ";
    }
}