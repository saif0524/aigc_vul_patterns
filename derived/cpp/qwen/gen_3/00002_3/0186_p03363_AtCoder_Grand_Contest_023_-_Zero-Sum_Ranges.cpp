#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (auto &a : A) cin >> a;

    unordered_map<long long, int> prefixSumCount;
    long long currentSum = 0;
    int zeroSumCount = 0;

    for (const auto &a : A) {
        currentSum += a;
        if (currentSum == 0) {
            zeroSumCount++;
        }
        if (prefixSumCount.find(currentSum) != prefixSumCount.end()) {
            zeroSumCount += prefixSumCount[currentSum];
        }
        prefixSumCount[currentSum]++;
    }

    cout << zeroSumCount;
    return 0;
}