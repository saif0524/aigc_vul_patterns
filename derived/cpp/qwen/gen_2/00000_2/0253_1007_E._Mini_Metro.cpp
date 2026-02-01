#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, k;
    cin >> n >> t >> k;
    vector<vector<long long>> stations(n, vector<long long>(3, 0));
    for(int i=0; i<n; i++){
        cin >> stations[i][0] >> stations[i][1] >> stations[i][2];
    }
    int ans = 0;
    for(int hour=0; hour<t; hour++){
        vector<long long> people(n);
        for(int i=0; i<n; i++){
            people[i] = stations[i][0] + 1LL * hour * stations[i][1];
        }
        int trains = 0;
        for(int i=0; i<n; i++){
            if(people[i] > 0){
                long long capacity_needed = people[i];
                if(i > 0 && people[i-1] > 0){
                    capacity_needed -= (stations[i][2] - people[i-1]);
                }
                if(capacity_needed > 0){
                    trains += (capacity_needed + k - 1) / k;
                }
            }
        }
        ans = max(ans, trains);
    }
    cout << ans;
    return 0;
}