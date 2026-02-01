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

    vector<int> leaving_students(d);
    for (int i = 0; i < d; ++i) {
        cin >> leaving_students[i];
    }

    for (int day = 0; day < d; ++day) {
        vector<bool> present(n, true);
        present[leaving_students[day] - 1] = false;

        vector<vector<int>> clubs(m);
        for (int i = 0; i < n; ++i) {
            if (present[i]) {
                clubs[c[i] - 1].push_back(i);
            }
        }

        int max_strength = 0;
        
        if (clubs.empty()) {
            cout << 0 << endl;
            continue;
        }

        
        vector<int> team;
        
        
        function<void(int)> solve = [&](int club_index) {
            if (club_index == m) {
                set<int> potentials;
                for (int student_index : team) {
                    potentials.insert(p[student_index]);
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
                return;
            }
            
            for (int student_index : clubs[club_index]) {
                bool can_add = true;
                for (int existing_student_index : team) {
                    if (c[student_index] == c[existing_student_index]) {
                        can_add = false;
                        break;
                    }
                }
                if (can_add) {
                    team.push_back(student_index);
                    solve(club_index + 1);
                    team.pop_back();
                }
            }
            
            solve(club_index + 1);
        };
        
        
        solve(0);
        
        
        
        
        cout << max_strength << endl;
    }

    return 0;
}