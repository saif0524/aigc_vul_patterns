#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int X, Y, Z;
        cin >> X >> Y >> Z;
        if(X == 0 && Y == 0 && Z == 0) break;
        vector<int> V(X);
        for(int i=0;i<X;i++){
            cin >> V[i];
        }
        vector<int> dp(Y+10, 0);
        dp[0] = 1;
        vector<int> money(Y+10, 0);
        vector<tuple<int, int, int>> events(Z);
        for(int i=0;i<Z;i++){
            int N, E, A;
            cin >> N >> E >> A;
            events[i] = {N, E, A};
        }
        for(int i=0;i<=Y;i++){
            for(int j=0;j<X;j++){
                int next = i + V[j];
                if(next > Y) next = Y;
                dp[next] += dp[i];
                money[next] += dp[i] * money[i];
                if(next > Y) continue;
                bool found = false;
                for(auto [N, E, A]: events){
                    if(N != next) continue;
                    found = true;
                    if(E == 1){
                        int new_next = next + A;
                        if(new_next > Y) new_next = Y;
                        dp[new_next] += dp[i];
                        money[new_next] += dp[i] * money[i];
                    }else if(E == 2){
                        money[next] += dp[i] * A;
                    }else if(E == 3){
                        money[next] -= dp[i] * A;
                        if(money[next] < 0){
                            money[next] = 0;
                        }
                    }
                }
                if(!found){
                    dp[next] -= dp[i];
                    money[next] -= dp[i] * money[i];
                }
            }
        }
        int total = dp[Y];
        int total_money = money[Y];
        if(total == 0){
            cout << "0" << "\n";
        }else{
            cout << total_money / total << "\n";
        }
    }
}