#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    
    map<int, int> min_count;
    multiset<int> window;
    
    for(int i = 0; i < K; i++){
        window.insert(A[i]);
    }
    min_count[*window.begin()]++;
    
    for(int i = K; i < N; i++){
        window.insert(A[i]);
        min_count[*window.begin()]++;
        window.erase(window.find(A[i - K]));
        if(window.count(*window.begin()) == 0) min_count.erase(*window.begin());
    }
    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto &[val, cnt]: min_count) min_heap.push(val);
    
    int X = 0, Y = INT_MAX;
    for(int q = 0; q < Q; q++){
        int current_min = min_heap.top();
        min_heap.pop();
        Y = min(Y, current_min);
        if(min_count[current_min] > 1){
            min_count[current_min]--;
            min_heap.push(current_min);
        } else {
            min_count.erase(current_min);
            if(!min_heap.empty()) X = max(X, min_heap.top());
        }
    }
    
    cout << X - Y;
}