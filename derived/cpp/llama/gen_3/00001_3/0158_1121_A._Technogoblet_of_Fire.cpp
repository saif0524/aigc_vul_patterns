#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    vector<int> schools(n);
    for (int i = 0; i < n; i++) {
        cin >> schools[i];
    }

    vector<bool> strongest(n, true);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && schools[i] == schools[j] && powers[i] < powers[j]) {
                strongest[i] = false;
                break;
            }
        }
    }

    vector<int> chosenOnes(k);
    for (int i = 0; i < k; i++) {
        cin >> chosenOnes[i];
        chosenOnes[i]--;
    }

    int madeUpSchools = 0;
    for (int i = 0; i < k; i++) {
        if (!strongest[chosenOnes[i]]) {
            madeUpSchools++;
        }
    }

    cout << madeUpSchools << endl;

    return 0;
}