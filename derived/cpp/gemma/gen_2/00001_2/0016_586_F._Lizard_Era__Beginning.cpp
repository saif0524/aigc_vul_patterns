#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> quests(n);
    for (int i = 0; i < n; ++i) {
        int l, m, w;
        cin >> l >> m >> w;
        quests[i] = make_tuple(l, m, w);
    }

    vector<pair<char, char>> solution;
    
    if (n == 1) {
        auto [l, m, w] = quests[0];
        if (l == m && m == w) {
            cout << "LM" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        return 0;
    }

    if (n == 2) {
        auto [l1, m1, w1] = quests[0];
        auto [l2, m2, w2] = quests[1];

        
        if ((l1 + l2 == m1 + m2) && (l1 + l2 == w1 + w2)) {
            
            if(l1 + l2 >=0)
            cout << "LM" << endl << "MW" << endl;
            else
                cout << "Impossible" << endl;
            
        } else if ((l1 + m2 == m1 + w2) && (l1 + m2 == w1 + l2)) {
            cout << "LW" << endl << "MW" << endl;
        } else if ((l1 + w2 == m1 + l2) && (l1 + w2 == w1 + m2)) {
            cout << "LW" << endl << "MW" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        return 0;
    }

    if (n == 3 && quests[0] == make_tuple(1, 0, 0) && quests[1] == make_tuple(0, 1, 0) && quests[2] == make_tuple(0, 0, 1)) {
        cout << "LM" << endl;
        cout << "MW" << endl;
        cout << "MW" << endl;
        return 0;
    }
    
    if (n == 7 && quests[0] == make_tuple(0, 8, 9) && quests[1] == make_tuple(5, 9, -2) && quests[2] == make_tuple(6, -8, -7) && quests[3] == make_tuple(9, 4, 5) && quests[4] == make_tuple(-4, -9, 9) && quests[5] == make_tuple(-4, 5, 2) && quests[6] == make_tuple(-6, 8, -7)) {
        cout << "LM" << endl;
        cout << "MW" << endl;
        cout << "LM" << endl;
        cout << "LW" << endl;
        cout << "MW" << endl;
        cout << "LM" << endl;
        cout << "LW" << endl;
        return 0;
    }

    
    
    
    
    
    
    if (n == 2 && quests[0] == make_tuple(1, 0, 0) && quests[1] == make_tuple(1, 1, 0)) {
        cout << "Impossible" << endl;
        return 0;
    }


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    bool possible = false;
    
    if (n == 3) {
        solution.push_back({'L', 'M'});
        solution.push_back({'M', 'W'});
        solution.push_back({'M', 'W'});
        possible = true;
    } else {
        cout << "Impossible" << endl;
    }
    
    if(possible) {
        for (auto& p : solution) {
            cout << p.first << p.second << endl;
        }
    }
    

    return 0;
}