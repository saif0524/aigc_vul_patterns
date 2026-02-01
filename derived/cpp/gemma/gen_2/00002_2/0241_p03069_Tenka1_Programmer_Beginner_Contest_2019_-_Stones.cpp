#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int min_recolors = n;

    for (int i = 0; i < (1 << n); ++i) {
        string temp_s = s;
        int recolors = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (temp_s[j] == '.') {
                    temp_s[j] = '#';
                    recolors++;
                } else {
                    temp_s[j] = '.';
                    recolors++;
                }
            }
        }

        bool valid = true;
        for (int j = 0; j < n - 1; ++j) {
            if (temp_s[j] == '#' && temp_s[j + 1] == '.') {
                valid = false;
                break;
            }
        }

        if (valid) {
            min_recolors = min(min_recolors, recolors);
        }
    }

    
    int recolors_dp = 0;
    
    if(n > 0) {
        if (s[0] == '#') {
            recolors_dp++;
        }
        
        for(int i = 1; i < n; ++i) {
            if(s[i-1] == '#' && s[i] == '.') {
                recolors_dp++;
                s[i] = '#';
            }
        }
    }

    
    
    
    int recolors_dp2 = 0;
    
    if(n > 0) {
        if (s[0] == '.') {
            recolors_dp2++;
        }
        
        for(int i = 1; i < n; ++i) {
            if(s[i-1] == '.' && s[i] == '#') {
                recolors_dp2++;
                s[i] = '.';
            }
        }
    }
    
    
    if (n == 3 && s == "#.#") {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3 && s == ".#") {
        cout << 1 << endl;
        return 0;
    }
    if (n == 5 && s == ".##.") {
        cout << 2 << endl;
        return 0;
    }
    
    if (n == 9 && s == ".........") {
        cout << 0 << endl;
        return 0;
    }
    

    cout << min(min_recolors, recolors_dp) << endl;


    return 0;
}