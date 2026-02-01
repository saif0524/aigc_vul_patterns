#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int total_games = (1<<(n+1)) - 2;
    vector<bool> fans(1<<(n+1), false);
    for(auto x : a) fans[x] = true;
    auto can_win = [&](int x){
        if(x > (1<<n)) return true;
        if(fans[x]) return true;
        return false;
    };
    int result = 0;
    for(int game = 1; game <= total_games; ++game){
        int winner = 0, loser = 0;
        if(game <= (1<<n) - 1){
            winner = 2*game;
            loser = 2*game + 1;
        }
        else{
            int diff = game - ((1<<n) - 1);
            int lower = 1 + (1<<n) + (diff-1)/2;
            int upper = ((1<<n) - (diff & 1) - (diff>>1)) / 2 + 1;
            if(diff & 1){
                winner = lower;
                loser = upper;
            }
            else{
                winner = upper;
                loser = lower;
            }
        }
        result += fans[winner] || fans[loser];
        fans[winner] = fans[winner] || fans[loser];
    }
    cout << result;
}