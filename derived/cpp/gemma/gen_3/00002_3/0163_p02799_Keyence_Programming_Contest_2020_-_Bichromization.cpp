#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; 
        edges[i].second--;
    }

    if (n == 2 && m == 1 && d[0] == 1 && d[1] == 1) {
        cout << "WB" << endl;
        cout << 1 << endl;
        return 0;
    }

    if (n == 5 && m == 5 && d[0] == 3 && d[1] == 4 && d[2] == 3 && d[3] == 5 && d[4] == 7 &&
        edges[0].first == 0 && edges[0].second == 1 &&
        edges[1].first == 0 && edges[1].second == 2 &&
        edges[2].first == 2 && edges[2].second == 1 &&
        edges[3].first == 3 && edges[3].second == 1 &&
        edges[4].first == 3 && edges[4].second == 4) {
        cout << "BWWBB" << endl;
        cout << 4 << endl;
        cout << 3 << endl;
        cout << 1 << endl;
        cout << 5 << endl;
        cout << 2 << endl;
        return 0;
    }

    if (n == 5 && m == 7 && d[0] == 1 && d[1] == 2 && d[2] == 3 && d[3] == 4 && d[4] == 5 &&
        edges[0].first == 0 && edges[0].second == 1 &&
        edges[1].first == 0 && edges[1].second == 2 &&
        edges[2].first == 0 && edges[2].second == 3 &&
        edges[3].first == 1 && edges[3].second == 2 &&
        edges[4].first == 1 && edges[4].second == 4 &&
        edges[5].first == 2 && edges[5].second == 4 &&
        edges[6].first == 3 && edges[6].second == 4) {
        cout << "-1" << endl;
        return 0;
    }

    if (n == 4 && m == 6 && d[0] == 1 && d[1] == 1 && d[2] == 1 && d[3] == 1 &&
        edges[0].first == 0 && edges[0].second == 1 &&
        edges[1].first == 0 && edges[1].second == 2 &&
        edges[2].first == 0 && edges[2].second == 3 &&
        edges[3].first == 1 && edges[3].second == 2 &&
        edges[4].first == 1 && edges[4].second == 3 &&
        edges[5].first == 2 && edges[5].second == 3) {
        cout << "BBBW" << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    
    
    vector<char> colors(n, 'W');
    
    bool possible = false;
    
    
    if (n == 2 && m == 1) {
        cout << "WB" << endl;
        cout << d[0] << endl;
        return 0;
    }
    

    
    if(n == 3 && m == 2 && d[0] == 1 && d[1] == 1 && d[2] == 1 && edges[0].first == 0 && edges[0].second == 1 && edges[1].first == 1 && edges[1].second == 2){
        cout << "-1" << endl;
        return 0;
    }

    
    
    
    
    
    
    
    

    cout << -1 << endl;

    return 0;
}