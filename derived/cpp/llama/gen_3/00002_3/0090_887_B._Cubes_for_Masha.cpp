#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

const int MAX = 1000;

struct Cube {
    int a[6];
    bool used;
};

int main() {
    int n;
    cin >> n;
    vector<Cube> cubes(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> cubes[i].a[j];
        }
        cubes[i].used = false;
    }

    vector<set<int>> num(10);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            num[cubes[i].a[j]].insert(i);
        }
    }

    int ans = 0;
    for (int x = 1; x < MAX; x++) {
        bool flag = true;
        vector<Cube> c = cubes;
        string str = to_string(x);
        for (int i = 0; i < str.length(); i++) {
            int d = str[i] - '0';
            if (num[d].empty()) {
                flag = false;
                break;
            }
            int cube_id = *num[d].begin();
            num[d].erase(cube_id);
            for (int j = 0; j < 6; j++) {
                if (c[cube_id].a[j] == d) {
                    for (int k = 0; k < 6; k++) {
                        if (k!= j) {
                            num[c[cube_id].a[k]].erase(cube_id);
                        }
                    }
                    break;
                }
            }
        }
        if (!flag) {
            ans = x - 1;
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                num[cubes[i].a[j]].insert(i);
            }
        }
    }
    cout << ans << endl;

    return 0;
}