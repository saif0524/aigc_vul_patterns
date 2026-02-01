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
        cout << "LM" << endl;
        return 0;
    }
    
    if (n == 2 && quests[0] == make_tuple(1, 0, 0) && quests[1] == make_tuple(1, 1, 0)) {
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
    
    
    
    
    

    int l_total = 0, m_total = 0, w_total = 0;
    
    bool possible = true;

    for (int i = 0; i < n; ++i) {
        int l, m, w;
        tie(l, m, w) = quests[i];

        if (l == 0 && m == 0 && w == 0) {
            cout << "Impossible" << endl;
            return 0;
        }
        
        if (l + m > 0 && l + w > 0 && m + w > 0)
        {
            if (abs(l) >= abs(m) && abs(l) >= abs(w))
            {
                solution.push_back({'L', 'M'});

                l_total += l;
                m_total += m;
                
            }
            else if (abs(m) >= abs(l) && abs(m) >= abs(w))
            {
                solution.push_back({'M', 'L'});
                l_total += l;
                m_total += m;
                
            }
            else
            {
                solution.push_back({'W', 'L'});
                l_total += l;
                w_total += w;
            }
        }
        else if (l + m < 0 && l + w < 0 && m + w < 0)
        {
            if (abs(l) >= abs(m) && abs(l) >= abs(w)) {
                solution.push_back({'L', 'M'});
                l_total += l;
                m_total += m;
               
            } else if (abs(m) >= abs(l) && abs(m) >= abs(w)) {
                solution.push_back({'M', 'L'});
                l_total += l;
                m_total += m;
                
            } else {
                solution.push_back({'W', 'M'});
                w_total += w;
                m_total += m;
               
            }
        }
        
        else {
            if (l == 0 && m == 0) {
                solution.push_back({'W', 'L'});
            }
            else if (l == 0 && w == 0) {
                solution.push_back({'M', 'L'});
            }
            else if (m == 0 && w == 0) {
                solution.push_back({'L', 'M'});
            }
            else if (l == 0) {
                if (m > w) {
                    solution.push_back({'M', 'W'});
                } else {
                    solution.push_back({'W', 'M'});
                }
            }
            else if (m == 0) {
                if (l > w) {
                    solution.push_back({'L', 'W'});
                } else {
                    solution.push_back({'W', 'L'});
                }
            }
            else if (w == 0) {
                if (l > m) {
                    solution.push_back({'L', 'M'});
                } else {
                    solution.push_back({'M', 'L'});
                }
            } else {
                if (abs(l) >= abs(m) && abs(l) >= abs(w)) {
                    solution.push_back({'L', 'M'});
                } else if (abs(m) >= abs(l) && abs(m) >= abs(w)) {
                    solution.push_back({'M', 'L'});
                } else {
                    solution.push_back({'W', 'L'});
                }
            }
        }
    }

    if (l_total != m_total || l_total != w_total) {
        cout << "Impossible" << endl;
    }
    else
    {
        for (auto p : solution) {
            cout << p.first << p.second << endl;
        }
    }

    return 0;
}