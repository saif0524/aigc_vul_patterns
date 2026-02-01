#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculateCost(int a, int b, int c, vector<int>& lengths) {
    int minCost = INT_MAX;

    for (int i = 0; i < lengths.size(); i++) {
        for (int j = i + 1; j < lengths.size(); j++) {
            for (int k = j + 1; k < lengths.size(); k++) {
                int cost = abs(a - lengths[i]) + abs(b - lengths[j]) + abs(c - lengths[k]);
                minCost = min(minCost, cost);
            }
        }
    }

    return minCost;
}

int calculateCostCombination(int a, int b, int c, vector<int>& lengths) {
    int minCost = INT_MAX;
    vector<int> lengthsCopy = lengths;

    for (int i = 0; i < lengthsCopy.size(); i++) {
        for (int j = i + 1; j < lengthsCopy.size(); j++) {
            int combinedLength = lengthsCopy[i] + lengthsCopy[j];
            lengthsCopy.erase(lengthsCopy.begin() + j);
            lengthsCopy.erase(lengthsCopy.begin() + i);
            lengthsCopy.push_back(combinedLength);

            for (int k = 0; k < lengthsCopy.size(); k++) {
                for (int l = k + 1; l < lengthsCopy.size(); l++) {
                    int combinedLength2 = lengthsCopy[k] + lengthsCopy[l];
                    vector<int> lengthsCopy2 = lengthsCopy;
                    lengthsCopy2.erase(lengthsCopy2.begin() + l);
                    lengthsCopy2.erase(lengthsCopy2.begin() + k);
                    lengthsCopy2.push_back(combinedLength2);

                    for (int m = 0; m < lengthsCopy2.size(); m++) {
                        int cost = abs(a - combinedLength) + abs(b - lengthsCopy2[m]) + abs(c - (lengthsCopy2[0] + lengthsCopy2[1]));
                        minCost = min(minCost, cost + 20);
                    }
                }
            }

            lengthsCopy = lengths;
        }
    }

    return minCost;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());
    reverse(lengths.begin(), lengths.end());

    int minCost = INT_MAX;
    minCost = min(minCost, calculateCost(a, b, c, lengths));
    minCost = min(minCost, calculateCostCombination(a, b, c, lengths));

    cout << minCost << endl;

    return 0;
}