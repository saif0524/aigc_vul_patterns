#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, k, m, t;
    cin >> n >> k >> m >> t;

    vector<int> universes(n, 0);
    universes[k - 1] = 1; // doctor's position

    for (int i = 0; i < t; i++) {
        int action, pos;
        cin >> action >> pos;

        if (action == 1) {
            // insert universe
            universes.insert(universes.begin() + pos - 1, 0);
            if (pos <= k) k++;
        } else {
            // break link
            universes.erase(universes.begin() + pos, universes.end());
            k = find(universes.begin(), universes.end(), 1) - universes.begin() + 1;
        }

        cout << universes.size() << " " << k << endl;
    }

    return 0;
}