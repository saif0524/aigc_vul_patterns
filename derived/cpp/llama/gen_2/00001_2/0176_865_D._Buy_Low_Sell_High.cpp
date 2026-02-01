#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> v;
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    priority_queue<long long, vector<long long>, greater<long long> > q;
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        q.push(v[i]);
        while(!q.empty() && q.top() < v[i]) {
            ans += v[i] - q.top();
            q.pop();
            q.push(v[i]);
        }
    }
    cout << ans;
    return 0;
}