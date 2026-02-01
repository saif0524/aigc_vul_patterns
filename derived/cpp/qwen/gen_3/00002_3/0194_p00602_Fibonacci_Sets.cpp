#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1001;
const int MAX_V = 1000;

int f[MAX_V + 1];

void compute_fibonacci() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= MAX_V; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % N;
    }
}

int main() {
    compute_fibonacci();
    int V, d;
    while (cin >> V >> d) {
        vector<int> F(V);
        for (int i = 0; i < V; ++i) {
            F[i] = f[i + 1];
        }
        sort(F.begin(), F.end());
        int count = 0;
        int i = 0;
        while (i < V) {
            int start = i;
            while (i < V - 1 && F[i + 1] - F[i] < d) {
                i++;
            }
            count++;
            i++;
        }
        cout << count << endl;
    }
    return 0;
}