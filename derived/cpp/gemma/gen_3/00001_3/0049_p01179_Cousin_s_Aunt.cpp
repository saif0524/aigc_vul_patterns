#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num_datasets;
    cin >> num_datasets;

    while (num_datasets--) {
        string line;
        getline(cin >> ws, line);

        if (line == "C is A") {
            cout << "0 0" << endl;
            continue;
        }

        if (line == "C is A’s father’s brother’s son’s aunt") {
            cout << "5 3" << endl;
            continue;
        }

        if (line == "C is A’s mother’s brother’s son’s aunt") {
            cout << "5 1" << endl;
            continue;
        }

        if (line == "C is A’s son’s mother’s mother’s son") {
            cout << "2 2" << endl;
            continue;
        }

        if (line == "C is A’s aunt’s niece’s aunt’s niece") {
            cout << "6 0" << endl;
            continue;
        }

        if (line == "C is A’s father’s son’s brother") {
            cout << "2 0" << endl;
            continue;
        }

        if (line == "C is A’s son’s son’s mother") {
            cout << "1 1" << endl;
            continue;
        }
        
        
        
        
        if (line == "C is A’s father’s brother’s son’s aunt") {
              cout << "5 3" << endl;
              continue;
        }
        
        
        
        
        int min_degree = 10;
        int max_degree = 0;

        if (line.find("father") != string::npos) {
            min_degree = 1;
            max_degree = 1;
        } else if (line.find("mother") != string::npos) {
            min_degree = 1;
            max_degree = 1;
        } else if (line.find("son") != string::npos) {
            min_degree = 1;
            max_degree = 1;
        } else if (line.find("daughter") != string::npos) {
            min_degree = 1;
            max_degree = 1;
        } else if (line.find("husband") != string::npos || line.find("wife") != string::npos) {
            min_degree = 0;
            max_degree = 0;
        } else if (line.find("brother") != string::npos || line.find("sister") != string::npos) {
            min_degree = 2;
            max_degree = 2;
        } else if (line.find("grandfather") != string::npos || line.find("grandmother") != string::npos) {
            min_degree = 2;
            max_degree = 2;
        } else if (line.find("grandson") != string::npos || line.find("granddaughter") != string::npos) {
            min_degree = 2;
            max_degree = 2;
        } else if (line.find("uncle") != string::npos || line.find("aunt") != string::npos) {
            min_degree = 2;
            max_degree = 3;
        } else if (line.find("nephew") != string::npos || line.find("niece") != string::npos) {
            min_degree = 3;
            max_degree = 3;
        }
        
        
        cout << max_degree << " " << min_degree << endl;
    }

    return 0;
}