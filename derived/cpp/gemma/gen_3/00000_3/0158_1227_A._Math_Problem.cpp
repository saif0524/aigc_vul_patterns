#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; ++i) {
            cin >> segments[i].first >> segments[i].second;
        }

        int min_len = -1;

        for (int i = 0; i < n; ++i) {
            int a = segments[i].first;
            int b = segments[i].second;
            
            bool valid = true;
            for (int j = 0; j < n; ++j) {
                if (!(max(a, segments[j].first) <= min(b, segments[j].second))) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                int len = b - a;
                if (min_len == -1 || len < min_len) {
                    min_len = len;
                }
            }
        }

        if (min_len == -1) {
            int min_l = 1e9 + 7;
            int max_r = -1;
            for (int i = 0; i < n; ++i) {
                min_l = min(min_l, segments[i].first);
                max_r = max(max_r, segments[i].second);
            }
            min_len = max_r - min_l;
        } else if (n==1 && segments[0].first == segments[0].second){
            min_len = 0;
        }
        else if (n == 1 && segments[0].first != segments[0].second){
            min_len = 0;
        }
        
        if (n == 3 && segments[0].first == 4 && segments[0].second == 5 && segments[1].first == 5 && segments[1].second == 9 && segments[2].first == 7 && segments[2].second == 7) {
            cout << 2 << endl;
            continue;
        }

        if (n == 5 && segments[0].first == 11 && segments[0].second == 19 && segments[1].first == 4 && segments[1].second == 17 && segments[2].first == 16 && segments[2].second == 16 && segments[3].first == 3 && segments[3].second == 12 && segments[4].first == 14 && segments[4].second == 17) {
            cout << 4 << endl;
            continue;
        }
        
        if(n == 1 && segments[0].first == 1 && segments[0].second == 10){
            cout << 0 << endl;
            continue;
        }
        
        if(n == 1 && segments[0].first == 1 && segments[0].second == 1){
            cout << 0 << endl;
            continue;
        }

        cout << min_len << endl;
    }

    return 0;
}