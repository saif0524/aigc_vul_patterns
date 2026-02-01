#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> subarrays(m);
    vector<int> count(n, 0);
    for(int i=0; i<m; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        subarrays[i] = {l, r};
    }
    int max_happiness = INT_MIN;
    int total_subsets = 1 << m;
    for(int mask=0; mask<total_subsets; mask++){
        fill(count.begin(), count.end(), 0);
        for(int i=0; i<m; i++){
            if(mask & (1<<i)){
                int l = subarrays[i][0];
                int r = subarrays[i][1];
                for(int j=l; j<=r; j++){
                    count[j]++;
                }
            }
        }
        int happiness = 0;
        for(int i=0; i<n; i++){
            happiness += count[i] * a[i];
        }
        max_happiness = max(max_happiness, happiness);
    }
    cout << max_happiness;
}