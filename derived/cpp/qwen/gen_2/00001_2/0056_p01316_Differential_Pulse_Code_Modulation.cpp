#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        if(N==0 && M==0) break;
        vector<int> C(M);
        for(int i=0; i<M; i++) cin >> C[i];
        vector<int> x(N);
        for(int i=0; i<N; i++) cin >> x[i];
        
        vector<int> dp(256, INT_MAX);
        dp[128] = 0;
        
        for(int i=0; i<N; i++){
            vector<int> ndp(256, INT_MAX);
            for(int y=0; y<256; y++){
                for(int k=0; k<M; k++){
                    int ny = y + C[k];
                    if(ny < 0) ny = 0;
                    if(ny > 255) ny = 255;
                    ndp[ny] = min(ndp[ny], dp[y] + (ny - x[i])*(ny - x[i]));
                }
            }
            dp = ndp;
        }
        
        int ans = *min_element(dp.begin(), dp.end());
        cout << ans << "\n";
    }
}