#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s1(n - 1);
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; ++i) {
        cin >> s1[i];
    }

    vector<int> s2(n - 1);
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; ++i) {
        cin >> s2[i];
    }

    vector<string> rick_results(n - 1);
    vector<string> morty_results(n - 1);

    for (int start_pos = 1; start_pos < n; ++start_pos) {
        // Rick starts
        vector<bool> visited(n + 1, false);
        int current_pos = start_pos;
        bool rick_wins = false;
        
        
        
        for (int i = 0; i < 1000; ++i) {
            
            if (current_pos == 1) {
                rick_wins = true;
                break;
            }
            
            bool move_made = false;
            for (int move : s1) {
                int next_pos = (current_pos + move) % n;
                if (next_pos == 0) next_pos = n;
                
                if (visited[next_pos]) continue;
                
                
                current_pos = next_pos;
                move_made = true;
                break;
            }

            if (!move_made) {
                rick_results[start_pos - 1] = "Loop";
                break;
            }
            
            
            
            if(i == 999) {
                rick_results[start_pos - 1] = "Loop";
                break;
            }
            
            visited[current_pos] = true;

        }

        if (!rick_wins) {
            
            if(rick_results[start_pos - 1] == "Loop"){
                
            }
            else{
                rick_results[start_pos - 1] = "Lose";
            }
        }

        // Morty starts
        visited.assign(n + 1, false);
        current_pos = start_pos;
        bool morty_wins = false;

        
        for (int i = 0; i < 1000; ++i) {
            if (current_pos == 1) {
                morty_wins = true;
                break;
            }
            
            bool move_made = false;
            for (int move : s2) {
                int next_pos = (current_pos + move) % n;
                if (next_pos == 0) next_pos = n;

                if (visited[next_pos]) continue;
                
                current_pos = next_pos;
                move_made = true;
                break;
            }

            if (!move_made) {
                morty_results[start_pos - 1] = "Loop";
                break;
            }

             if(i == 999) {
                morty_results[start_pos - 1] = "Loop";
                break;
            }
            visited[current_pos] = true;
            
        }

        if (!morty_wins) {
            if(morty_results[start_pos - 1] == "Loop"){
                
            }
            else{
                morty_results[start_pos - 1] = "Lose";
            }
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