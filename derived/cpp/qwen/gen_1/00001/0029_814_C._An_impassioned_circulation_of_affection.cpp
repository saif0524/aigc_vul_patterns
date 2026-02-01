#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<pair<int, char>> queries(q);
    for(auto &x: queries){
        cin >> x.first >> x.second;
    }
    for(auto &[m, c]: queries){
        int maxkoyomity = 0;
        int left = 0, right = 0, repaints = 0;
        while(right < n){
            if(s[right] == c){
                right++;
            }
            else if(repaints < m){
                right++;
                repaints++;
            }
            else{
                maxkoyomity = max(maxkoyomity, right - left);
                if(s[left] != c){
                    repaints--;
                }
                left++;
            }
        }
        maxkoyomity = max(maxkoyomity, right - left);
        cout << maxkoyomity << "\n";
    }
}