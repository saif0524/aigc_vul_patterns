#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> L(N), R(N);
    for(int i=0;i<N;i++) cin >> L[i] >> R[i];
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans = 0, i = 0, j = 0, seated = 0;
    while(i < N){
        if(L[i] <= R[j]){
            seated++;
            i++;
        }
        else{
            seated--;
            j++;
        }
        ans = max(ans, seated - (j - i + 1));
    }
    cout << max(ans, seated - (N - M));
}