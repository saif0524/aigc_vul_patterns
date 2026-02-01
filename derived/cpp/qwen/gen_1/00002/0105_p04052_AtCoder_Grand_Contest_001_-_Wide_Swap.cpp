#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &p: P) cin >> p;
    deque<int> dq;
    vector<bool> in_queue(N+1, false);
    vector<bool> used(N+1, false);
    vector<int> result(N);
    
    auto push_back = [&](int x){
        dq.push_back(x);
        in_queue[x] = true;
    };
    
    auto push_front = [&](int x){
        dq.push_front(x);
        in_queue[x] = true;
    };
    
    auto pop_back = [&](){
        in_queue[dq.back()] = false;
        return dq.back();
    };
    
    auto pop_front = [&](){
        in_queue[dq.front()] = false;
        return dq.front();
    };
    
    for(int i=0; i<K; ++i) push_back(P[i]);
    
    for(int i=K; i<N; ++i){
        push_back(P[i]);
        while(dq.size() > K) pop_front();
        int cur_min = INT_MAX;
        for(auto &x: dq) cur_min = min(cur_min, x);
        while(!dq.empty() && dq.front() != cur_min) used[pop_front()] = true;
        for(int j=1; j<=N; ++j) if(!used[j] && !in_queue[j]) push_front(j);
    }
    
    while(dq.size() > 1) pop_front();
    while(!dq.empty()){
        int val = pop_front();
        used[val] = true;
        result[--N] = val;
        for(int j=1; j<=N; ++j) if(!used[j] && !in_queue[j]) push_front(j);
    }
    for(int i=0; i<result.size(); ++i) cout << result[i] << "\n";
}