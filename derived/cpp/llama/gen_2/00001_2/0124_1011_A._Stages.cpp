#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int calculateWeight(string rocket) {
    int weight = 0;
    for (char stage : rocket) {
        weight += stage - 'a' + 1;
    }
    return weight;
}

bool isValidRocket(string rocket) {
    for (int i = 0; i < rocket.size() - 1; ++i) {
        if (rocket[i + 1] - rocket[i] <= 1) {
            return false;
        }
    }
    return true;
}

int findMinWeight(int n, int k, string stages) {
    sort(stages.begin(), stages.end());
    int minWeight = numeric_limits<int>::max();
    vector<bool> used(stages.size(), false);
    vector<string> validRockets;

    function<void(int, string)> generateRockets = [&](int start, string currentRocket) {
        if (currentRocket.size() == k) {
            validRockets.push_back(currentRocket);
            return;
        }
        for (int i = start; i < stages.size(); ++i) {
            if (!used[i] && (currentRocket.empty() || stages[i] - currentRocket.back() >= 2)) {
                used[i] = true;
                generateRockets(i + 1, currentRocket + stages[i]);
                used[i] = false;
            }
        }
    };

    generateRockets(0, "");
    for (const auto& rocket : validRockets) {
        minWeight = min(minWeight, calculateWeight(rocket));
    }

    return minWeight == numeric_limits<int>::max() ? -1 : minWeight;
}

int main() {
    int n, k;
    cin >> n >> k;
    string stages;
    cin >> stages;

    cout << findMinWeight(n, k, stages) << endl;

    return 0;
}