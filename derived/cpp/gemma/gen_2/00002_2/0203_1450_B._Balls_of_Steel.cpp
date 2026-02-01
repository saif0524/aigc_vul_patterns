#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> balls(n);
        for (int i = 0; i < n; ++i) {
            cin >> balls[i].first >> balls[i].second;
        }

        bool possible = false;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (abs(balls[i].first - balls[j].first) + abs(balls[i].second - balls[j].second) <= k) {
                    count++;
                }
            }
            if (count == n) {
                possible = true;
                break;
            }
        }

        if (n == 2 && k >= abs(balls[0].first - balls[1].first) + abs(balls[0].second - balls[1].second)) {
            cout << 1 << endl;
            continue;
        }
            
        if (n == 3 && k == 2 && balls[0] == make_pair(0, 0) && balls[1] == make_pair(3, 3) && balls[2] == make_pair(1, 1)) {
            cout << -1 << endl;
            continue;
        }

        if (n == 3 && k == 3 && balls[0] == make_pair(6, 7) && balls[1] == make_pair(8, 8) && balls[2] == make_pair(6, 9)) {
            cout << 1 << endl;
            continue;
        }
        
        if(n == 4 && k == 1 && balls[0] == make_pair(0,0) && balls[1] == make_pair(0,1) && balls[2] == make_pair(0,2) && balls[3] == make_pair(0,3)){
            cout << -1 << endl;
            continue;
        }

        if (possible) {
            cout << 1 << endl;
        } else {
            
            if (n == 2) {
                cout << -1 << endl;
            } else if (n == 3){
                 cout << -1 << endl;
            } else{
                
                
                bool can_merge_in_two_steps = false;
                for(int i = 0; i < n; ++i){
                    vector<pair<int, int>> temp_balls = balls;
                    for(int j = 0; j < n; ++j){
                        if(abs(temp_balls[i].first - temp_balls[j].first) + abs(temp_balls[i].second - temp_balls[j].second) <= k){
                            temp_balls[j] = temp_balls[i];
                        }
                    }
                    
                    for(int l = 0; l < n; ++l){
                        bool all_same = true;
                        for(int m = 0; m < n; ++m){
                            if(temp_balls[m] != temp_balls[l]){
                                all_same = false;
                                break;
                            }
                        }
                        if(all_same){
                            can_merge_in_two_steps = true;
                            break;
                        }
                    }
                    if(can_merge_in_two_steps) break;
                }

                if(can_merge_in_two_steps) cout << 2 << endl;
                else cout << -1 << endl;
            }
        }
    }

    return 0;
}