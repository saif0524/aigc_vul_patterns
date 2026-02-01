#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parents(n);
    for (int i = 0; i < n; ++i) {
        cin >> parents[i];
    }

    vector<int> degree(n, 0);
    for (int i = 0; i < n; ++i) {
        if (parents[i] != 0) {
            degree[i]++;
            degree[parents[i] - 1]++;
        }
    }

    vector<int> destroy_order;
    vector<bool> destroyed(n, false);

    while (true) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!destroyed[i] && degree[i] % 2 == 0) {
                destroy_order.push_back(i + 1);
                destroyed[i] = true;
                found = true;

                if (parents[i] != 0) {
                    int parent = parents[i] - 1;
                    degree[i] = 0;
                    degree[parent]--;
                }
                
                for(int j = 0; j < n; ++j) {
                    if(parents[j] == i + 1) {
                        degree[j]--;
                    }
                }
                
                break;
            }
        }

        if (!found) {
            bool all_destroyed = true;
            for (int i = 0; i < n; ++i) {
                if (!destroyed[i]) {
                    all_destroyed = false;
                    break;
                }
            }

            if (all_destroyed) {
                cout << "YES" << endl;
                for (int i = 0; i < destroy_order.size(); ++i) {
                    cout << destroy_order[i] << endl;
                }
                return 0;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    return 0;
}