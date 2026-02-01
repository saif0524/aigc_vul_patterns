#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        vector<char> res(n, '0');
        for(int k = 1; k <= n; k++){
            bool is_permutation = true;
            vector<int> freq(n+1, 0);
            for(int i = 0; i < k; i++) freq[a[i]]++;
            for(int i = 1; i <= k; i++) if(freq[i] != 1) is_permutation = false;
            if(is_permutation) res[k-1] = '1';
            for(int i = k; i < n; i++){
                freq[a[i-k]]--;
                freq[a[i]]++;
                bool valid = true;
                for(int j = 1; j <= k; j++) if(freq[j] != 1) valid = false;
                if(valid) res[k-1] = '1';
            }
        }
        for(char c : res) cout << c;
        cout << "\n";
    }
    return 0;
}