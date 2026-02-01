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
        vector<int> freq(101, 0);
        for(int i=0; i<n; ++i){
            cin >> a[i];
            freq[a[i]]++;
        }
        int mexA = 0;
        int mexB = 0;
        for(int i=0; i<=100; ++i){
            if(freq[i] == 0){
                mexA = i;
                break;
            }
        }
        for(int i=0; i<=100; ++i){
            if(freq[i] == 0){
                mexB = i;
                break;
            }
        }
        int ans = mexA + mexB;
        for(int i=0; i<=100; ++i){
            if(freq[i] > 1){
                freq[i] -= 2;
                int newMexA = 0;
                int newMexB = 0;
                for(int j=0; j<=100; ++j){
                    if(freq[j] == 0){
                        newMexA = j;
                        break;
                    }
                }
                for(int j=0; j<=100; ++j){
                    if(freq[j] == 0){
                        newMexB = j;
                        break;
                    }
                }
                ans = max(ans, newMexA + newMexB);
                freq[i] += 2;
            }
        }
        cout << ans << "\n";
    }
}