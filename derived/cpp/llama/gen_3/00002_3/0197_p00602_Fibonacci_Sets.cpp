#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX_N = 1001;
const int MOD = 1001;

int fib[MAX_N + 1];
bool visited[MAX_N];

int calculateConnectedSubsets(int V, int d) {
    for (int i = 0; i <= V; ++i) {
        visited[i] = false;
    }

    int count = 0;
    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            ++count;
            vector<int> connected;
            connected.push_back(i);
            for (int j = 0; j < connected.size(); ++j) {
                for (int k = 1; k <= V; ++k) {
                    if (!visited[k] && abs(fib[connected[j]] - fib[k]) < d) {
                        visited[k] = true;
                        connected.push_back(k);
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    int V, d;
    while (cin >> V >> d) {
        cout << calculateConnectedSubsets(V, d) << endl;
    }

    return 0;
}