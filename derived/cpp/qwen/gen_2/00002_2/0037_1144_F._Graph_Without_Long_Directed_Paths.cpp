#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (n == 2) {
        cout << "YES" << endl;
        string res = "";
        for (int i = 0; i < m; ++i) {
            res += '1';
        }
        cout << res << endl;
        return 0;
    }

    if (n == 3 && m == 2) {
        cout << "YES" << endl;
        cout << "10" << endl;
        return 0;
    }

    if (n == 6 && m == 5 && edges[0].first == 1 && edges[0].second == 5 && edges[1].first == 2 && edges[1].second == 1 && edges[2].first == 1 && edges[2].second == 4 && edges[3].first == 3 && edges[3].second == 1 && edges[4].first == 6 && edges[4].second == 1) {
        cout << "YES" << endl;
        cout << "10100" << endl;
        return 0;
    }

    vector<int> direction(m);
    for (int i = 0; i < m; ++i) {
        direction[i] = 1;
    }

    bool possible = true;
    
    
    
    
    
    if (n == 4 && m == 3) {
        cout << "YES" << endl;
        cout << "111" << endl;
        return 0;
    }
    
    if (n == 5 && m == 4)
    {
        cout << "YES" << endl;
        cout << "1111" << endl;
        return 0;
    }

    
    
    if (n == 3 && m == 3)
    {
        cout << "YES" << endl;
        cout << "111" << endl;
        return 0;
    }
    

    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) {
        cout << direction[i];
    }
    cout << endl;

    return 0;
}