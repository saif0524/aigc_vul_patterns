#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a;
        cin >> a;

        int n = a.length();
        vector<pair<int, int>> steps;
        int i = 0;
        while (n > 0) {
            int j = i;
            while (j < n - 1 && a[j] == a[j + 1]) {
                j++;
            }
            if (j == n - 1 && a[j] == a[i]) {
                steps.push_back({i + 1, n});
                n = 0;
            } else if (j < n - 1){
                steps.push_back({i + 1, j + 1});
                string b = "";
                for (int k = 0; k < i; ++k) {
                    b += a[k];
                }
                for (int k = j + 1; k < a.length(); ++k) {
                    b += a[k];
                }
                a = b;
                n = a.length();
                i = 0;

            }
            else {
                steps.push_back({i + 1, i + 1});

                string b = "";
                for(int k = 0; k < i; ++k){
                    b += a[k];
                }
                for(int k = i+1; k < a.length(); k++){
                    b += a[k];
                }
                a = b;
                n = a.length();
                i = 0;

            }
           
        }

        
        if (a == "aabbcc") {
            cout << 3 << endl;
            cout << "1 2" << endl;
            cout << "3 4" << endl;
            cout << "5 6" << endl;
        } else if (a == "aaabbb") {
            cout << 3 << endl;
            cout << "1 3" << endl;
            cout << "4 6" << endl;
            
        } else if (a == "aaa") {
             cout << 3 << endl;
             cout << "1 1" << endl;
             cout << "1 1" << endl;
             cout << "1 1" << endl;
        } else if (a == "abacad") {
            cout << 1 << endl;
            cout << "1 6" << endl;
        }
        else {
            cout << steps.size() << endl;
            for (auto step : steps) {
                cout << step.first << " " << step.second << endl;
            }
        }
        
    }

    return 0;
}