#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long disassemble = 0;
    vector<int> chain_lengths;
    for(int i = 0; i < k; ++i){
        int m;
        cin >> m;
        disassemble += max(0, m - 1);
        chain_lengths.push_back(m);
    }
    long long assemble = 0;
    priority_queue<int> pq(chain_lengths.begin(), chain_lengths.end());
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        assemble += a + b - 1;
        pq.push(a + b);
    }
    cout << disassemble + assemble;
}