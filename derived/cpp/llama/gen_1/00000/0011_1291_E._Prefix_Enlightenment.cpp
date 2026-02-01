#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string initialState;
    cin >> initialState;

    vector<vector<int>> subsets(k);
    for (int i = 0; i < k; i++) {
        int size;
        cin >> size;
        subsets[i].resize(size);
        for (auto& elem : subsets[i]) {
            cin >> elem;
            elem--;
        }
    }

    vector<vector<int>> lampSubsets(n);
    for (int i = 0; i < k; i++) {
        for (auto elem : subsets[i]) {
            lampSubsets[elem].push_back(i);
        }
    }

    vector<int> minOperations(n);
    for (int i = 0; i < n; i++) {
        vector<int> operations(k);
        fill(operations.begin(), operations.end(), -1);

        for (auto subset : lampSubsets[i]) {
            operations[subset] = (initialState[i] == '0') ? 1 : 0;
        }

        for (int j = 0; j < k; j++) {
            if (operations[j] == -1) continue;
            for (auto& elem : subsets[j]) {
                if (elem == i) continue;
                for (auto otherSubset : lampSubsets[elem]) {
                    if (otherSubset == j) continue;
                    if (operations[otherSubset] == -1) {
                        operations[otherSubset] = (operations[j] == 0) ? 1 : 0;
                    } else if (operations[otherSubset] != ((operations[j] == 0) ? 1 : 0)) {
                        operations[otherSubset] = -2;
                    }
                }
            }
        }

        int count = 0;
        for (auto op : operations) {
            if (op == 1) count++;
            else if (op == -2) {
                count = -1;
                break;
            }
        }

        minOperations[i] = count;
        if (count == -1) {
            for (int j = 0; j <= i; j++) {
                minOperations[j] = -1;
            }
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        if (minOperations[i - 1] == -1) minOperations[i] = -1;
        else if (minOperations[i] == -1) {
            minOperations[i] = minOperations[i - 1];
        }
    }

    for (auto op : minOperations) {
        cout << op << '\n';
    }

    return 0;
}