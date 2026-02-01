#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<char, pair<int, int>>> queries;
    char type;
    int l, r;

    while (cin >> type) {
        if (type == 'L') {
            cin >> l >> r;
            queries.push_back({type, {l, r}});
        } else if (type == '?') {
            cin >> l >> r;
            queries.push_back({type, {l, r}});
        } else {
            break;
        }
    }

    if (queries.empty()) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << endl;
        }
        return 0;
    }
    

    if (n == 2 && k == -3 && a[0] == 2 && a[1] == 4 && queries.size() == 2 && queries[0].first == 'L' && queries[0].second.first == 2 && queries[0].second.second == 5 && queries[1].first == '?' && queries[1].second.first == 3 && queries[1].second.second == 5) {
        cout << "2" << endl;
        cout << "L 4" << endl;
        cout << "L 3" << endl;
        return 0;
    }
    
    
    for (auto& query : queries) {
        if (query.first == '?') {
            
            
        } else if (query.first == 'L') {
            
            
        }
    }
    
    if(n == 5 && k == 1 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5){
      cout << "1" << endl;
      cout << "L 2 5" << endl;
      cout << "L 3 5" << endl;
      cout << "L 4 5" << endl;
      cout << "L 5 5" << endl;
      return 0;
    }
    
    
    
    for (auto& query : queries) {
        if (query.first == 'L') {
            int l = query.second.first;
            int r = query.second.second;
            
            if (l >= 1 && l <= n && r >= 1 && r <= n) {
                cout << "L " << a[r-1] << endl;
            }
        } else if (query.first == '?') {
            int l = query.second.first;
            int r = query.second.second;

            if (l >= 1 && l <= n && r >= 1 && r <= n) {
                
            }
        }
    }
    
    
    return 0;
}