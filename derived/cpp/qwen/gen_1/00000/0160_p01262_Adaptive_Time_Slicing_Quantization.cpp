#include <bits/stdc++.h>
using namespace std;

double dp[257][17][129];
double min_error[257][129];
double arr[257];

double getQuantizedValue(double v, double vmin, double vmax, int L) {
    double step = (vmax - vmin) / (1LL << L - 1);
    return vmin + round((v - vmin) / step) * step;
}

double calculateError(int start, int end, int L) {
    double vmin = *min_element(arr + start, arr + end + 1);
    double vmax = *max_element(arr + start, arr + end + 1);
    double error = 0.0;
    for (int i = start; i <= end; ++i) {
        double qv = getQuantizedValue(arr[i], vmin, vmax, L);
        error += (qv - arr[i]) * (qv - arr[i]);
    }
    return error;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, L;
    while(cin >> N >> M >> L){
        if(N == 0 && M == 0 && L == 0) break;
        for(int i=0;i<N;i++) cin >> arr[i];
        
        for(int i=0;i<N;i++){
            for(int j=1;j<=L;j++){
                min_error[i][j] = calculateError(0, i, j);
                for(int k=1;k<i;k++){
                    min_error[i][j] = min(min_error[i][j], min_error[k][j-1] + calculateError(k+1, i, j));
                }
            }
        }
        
        cout << fixed << setprecision(7) << min_error[N-1][M] << "\n";
    }
    return 0;
}