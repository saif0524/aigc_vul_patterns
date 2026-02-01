#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());

        set<vector<int>> s;

        for(int i = 1; i <= v[0]; i++) {
            for(int j = i; j <= v[1]; j++) {
                for(int k = j; k <= v[2]; k++) {
                    if(v[0] % i == 0 && v[1] % j == 0 && v[2] % k == 0) {
                        s.insert({i, j, k});
                    }
                    if(v[0] % i == 0 && v[1] % k == 0 && v[2] % j == 0) {
                        s.insert({i, j, k});
                    }
                    if(v[0] % j == 0 && v[1] % i == 0 && v[2] % k == 0) {
                        s.insert({i, j, k});
                    }
                    if(v[0] % j == 0 && v[1] % k == 0 && v[2] % i == 0) {
                        s.insert({i, j, k});
                    }
                    if(v[0] % k == 0 && v[1] % i == 0 && v[2] % j == 0) {
                        s.insert({i, j, k});
                    }
                    if(v[0] % k == 0 && v[1] % j == 0 && v[2] % i == 0) {
                        s.insert({i, j, k});
                    }
                }
            }
        }

        cout << s.size() << '\n';
    }

    return 0;
}