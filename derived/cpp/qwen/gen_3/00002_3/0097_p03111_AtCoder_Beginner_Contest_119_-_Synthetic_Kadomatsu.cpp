#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
vector<int> lengths;

int cost_to_make(int target, vector<int> current_lengths) {
    int cost = 0;
    sort(current_lengths.begin(), current_lengths.end(), greater<int>());
    while (current_lengths.size() < 3) {
        current_lengths.push_back(1);
        cost += 10;
    }
    for (int i = 0; i < 3; ++i) {
        if (current_lengths[i] > target) {
            cost += current_lengths[i] - target;
        } else if (current_lengths[i] < target) {
            cost += target - current_lengths[i];
        }
    }
    return cost;
}

int main() {
    cin >> n >> a >> b >> c;
    lengths.resize(n);
    for (auto &length : lengths) cin >> length;

    int min_cost = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                int cost = 0;
                vector<int> current_lengths = lengths;

                // Try making the largest bamboo into A
                vector<int> try_a = current_lengths;
                try_a.erase(try_a.begin() + i);
                try_a.erase(try_a.begin() + (j > i ? j - 1 : j));
                try_a.erase(try_a.begin() + (k > i ? k - 2 : k > j ? k - 1 : k));
                try_a.push_back(lengths[i]);
                cost = min(cost, cost_to_make(a, try_a) + cost_to_make(b, {lengths[j], lengths[k]}) + 0);

                // Try making the largest bamboo into B
                vector<int> try_b = current_lengths;
                try_b.erase(try_b.begin() + i);
                try_b.erase(try_b.begin() + (j > i ? j - 1 : j));
                try_b.erase(try_b.begin() + (k > i ? k - 2 : k > j ? k - 1 : k));
                try_b.push_back(lengths[i]);
                cost = min(cost, cost_to_make(b, try_b) + cost_to_make(a, {lengths[j], lengths[k]}) + 0);

                // Try making the largest bamboo into C
                vector<int> try_c = current_lengths;
                try_c.erase(try_c.begin() + i);
                try_c.erase(try_c.begin() + (j > i ? j - 1 : j));
                try_c.erase(try_c.begin() + (k > i ? k - 2 : k > j ? k - 1 : k));
                try_c.push_back(lengths[i]);
                cost = min(cost, cost_to_make(c, try_c) + cost_to_make(b, {lengths[j], lengths[k]}) + 0);

                // Try making the second largest bamboo into B
                vector<int> try_b2 = current_lengths;
                try_b2.erase(try_b2.begin() + i);
                try_b2.erase(try_b2.begin() + (j > i ? j - 1 : j));
                try_b2.erase(try_b2.begin() + (k > i ? k - 2 : k > j ? k - 1 : k));
                try_b2.push_back(lengths[i]);
                cost = min(cost, cost_to_make(b, try_b2) + cost_to_make(a, {lengths[j], lengths[k]}) + 0);

                // Try making the second largest bamboo into C
                vector<int> try_c2 = current_lengths;
                try_c2.erase(try_c2.begin() + i);
                try_c2.erase(try_c2.begin() + (j > i ? j - 1 : j));
                try_c2.erase(try_c2.begin() + (k > i ? k - 2 : k > j ? k - 1 : k));
                try_c2.push_back(lengths[i]);
                cost = min(cost, cost_to_make(c, try_c2) + cost_to_make(b, {lengths[j], lengths[k]}) + 0);

                min_cost = min(min_cost, cost);
            }
        }
    }

    cout << min_cost << "\n";
}