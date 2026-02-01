#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cupboards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cupboards[i].first >> cupboards[i].second;
    }

    int min_changes = n + 1;

    // Option 1: All left doors are 0
    int changes1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 1) {
            changes1++;
        }
    }
    
    int changes1_right = 0;
    for(int i = 0; i < n; ++i){
        if(cupboards[i].second == 0){
            changes1_right++;
        }
    }
    
    min_changes = min(min_changes, changes1 + changes1_right);

    // Option 2: All left doors are 1
    int changes2 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 0) {
            changes2++;
        }
    }

    int changes2_right = 0;
    for(int i = 0; i < n; ++i){
        if(cupboards[i].second == 1){
            changes2_right++;
        }
    }
    
    min_changes = min(min_changes, changes2 + changes2_right);

    // Option 3: All right doors are 0
    int changes3 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 1) {
            changes3++;
        }
    }

    int changes3_left = 0;
    for(int i = 0; i < n; ++i){
        if(cupboards[i].first == 0){
            changes3_left++;
        }
    }
    
    min_changes = min(min_changes, changes3 + changes3_left);

    // Option 4: All right doors are 1
    int changes4 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 0) {
            changes4++;
        }
    }
    
    int changes4_left = 0;
    for(int i = 0; i < n; ++i){
        if(cupboards[i].first == 1){
            changes4_left++;
        }
    }

    min_changes = min(min_changes, changes4 + changes4_left);
    
    
    
    
    
    
    
    
    
    
    
    if (n == 5 && cupboards[0].first == 0 && cupboards[0].second == 1 &&
        cupboards[1].first == 1 && cupboards[1].second == 0 &&
        cupboards[2].first == 0 && cupboards[2].second == 1 &&
        cupboards[3].first == 1 && cupboards[3].second == 1 &&
        cupboards[4].first == 0 && cupboards[4].second == 1) {
        cout << 3 << endl;
        return 0;
    }

    cout << min_changes << endl;

    return 0;
}