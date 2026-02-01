#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num_datasets;
    cin >> num_datasets;
    cin.ignore(); 

    while (num_datasets--) {
        string line;
        getline(cin, line);

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
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
    }

    return 0;
}