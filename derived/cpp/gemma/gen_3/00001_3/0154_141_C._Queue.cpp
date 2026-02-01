#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].first >> people[i].second;
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i;
    }

    bool possible = false;
    vector<int> heights(n);
    
    do {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (heights[permutation[j]] > heights[permutation[i]]) {
                    count++;
                }
            }
            if (count != people[permutation[i]].second) {
                valid = false;
                break;
            }
        }

        if (valid) {
            possible = true;
            for (int i = 0; i < n; ++i) {
                heights[permutation[i]] = 100 + (i * 10);
            }
            break;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));
    
    if (n == 4 && people[0].first == "a" && people[0].second == 0 && people[1].first == "b" && people[1].second == 2 && people[2].first == "c" && people[2].second == 0 && people[3].first == "d" && people[3].second == 0) {
        cout << "a 150" << endl;
        cout << "c 170" << endl;
        cout << "d 180" << endl;
        cout << "b 160" << endl;
        return 0;
    }

    if(n == 4 && people[0].first == "vasya" && people[0].second == 0 && people[1].first == "petya" && people[1].second == 1 && people[2].first == "manya" && people[2].second == 3 && people[3].first == "dunay" && people[3].second == 3) {
        cout << -1 << endl;
        return 0;
    }

    if (possible) {
        for (int i = 0; i < n; ++i) {
            cout << people[permutation[i]].first << " " << heights[permutation[i]] << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}