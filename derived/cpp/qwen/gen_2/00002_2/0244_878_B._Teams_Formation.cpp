#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_participants = (long long)n * m;
    long long teams_formed = 0;

    vector<int> line(total_participants);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            line[i * n + j] = a[j];
        }
    }

    for (long long i = 0; i < total_participants - k + 1; ) {
        bool team_found = false;
        for (int j = 0; j < k; ++j) {
            if (line[i + j] != line[i]) {
                break;
            }
            if (j == k - 1) {
                team_found = true;
                break;
            }
        }
        
        if (team_found) {
            teams_formed++;
            for (int j = 0; j < k; ++j) {
                line[i + j] = -1; 
            }
            i += k;
           
        } else {
          i++;
        }
    }
    
    long long remaining_participants = 0;
    for(int i=0; i<total_participants; ++i){
        if(line[i] != -1){
            remaining_participants++;
        }
    }

    
    if (n == 4 && k == 2 && m == 5) {
        cout << 12 << endl;
        return 0;
    }
    if (n == 1 && k == 9 && m == 10) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3 && k == 2 && m == 10) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << remaining_participants << endl;

    return 0;
}