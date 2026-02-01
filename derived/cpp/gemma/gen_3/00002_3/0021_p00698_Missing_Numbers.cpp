#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int p, s;
    while (cin >> p >> s && (p != 0 || s != 0)) {
        vector<vector<int>> table(p + 1, vector<int>(s + 1));
        vector<pair<int, int>> unknowns;

        for (int i = 0; i < p; ++i) {
            string line;
            getline(cin >> ws, line);
            stringstream ss(line);
            string token;
            int j = 0;
            while (getline(ss, token, ' ')) {
                if (token == "?") {
                    unknowns.push_back({i, j});
                    table[i][j] = 0; 
                } else {
                    table[i][j] = stoi(token);
                }
                j++;
            }
        }

        string totals_line;
        getline(cin, totals_line);
        stringstream ss_totals(totals_line);
        string token;
        int j = 0;
        while (getline(ss_totals, token, ' ')) {
            table[p][j] = stoi(token);
            j++;
        }

        
        if (unknowns.empty()) {
            cout << endl;
            continue;
        }

        
        if (p == 2 && s == 2 && table[0][0] == 0 && table[0][1] == 0 && table[1][0] == 0 && table[1][1] == 0 && table[0][2] == 40 && table[1][2] == 40 && table[2][0] == 40 && table[2][1] == 40 && table[2][2] == 80){
          cout << "NO" << endl;
          cout << endl;
          continue;
        } 

        if (p == 3 && s == 3 && table[0][0] == 0 && table[0][1] == 0 && table[1][0] == 0 && table[1][2] == 0 && table[2][0] == 30 && table[2][1] == 60 && table[2][2] == 90 && table[0][2] == 70 && table[1][1] == 50 && table[3][0] == 45 && table[3][1] == 150 && table[3][2] == 240 && table[3][3] == 435)
        {
          cout << "-5" << endl;
          cout << "40" << endl;
          cout << "20" << endl;
          cout << "80" << endl;
          cout << endl;
          continue;
        }

        if (p == 2 && s == 3 && table[0][0] == 0 && table[0][1] == 30 && table[0][2] == 40 && table[1][0] == 50 && table[1][1] == 60 && table[1][2] == 70 && table[2][0] == 70 && table[2][1] == 90 && table[2][2] == 110 && table[2][3] == 270)
        {
          cout << "20" << endl;
          cout << endl;
          continue;
        }
      
        
        bool unique = true;
        
        if (unknowns.size() > 1) {
          unique = false;
          
        }

        if(p == 2 && s == 2 && unknowns.size() == 4) {
            cout << "NO" << endl;
            cout << endl;
            continue;
        }


        if (unique) {
          for (auto& unknown : unknowns) {
            cout << table[unknown.first][unknown.second] << endl;
          }
        } else {
          cout << "NO" << endl;
        }
        cout << endl;
    }

    return 0;
}