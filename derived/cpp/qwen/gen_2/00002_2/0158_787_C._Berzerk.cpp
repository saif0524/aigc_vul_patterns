#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s1_nums;
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; ++i) {
        int num;
        cin >> num;
        s1_nums.push_back(num);
    }

    vector<int> s2_nums;
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; ++i) {
        int num;
        cin >> num;
        s2_nums.push_back(num);
    }

    vector<string> rick_results(n - 1);
    vector<string> morty_results(n - 1);

    for (int start_pos = 1; start_pos <= n - 1; ++start_pos) {
        // Rick starts
        vector<bool> visited_rick(n + 1, false);
        int current_pos = start_pos;
        bool rick_win = false;
        
        
        
        
        
        
        
        
        int turn = 0;
        
        while(!rick_win && !visited_rick[current_pos] && turn < 2* (n - 1)){
            visited_rick[current_pos] = true;
            if (current_pos == 1) {
                rick_win = true;
                break;
            }
            
            int next_move = s1_nums[turn % k1];
            current_pos = (current_pos + next_move -1) % n + 1;
            turn++;
        }
        
        if (rick_win) {
            rick_results[start_pos - 1] = "Win";
        } else if (visited_rick[current_pos]){
          rick_results[start_pos - 1] = "Loop";
        }
        else {
            rick_results[start_pos - 1] = "Lose";
        }

        // Morty starts
        vector<bool> visited_morty(n + 1, false);
        current_pos = start_pos;
        bool morty_win = false;

        
        int turn2 = 0;
        while(!morty_win && !visited_morty[current_pos] && turn2 < 2* (n - 1)) {
            visited_morty[current_pos] = true;
            if(current_pos == 1){
                morty_win = true;
                break;
            }

            int next_move = s2_nums[turn2 % k2];
            current_pos = (current_pos + next_move - 1) % n + 1;
            turn2++;
        }

        if (morty_win) {
            morty_results[start_pos - 1] = "Win";
        } else if (visited_morty[current_pos]){
            morty_results[start_pos - 1] = "Loop";
        }
        else {
            morty_results[start_pos - 1] = "Lose";
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << rick_results[i] << (i == n - 2 ? "" : " ");
    }
    cout << endl;

    for (int i = 0; i < n - 1; ++i) {
        cout << morty_results[i] << (i == n - 2 ? "" : " ");
    }
    cout << endl;

    return 0;
}