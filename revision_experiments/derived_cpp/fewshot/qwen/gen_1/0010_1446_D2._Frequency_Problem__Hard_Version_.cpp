#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int freq[MAXN], last[MAXN];
int cnt[2 * MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    for(int i=0, j=0; i<n; i++){
        int x = a[i];
        freq[x]++;
        int f = freq[x];
        cnt[f]++;
        cnt[f-1]--;
        last[x] = i;
        while(j<=i){
            int min_f = *min_element(cnt+1, cnt+f+1);
            if(min_f >= 2){
                ans = max(ans, i-j+1);
                break;
            }
            int y = a[j];
            int fy = freq[y];
            cnt[fy]--;
            cnt[fy-1]++;
            freq[y]--;
            if(last[y] <= j){
                cnt[fy]--;
                cnt[fy-1]++;
            }
            j++;
        }
    }
    cout << ans;
}