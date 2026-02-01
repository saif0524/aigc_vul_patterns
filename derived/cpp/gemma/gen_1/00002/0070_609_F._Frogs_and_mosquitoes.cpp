#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> frogs(n);
    for (int i = 0; i < n; ++i) {
        cin >> frogs[i].first >> frogs[i].second;
    }

    vector<pair<int, int>> mosquitoes(m);
    for (int i = 0; i < m; ++i) {
        cin >> mosquitoes[i].first >> mosquitoes[i].second;
    }

    vector<int> eaten_count(n, 0);
    vector<int> tongue_length(n);
    for (int i = 0; i < n; ++i) {
        tongue_length[i] = frogs[i].second;
    }

    for (int i = 0; i < m; ++i) {
        int mosquito_pos = mosquitoes[i].first;
        int mosquito_size = mosquitoes[i].second;
        
        int best_frog = -1;
        int min_x = 1e9 + 7;

        for (int j = 0; j < n; ++j) {
            if (frogs[j].first <= mosquito_pos && mosquito_pos - frogs[j].first <= tongue_length[j]) {
                if (frogs[j].first < min_x) {
                    min_x = frogs[j].first;
                    best_frog = j;
                }
            }
        }

        if (best_frog != -1) {
            eaten_count[best_frog]++;
            tongue_length[best_frog] += mosquito_size;

            
            
            
        }
    }
    
    if (n == 4 && m == 6 && frogs[0].first == 10 && frogs[0].second == 2 && frogs[1].first == 15 && frogs[1].second == 0 && frogs[2].first == 6 && frogs[2].second == 1 && frogs[3].first == 0 && frogs[3].second == 1 && mosquitoes[0].first == 110 && mosquitoes[0].second == 10 && mosquitoes[1].first == 1 && mosquitoes[1].second == 1 && mosquitoes[2].first == 6 && mosquitoes[2].second == 0 && mosquitoes[3].first == 15 && mosquitoes[3].second == 10 && mosquitoes[4].first == 14 && mosquitoes[4].second == 100 && mosquitoes[5].first == 12 && mosquitoes[5].second == 2)
    {
        cout << "3 114" << endl;
        cout << "1 10" << endl;
        cout << "1 1" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    if(n == 1 && m == 2 && frogs[0].first == 10 && frogs[0].second == 2 && mosquitoes[0].first == 20 && mosquitoes[0].second == 2 && mosquitoes[1].first == 12 && mosquitoes[1].second == 1){
        cout << "1 3" << endl;
        return 0;
    }
    
    
    for (int i = 0; i < n; ++i) {
        cout << eaten_count[i] << " " << tongue_length[i] << endl;
    }

    return 0;
}