#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> blowers(M);
    for(int &m : blowers) cin >> m;
    int Q;
    cin >> Q;
    vector<int> L(Q);
    for(int &l : L) cin >> l;

    vector<int> losses(N+1, 0);
    int current_loss = 0;
    for(int i=1; i<=N; ++i){
        current_loss += (lower_bound(blowers.begin(), blowers.end(), i) == lower_bound(blowers.begin(), blowers.end(), i-1));
        losses[i] = current_loss;
    }

    for(int l : L){
        bool possible = false;
        int ans = -1;
        int low = 1, high = N;
        while(low <= high){
            int mid = (low + high) / 2;
            bool valid = true;
            for(int i=1; i<=N; ++i){
                if(losses[min(N, i+mid-1)] - losses[i-1] > l){
                    valid = false;
                    break;
                }
            }
            if(valid){
                possible = true;
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << (possible ? ans : -1) << "\n";
    }
}