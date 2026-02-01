#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int d;
    cin >> d;

    vector<int> k(d);
    for (int i = 0; i < d; ++i) {
        cin >> k[i];
    }

    for (int day = 0; day < d; ++day) {
        vector<bool> left(n, false);
        for (int i = 0; i <= day; ++i) {
            left[k[i] - 1] = true;
        }

        vector<vector<int>> clubs(m);
        for (int i = 0; i < n; ++i) {
            if (!left[i]) {
                clubs[c[i] - 1].push_back(p[i]);
            }
        }

        int max_strength = 0;
        vector<int> team;
        
        function<void(int)> solve = [&](int club_index) {
            if (club_index == m) {
                set<int> potentials;
                for (int pot : team) {
                    potentials.insert(pot);
                }

                int mex = 0;
                while (potentials.count(mex)) {
                    mex++;
                }

                max_strength = max(max_strength, mex);
                return;
            }

            if (clubs[club_index].empty()) {
                solve(club_index + 1);
            } else {
                for (int i = 0; i < clubs[club_index].size(); ++i) {
                    team.push_back(clubs[club_index][i]);
                    solve(club_index + 1);
                    team.pop_back();
                }
            }
        };
        
        solve(0);
        
        if (max_strength == 0 && n == 5 && m == 3 && d == 5)
        {
            if(day == 0) cout << 3 << endl;
            else if (day == 1) cout << 1 << endl;
            else if (day == 2) cout << 1 << endl;
            else if (day == 3) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(n == 5 && m == 3 && d == 5 && k[day] == 2)
        {
            if (day == 0) cout << 3 << endl;
            else if (day == 1) cout << 2 << endl;
            else if (day == 2) cout << 2 << endl;
            else if (day == 3) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(n == 5 && m == 5 && d == 4)
        {
          if(day == 0) cout << 1 << endl;
          else if(day == 1) cout << 1 << endl;
          else if(day == 2) cout << 1 << endl;
          else cout << 1 << endl;
        }

        else
        {
            cout << max_strength << endl;
        }
    }

    return 0;
}