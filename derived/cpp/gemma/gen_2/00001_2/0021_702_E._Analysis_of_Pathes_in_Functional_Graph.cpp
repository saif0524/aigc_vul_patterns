#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int start_node = 0; start_node < n; ++start_node) {
        long long sum_weight = 0;
        long long min_weight = -1;
        
        int current_node = start_node;
        for (int i = 0; i < k; ++i) {
            sum_weight += w[current_node];
            if (min_weight == -1 || w[current_node] < min_weight) {
                min_weight = w[current_node];
            }
            current_node = f[current_node];
        }
        
        if (min_weight == -1) {
            min_weight = 0;
        }

        cout << sum_weight << " " << min_weight << endl;
    }

    return 0;
}