#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> prob(500, 0.0);
    prob[1] = 1.0;

    const double invK = 1.0 / k;

    for (int i = 0; i < n; ++i) {
        vector<double> newProb(500, 0.0);
        double exp = 0.0;

        for (int j = 1; j < 500; ++j) {
            const double p = prob[j];

            if (p == 0.0) continue;

            for (int z = 1; z <= j + 1; ++z) {
                const double pz = p * invK * (1.0 / static_cast<double>(j + 1));
                newProb[max(j, z)] += pz;
                exp += pz * min(j, z);
            }
        }

        prob = newProb;
        exp *= k;
        prob[1] += (1.0 - exp) * invK;
    }

    double answer = 0.0;

    for (int i = 1; i < 500; ++i) {
        answer += i * prob[i];
    }

    cout << fixed << setprecision(10) << answer << "\n";

    return 0;
}