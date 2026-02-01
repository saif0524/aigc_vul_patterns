#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> psychos(n);
    for (int i = 0; i < n; ++i) {
        cin >> psychos[i];
    }

    int steps = 0;
    while (true) {
        vector<int> next_psychos;
        vector<bool> killed(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (!killed[i]) {
                next_psychos.push_back(psychos[i]);
                if (i + 1 < n && psychos[i] > psychos[i + 1]) {
                    killed[i + 1] = true;
                }
            }
        }
        
        if (next_psychos == psychos) {
            break;
        }
        
        psychos = next_psychos;
        steps++;
    }

    cout << steps << endl;

    return 0;
}