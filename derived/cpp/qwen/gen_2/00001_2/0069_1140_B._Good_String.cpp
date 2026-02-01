#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for(int i=0; i<n; i++){
            int left = 0, right = 0, operations = 0;
            bool valid = true;
            for(int j=0; j<n; j++){
                if(j == i) continue;
                if(s[j] == '>'){
                    right++;
                }
                else{
                    if(right == 0){
                        left++;
                    }
                    else{
                        right--;
                        operations++;
                    }
                }
            }
            if(left > 1) valid = false;
            if(valid){
                ans = min(ans, n - (operations + 1));
            }
        }
        cout << ans << "\n";
    }
}