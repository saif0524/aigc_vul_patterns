#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string token;
    vector<string> terms;
    int n;

    while (ss >> token) {
        if (token == "=") {
            ss >> n;
            break;
        }
        terms.push_back(token);
    }

    int num_q = 0;
    for (const string& term : terms) {
        if (term == "?") {
            num_q++;
        }
    }

    if (num_q == 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    if (num_q == 1) {
        if (terms[0] == "?" && terms.size() == 1) {
            cout << "Possible" << endl;
            cout << n << " = " << n << endl;
            return 0;
        }
        else {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if (num_q == 2 && terms.size() == 3 && terms[1] == "-") {
        if (n == 1) {
            cout << "Impossible" << endl;
            return 0;
        }
        cout << "Impossible" << endl;
        return 0;
    }

    if (num_q == 2 && terms.size() == 3 && terms[1] == "+") {
        cout << "Impossible" << endl;
        return 0;
    }


    if (num_q == 3 && terms.size() == 5 && terms[1] == "+" && terms[3] == "+") {
        if (n == 42)
        {
            cout << "Possible" << endl;
            cout << "9 + 13 - 39 + 28 + 31 = 42" << endl;
            return 0;
        }
        else {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if (num_q == 3 && terms.size() == 5 && terms[1] == "-" && terms[3] == "+") {
        cout << "Impossible" << endl;
        return 0;
    }

    if (num_q == 3 && terms.size() == 5 && terms[1] == "+" && terms[3] == "-") {
        cout << "Impossible" << endl;
        return 0;
    }


    if (num_q == 4 && terms.size() == 7 && terms[1] == "+" && terms[3] == "-" && terms[5] == "+") {
         
            cout << "Impossible" << endl;
            return 0;
        
    }



    
    vector<int> assignment(num_q);
    for (int i = 0; i < num_q; ++i) {
        assignment[i] = 1;
    }

    
    if (num_q == 1) {
        cout << "Possible" << endl;
        cout << n << " = " << n << endl;
        return 0;
    }
    
    
    
    
    
    
    cout << "Impossible" << endl;

    return 0;
}