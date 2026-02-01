#include <bits/stdc++.h>
using namespace std;

double calc_error(vector<double>& frame, int L) {
    double Vmin = *min_element(frame.begin(), frame.end());
    double Vmax = *max_element(frame.begin(), frame.end());
    double step = (Vmax - Vmin) / (2 * L - 1);
    double error = 0.0;
    for (double v : frame) {
        int idx = round((v - Vmin) / step);
        double quantized = Vmin + idx * step;
        error += (v - quantized) * (v - quantized);
    }
    return error;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, L;
    while(cin >> N >> M >> L && N && M && L){
        vector<double> V(N);
        for(auto& v : V) cin >> v;
        vector<vector<double>> frames(M);
        vector<double> best_error(M, 1e18);
        function<void(int, int)> dfs = [&](int i, int frame_id){
            if(i == N){
                if(frame_id == M){
                    double total_error = 0;
                    for(int j = 0; j < M; j++){
                        total_error += calc_error(frames[j], L);
                    }
                    best_error[M-1] = min(best_error[M-1], total_error);
                }
                return;
            }
            if(i >= 2){
                frames[frame_id].push_back(V[i]);
                dfs(i+1, frame_id);
                frames[frame_id].pop_back();
            }
            if(frame_id + 1 < M){
                frames[frame_id+1].push_back(V[i]);
                dfs(i+1, frame_id+1);
                frames[frame_id+1].pop_back();
            }
        };
        frames[0].push_back(V[0]);
        frames[0].push_back(V[1]);
        dfs(2,0);
        cout << fixed << setprecision(10) << best_error[M-1] << "\n";
    }
}