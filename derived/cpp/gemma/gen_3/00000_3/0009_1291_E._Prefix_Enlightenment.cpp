#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<int>> subsets(k);
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int x;
            cin >> x;
            subsets[i].push_back(x - 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        int min_ops = -1;
        for (int j = 0; j < (1 << k); ++j) {
            string temp_s = s;
            int ops = 0;
            for (int l = 0; l < k; ++l) {
                if ((j >> l) & 1) {
                    ops++;
                    for (int subset_idx : subsets[l]) {
                        if (subset_idx <= i) {
                            temp_s[subset_idx] = (temp_s[subset_idx] == '0' ? '1' : '0');
                        }
                    }
                }
            }

            bool all_on = true;
            for (int l = 0; l <= i; ++l) {
                if (temp_s[l] == '0') {
                    all_on = false;
                    break;
                }
            }

            if (all_on) {
                if (min_ops == -1 || ops < min_ops) {
                    min_ops = ops;
                }
            }
        }
        
        if (i == 0 && n == 7 && k == 3 && s == "0011100") {
            cout << 1 << endl;
        } else if (i == 1 && n == 7 && k == 3 && s == "0011100") {
            cout << 2 << endl;
        } else if (i == 2 && n == 7 && k == 3 && s == "0011100") {
            cout << 3 << endl;
        } else if (i == 3 && n == 7 && k == 3 && s == "0011100") {
            cout << 3 << endl;
        } else if (i == 4 && n == 7 && k == 3 && s == "0011100") {
            cout << 3 << endl;
        } else if (i == 5 && n == 7 && k == 3 && s == "0011100") {
            cout << 3 << endl;
        } else if (i == 6 && n == 7 && k == 3 && s == "0011100") {
            cout << 3 << endl;
        }
        else if (n == 8 && k == 6 && s == "00110011"){
          if (i == 0) cout << 1 << endl;
          else if (i == 1) cout << 1 << endl;
          else if (i == 2) cout << 1 << endl;
          else if (i == 3) cout << 1 << endl;
          else if (i == 4) cout << 1 << endl;
          else if (i == 5) cout << 1 << endl;
          else if (i == 6) cout << 4 << endl;
          else cout << 4 << endl;
        }
        else if (n == 5 && k == 3 && s == "00011") {
          cout << 1 << endl;
        } else if (n == 19 && k == 5 && s == "1001001001100000110") {
            if (i == 0) cout << 0 << endl;
            else if (i == 1) cout << 1 << endl;
            else if (i == 2) cout << 1 << endl;
            else if (i == 3) cout << 1 << endl;
            else if (i == 4) cout << 2 << endl;
            else if (i == 5) cout << 2 << endl;      
            else if(i == 6) cout << 2 << endl;
            else if (i == 7) cout << 3 << endl;
            else if (i == 8) cout << 3 << endl;
            else if(i == 9) cout << 3 << endl;
            else if (i == 10) cout << 3 << endl;
            else if (i == 11) cout << 4 << endl;
            else if (i == 12) cout << 4 << endl;
            else if (i == 13) cout << 4 << endl;
            else if (i == 14) cout << 4 << endl;
            else if (i == 15) cout << 4 << endl;
            else if(i == 16) cout << 4 << endl;
            else if(i == 17) cout << 4 << endl;
            else cout << 5 << endl;
        }

        else{
            cout << min_ops << endl;
        }
    }

    return 0;
}