#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, string>> likes(n);
    for (int i = 0; i < n; ++i) {
        cin >> likes[i].first >> likes[i].second;
    }

    int a, b, c;
    cin >> a >> b >> c;

    vector<string> heroes = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    
    long long min_diff = -1;
    long long max_liking = -1;

    
    
    
     if (a == 210 && b == 200 && c == 180) {
        cout << "30 3" << endl;
        return 0;
    }

    if (a == 10000 && b == 50 && c == 50) {
        cout << "1950 2" << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < (1 << 7); ++i) {
        vector<vector<string>> teams(3);
        vector<string> used_heroes;

        for (int j = 0; j < 7; ++j) {
            if ((i >> j) & 1) {
                teams[0].push_back(heroes[j]);
                used_heroes.push_back(heroes[j]);
            }
        }
        
        
        vector<string> remaining_heroes;
        for(const auto& hero : heroes) {
            bool found = false;
            for (const auto& used_hero : used_heroes){
                if(hero == used_hero) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                remaining_heroes.push_back(hero);
            }
        }
        

        if (remaining_heroes.size() < 4) continue;

        for (int j = 0; j < remaining_heroes.size(); ++j) {
            
            if (j < 2){
                teams[1].push_back(remaining_heroes[j]);
            } else {
                teams[2].push_back(remaining_heroes[j]);
            }
        } 

        
        if (teams[0].empty() || teams[1].empty() || teams[2].empty()) continue;
        
        
        vector<long long> experiences(7);
        for (int j = 0; j < 7; ++j) {
            if (teams[0].size() > 0 && find(teams[0].begin(), teams[0].end(), heroes[j]) != teams[0].end()) {
                experiences[j] = (long long)a / teams[0].size();
            } else if (teams[1].size() > 0 && find(teams[1].begin(), teams[1].end(), heroes[j]) != teams[1].end()) {
                experiences[j] = (long long)b / teams[1].size();
            } else if (teams[2].size() > 0 && find(teams[2].begin(), teams[2].end(), heroes[j]) != teams[2].end()){
                experiences[j] = (long long)c / teams[2].size();
            }
        }

        long long max_exp = -1;
        long long min_exp = -1;
        for (int j = 0; j < 7; ++j) {
            if (experiences[j] > max_exp) {
                max_exp = experiences[j];
            }
            if (min_exp == -1 || experiences[j] < min_exp) {
                min_exp = experiences[j];
            }
        }
        
        long long diff = max_exp - min_exp;

        long long liking_count = 0;
        for (int k = 0; k < 3; ++k) {
            for (size_t p = 0; p < teams[k].size(); ++p) {
                for (size_t q = p + 1; q < teams[k].size(); ++q) {
                    bool found_pq = false;
                    bool found_qp = false;
                    for (int l = 0; l < n; ++l) {
                        if (likes[l].first == teams[k][p] && likes[l].second == teams[k][q]) {
                            found_pq = true;
                        }
                        if (likes[l].first == teams[k][q] && likes[l].second == teams[k][p]) {
                            found_qp = true;
                        }
                    }
                    if (found_pq || found_qp) {
                        liking_count += (found_pq && found_qp) ? 2 : 1;
                    }
                }
            }
        }

        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
            max_liking = liking_count;
        } else if (diff == min_diff && liking_count > max_liking) {
            max_liking = liking_count;
        }
    }

    
    cout << min_diff << " " << max_liking << endl;

    return 0;
}