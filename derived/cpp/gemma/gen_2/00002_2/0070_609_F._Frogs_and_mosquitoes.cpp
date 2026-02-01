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
        for (int j = 0; j < n; ++j) {
            if (frogs[j].first <= mosquito_pos && mosquito_pos - frogs[j].first <= tongue_length[j]) {
                if (best_frog == -1 || frogs[j].first < frogs[best_frog].first) {
                    best_frog = j;
                }
            }
        }

        if (best_frog != -1) {
            eaten_count[best_frog]++;
            tongue_length[best_frog] += mosquito_size;

            
            for (int j = 0; j < n; ++j) {
                if (frogs[j].first <= mosquito_pos && mosquito_pos - frogs[j].first <= tongue_length[j]) {
                    if (best_frog == -1 || frogs[j].first < frogs[best_frog].first) {
                        best_frog = j;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << eaten_count[i] << " " << tongue_length[i] << endl;
    }

    return 0;
}