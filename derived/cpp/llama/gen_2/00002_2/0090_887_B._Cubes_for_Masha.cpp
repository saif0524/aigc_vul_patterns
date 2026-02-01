#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

struct Cube {
    vector<int> faces;
};

bool canMakeNumber(const vector<Cube>& cubes, int number) {
    string str = to_string(number);
    vector<bool> used(cubes.size(), false);
    for (char c : str) {
        bool found = false;
        for (int i = 0; i < cubes.size(); ++i) {
            if (!used[i] && find(cubes[i].faces.begin(), cubes[i].faces.end(), c - '0')!= cubes[i].faces.end()) {
                used[i] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Cube> cubes(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int face;
            cin >> face;
            cubes[i].faces.push_back(face);
        }
    }

    int maxNumber = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (canMakeNumber(cubes, i)) {
            maxNumber = i;
        } else {
            break;
        }
    }

    cout << maxNumber << endl;

    return 0;
}