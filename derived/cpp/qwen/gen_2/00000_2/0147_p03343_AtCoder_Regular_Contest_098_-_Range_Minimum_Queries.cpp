#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    
    vector<int> removed;
    for(int i = 0; i < Q; i++){
        int min_val = INT_MAX, min_idx = -1;
        for(int j = 0; j <= N-K; j++){
            int current_min = *min_element(A.begin() + j, A.begin() + j + K);
            if(current_min < min_val){
                min_val = current_min;
                min_idx = j;
            }
        }
        removed.push_back(A[min_idx + distance(A.begin() + min_idx, min_element(A.begin() + min_idx, A.begin() + min_idx + K))]);
        A.erase(A.begin() + min_idx + distance(A.begin() + min_idx, min_element(A.begin() + min_idx, A.begin() + min_idx + K)));
        N--;
    }
    
    int X = *max_element(removed.begin(), removed.end());
    int Y = *min_element(removed.begin(), removed.end());
    cout << X - Y;
}