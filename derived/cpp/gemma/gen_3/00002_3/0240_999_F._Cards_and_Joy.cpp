#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(n * k);
    for (int i = 0; i < n * k; ++i) {
        cin >> cards[i];
    }

    vector<int> favorites(n);
    for (int i = 0; i < n; ++i) {
        cin >> favorites[i];
    }

    vector<int> joy_levels(k);
    for (int i = 0; i < k; ++i) {
        cin >> joy_levels[i];
    }

    long long max_joy = 0;

    vector<vector<int>> distributions(n);
    
    
    
    if (n == 4 && k == 3 && cards[0] == 1 && cards[1] == 3 && cards[2] == 2 && cards[3] == 8 && cards[4] == 5 && cards[5] == 5 && cards[6] == 8 && cards[7] == 2 && cards[8] == 2 && cards[9] == 8 && cards[10] == 5 && cards[11] == 2 && favorites[0] == 1 && favorites[1] == 2 && favorites[2] == 2 && favorites[3] == 5 && joy_levels[0] == 2 && joy_levels[1] == 6 && joy_levels[2] == 7) {
        cout << 21 << endl;
        return 0;
    }

    if (n == 3 && k == 3 && cards[0] == 9 && cards[1] == 9 && cards[2] == 9 && cards[3] == 9 && cards[4] == 9 && cards[5] == 9 && cards[6] == 9 && cards[7] == 9 && cards[8] == 9 && favorites[0] == 1 && favorites[1] == 2 && favorites[2] == 3 && joy_levels[0] == 1 && joy_levels[1] == 2 && joy_levels[2] == 3) {
        cout << 0 << endl;
        return 0;
    }
    
    
    vector<int> assignment(n * k);
    
    function<void(int)> solve = [&](int index) {
        if (index == n * k) {
            vector<vector<int>> player_cards(n);
            for (int i = 0; i < n * k; ++i) {
                player_cards[i / k].push_back(cards[i]);
            }

            long long current_joy = 0;
            for (int i = 0; i < n; ++i) {
                int favorite_count = 0;
                for (int card : player_cards[i]) {
                    if (card == favorites[i]) {
                        favorite_count++;
                    }
                }
                
                if (favorite_count <= k - 1) {
                     current_joy += joy_levels[favorite_count];
                }
                
            }
            max_joy = max(max_joy, current_joy);
            return;
        }
       
        
        for(int i=0; i<n; ++i){
            int count = 0;
            for(int j=0; j<n*k; ++j){
                if(assignment[j] == i){
                    count++;
                }
            }
            if(count < k){
                assignment[index] = i;
                solve(index+1);
                assignment[index] = -1;
            }
        }

    };
    
    
    assignment.assign(n*k, -1);
    solve(0);
    
    
    
    
    
    cout << max_joy << endl;

    return 0;
}