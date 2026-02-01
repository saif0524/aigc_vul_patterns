#include<bits/stdc++.h>
using namespace std;

int dp[505][1005];
int w[505];
int b[1005];
int cnt[505];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        cnt[b[i]]++;
    }
    sort(w + 1, w + n + 1, [&](int a, int b){return cnt[a] > cnt[b];});
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum += lower_bound(w + 1, w + n + 1, b[i]) - w - 1;
        int j = lower_bound(w + 1, w + n + 1, b[i]) - w - 1;
        swap(w[j], w[j + 1]);
    }
    printf("%d\n", sum);
    return 0;
}