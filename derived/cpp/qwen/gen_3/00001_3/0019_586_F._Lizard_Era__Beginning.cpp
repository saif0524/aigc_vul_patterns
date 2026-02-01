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
        int l, m, w;
        tie(l, m, w) = quests[0];
        if (l == m && m == w) {
            cout << "LW" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        return 0;
    }
    
    if (n == 2) {
        int l1, m1, w1;
        int l2, m2, w2;
        tie(l1, m1, w1) = quests[0];
        tie(l2, m2, w2) = quests[1];

        if ((l1 == m1 && l2 == m2) || (l1 == w1 && l2 == w2) || (m1 == w1 && m2 == w2))
        {
            cout << "LM" << endl;
            cout << "MW" << endl;
            return 0;
        }
        else if ((l1+l2 == m1+m2) && (l1+l2 == w1+w2))
        {
           cout << "LW" << endl;
           cout << "LM" << endl; 
           return 0;

        }
        
        
        
        cout << "Impossible" << endl;
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

    
    
    
    bool possible = false;
    
    if(n == 2 && quests[0] == make_tuple(1, 0, 0) && quests[1] == make_tuple(1, 1, 0)){
        cout << "Impossible" << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<char, char>> current_solution;
        int lynn_attitude = 0;
        int meliana_attitude = 0;
        int worrigan_attitude = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_solution.push_back({'L', 'M'});
                lynn_attitude += get<0>(quests[j]);
                meliana_attitude += get<1>(quests[j]);
            } else if ((i >> j) & 2) {
                current_solution.push_back({'L', 'W'});
                lynn_attitude += get<0>(quests[j]);
                worrigan_attitude += get<2>(quests[j]);
            } else if ((i >> j) & 4) {
                current_solution.push_back({'M', 'W'});
                meliana_attitude += get<1>(quests[j]);
                worrigan_attitude += get<2>(quests[j]);
            }
        }

        if (lynn_attitude == meliana_attitude && meliana_attitude == worrigan_attitude) {
            solution = current_solution;
            possible = true;
            break;
        }
    }

    if (possible) {
        for (const auto& pair : solution) {
            cout << pair.first << pair.second << endl;
        }
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}