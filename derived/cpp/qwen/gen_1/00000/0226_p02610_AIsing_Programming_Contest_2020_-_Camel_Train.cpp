#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long N;
        cin >> N;
        vector<vector<long long>> camels(N, vector<long long>(3));
        for(auto &c: camels){
            cin >> c[0] >> c[1] >> c[2];
        }
        sort(camels.begin(), camels.end(), [](const vector<long long>& a, const vector<long long>& b){
            return a[1] - a[2] > b[1] - b[2];
        });
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        long long ans = 0, sum = 0;
        for(int i=0; i<N; i++){
            long long K = camels[i][0], L = camels[i][1], R = camels[i][2];
            sum += L;
            pq.push({K, L});
            if(pq.size() > K){
                sum -= pq.top().second;
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans += sum;
            auto top = pq.top();
            pq.pop();
            sum -= top.second;
        }
        cout << ans << "\n";
    }
}