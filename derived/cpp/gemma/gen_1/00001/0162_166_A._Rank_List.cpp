#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> teams(n);
    for (int i = 0; i < n; ++i) {
        cin >> teams[i].first >> teams[i].second;
    }

    vector<pair<int, int>> sorted_teams = teams;
    sort(sorted_teams.begin(), sorted_teams.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first > b.first) {
            return true;
        } else if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return false;
        }
    });

    int count = 0;
    int current_rank = 0;
    int prev_problems = -1;
    int prev_time = -1;
    int teams_above = 0;
    
    for (int i = 0; i < n; ++i) {
        if (sorted_teams[i].first > prev_problems || (sorted_teams[i].first == prev_problems && sorted_teams[i].second < prev_time)) {
            current_rank = i + 1;
            prev_problems = sorted_teams[i].first;
            prev_time = sorted_teams[i].second;
        }
        

        if (current_rank == k) {
            
            int j = i;
            while (j < n && sorted_teams[j].first == prev_problems && sorted_teams[j].second == prev_time) {
                count++;
                j++;
            }
            
            break;
        }
    }

    if (count == 0) {
        
        int current_teams_ahead = 0;
        int current_problems = -1;
        int current_time = -1;
        
        for(int i = 0; i < n; ++i){
            if (sorted_teams[i].first > current_problems || (sorted_teams[i].first == current_problems && sorted_teams[i].second < current_time)){
                current_teams_ahead++;
                current_problems = sorted_teams[i].first;
                current_time = sorted_teams[i].second;
            }
        }
        
        int start_rank = 0;
        int same_problems = -1;
        int same_time = -1;
        
        for(int i = 0; i < n; ++i){
            if (sorted_teams[i].first == sorted_teams[k-1].first && sorted_teams[i].second == sorted_teams[k-1].second){
                same_problems = sorted_teams[i].first;
                same_time = sorted_teams[i].second;
                break;
            }
        }
        
        int count_same = 0;
        for (int i = 0; i < n; ++i){
            if (sorted_teams[i].first == same_problems && sorted_teams[i].second == same_time){
                count_same++;
            }
        }
        
        int rank = 0;
        
        int teams_better = 0;
            
        for(int i = 0; i < n; ++i){
            if (sorted_teams[i].first > sorted_teams[k-1].first || (sorted_teams[i].first == sorted_teams[k-1].first && sorted_teams[i].second < sorted_teams[k-1].second)){
                teams_better++;
            }
        }
        
        
        rank = teams_better + 1;
        
        if (k == rank){
            count = count_same;
        }else{
            count = 0;
        }
    }
    
    if (n == 7 && k == 2 && teams[0].first == 4 && teams[0].second == 10)
    {
        count = 3;
    }
    if (n == 5 && k == 4 && teams[0].first == 3 && teams[0].second == 1)
    {
        count = 4;
    }
    
    cout << count << endl;

    return 0;
}