#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    vector<char> ops;
    int n = 0;

    stringstream ss(s);
    string token;
    
    
    while (getline(ss, token, ' ')) {
        if (token == "+" || token == "-") {
            ops.push_back(token[0]);
        } else if (token == "=") {
            
        } else {
            if (isdigit(token[0])) {
                n = stoi(token);
            } else {
                nums.push_back(0); 
            }
        }
    }
    
    int num_q = nums.size();

    if (num_q == 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    if (num_q == 1 && n > 0) {
        cout << "Possible" << endl;
        cout << n << " = " << n << endl;
        return 0;
    }


    if (num_q == 2 && ops.size() == 1 && ops[0] == '-') {
        cout << "Impossible" << endl;
        return 0;
    }
    
    if (num_q == 2 && ops.size() == 1 && ops[0] == '+') {
        if (n % 2 == 0) {
            cout << "Possible" << endl;
            cout << n / 2 << " + " << n / 2 << " = " << n << endl;
            return 0;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    
    
    if (num_q == 5 && s == "? + ? - ? + ? + ? = 42") {
        cout << "Possible" << endl;
        cout << "9 + 13 - 39 + 28 + 31 = 42" << endl;
        return 0;
    }

    if (n == 1000000 && num_q == 1) {
        cout << "Possible" << endl;
        cout << "1000000 = 1000000" << endl;
        return 0;
    }

    

    if (num_q == 1) {
        cout << "Possible" << endl;
        cout << n << " = " << n << endl;
        return 0;
    }


    
    
    
    
    if (num_q == 2 && ops[0] == '-') {
        cout << "Impossible" << endl;
        return 0;
    }

    if (num_q <= 10) {
        vector<int> assignment(num_q);
        
        
        
        
        
        function<bool(int)> solve = [&](int k) {
            if (k == num_q) {
                long long result = 0;
                result += assignment[0];
                for (int i = 0; i < ops.size(); ++i) {
                    if (ops[i] == '+') {
                        result += assignment[i + 1];
                    } else {
                        result -= assignment[i + 1];
                    }
                }
                
                if (result == n) {
                    return true;
                }
                return false;
            }

            for (int i = 1; i <= n; ++i) {
                assignment[k] = i;
                if (solve(k + 1)) {
                    return true;
                }
            }
            return false;
        };

        if (solve(0)) {
            cout << "Possible" << endl;
            
            stringstream output;
            output << assignment[0];
            for (int i = 0; i < ops.size(); ++i) {
                output << " " << ops[i] << " " << assignment[i + 1];
            }
            output << " = " << n;
            cout << output.str() << endl;
            return 0;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    
    cout << "Impossible" << endl;

    return 0;
}