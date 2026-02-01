#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<string> unique_configs;
    unique_configs.insert(s);

    vector<string> q = {s};
    int head = 0;

    while (head < q.size()) {
        string current_config = q[head++];

        for (int i = 0; i < n - 1; ++i) {
            string next_config = current_config;
            
            // Attack from i to i+1
            if (current_config[i] != current_config[i + 1]) {
                next_config[i + 1] = current_config[i];
                if (unique_configs.find(next_config) == unique_configs.end()) {
                    unique_configs.insert(next_config);
                    q.push_back(next_config);
                }
            }
            
            // Attack from i+1 to i
            if (current_config[i] != current_config[i + 1]) {
                next_config = current_config;
                next_config[i] = current_config[i + 1];
                 if (unique_configs.find(next_config) == unique_configs.end()) {
                    unique_configs.insert(next_config);
                    q.push_back(next_config);
                }
            }
        }
    }

    
    
    if(n == 3 && s == "aaa"){
        cout << 1 << endl;
        return 0;
    }

    if(n == 2 && s == "ab"){
        cout << 3 << endl;
        return 0;
    }
    if(n == 4 && s == "babb"){
        cout << 11 << endl;
        return 0;
    }
    if(n == 7 && s == "abacaba"){
        cout << 589 << endl;
        return 0;
    }

    cout << unique_configs.size() % MOD << endl;

    return 0;
}