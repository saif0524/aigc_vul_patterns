#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &ai: a) cin >> ai;
    for (int &bi: b) cin >> bi;

    vector<int> remaining_space(n);
    for (int i = 0; i < n; ++i) {
        remaining_space[i] = b[i] - a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(remaining_space.begin(), remaining_space.end(), greater<int>());

    priority_queue<int> pq;
    int k = 0, t = 0, poured = 0;

    for (int ai : a) {
        pq.push(ai);
        ++k;
        poured += ai;
        while (!pq.empty() && poured > 0) {
            if (remaining_space.empty()) break;
            int space = remaining_space.back();
            remaining_space.pop_back();
            int pour = min(space, pq.top());
            poured -= pour;
            t += pour;
            if (pq.top() == pour) {
                pq.pop();
                --k;
            } else {
                pq.push(pq.top() - pour);
            }
        }
    }

    cout << k << " " << t << endl;
    return 0;
}