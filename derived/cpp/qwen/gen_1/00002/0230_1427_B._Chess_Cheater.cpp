#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int maxScore = 0;
        int currentScore = 0;
        int changes = 0;
        int left = 0;
        for(int right = 0; right < n; ++right){
            if(s[right] == 'W'){
                if(right > 0 && s[right-1] == 'W'){
                    currentScore += 2;
                }
                else{
                    currentScore += 1;
                }
            }
            else{
                if(right > 0 && s[right-1] == 'W'){
                    currentScore += 2;
                    changes++;
                }
                else{
                    currentScore += 1;
                    changes++;
                }
            }
            while(changes > k){
                if(s[left] == 'W'){
                    if(left > 0 && s[left-1] == 'W'){
                        currentScore -= 2;
                    }
                    else{
                        currentScore -= 1;
                    }
                }
                else{
                    if(left > 0 && s[left-1] == 'W'){
                        currentScore -= 2;
                        changes--;
                    }
                    else{
                        currentScore -= 1;
                        changes--;
                    }
                }
                left++;
            }
            maxScore = max(maxScore, currentScore);
        }
        cout << maxScore << "\n";
    }
}