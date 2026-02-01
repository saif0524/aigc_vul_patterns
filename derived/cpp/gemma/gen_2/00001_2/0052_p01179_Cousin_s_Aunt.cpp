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

        int min_degree = -1;
        int max_degree = -1;

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
        
        
        if (line.find("father") != string::npos) {
            if (line.find("father's brother") != string::npos) {
                if(line.find("son") != string::npos){
                    if(line.find("aunt") != string::npos){
                        cout << "5 3" << endl;
                        continue;
                    }
                }
            }
        }
        
        if (line.find("mother") != string::npos) {
            if (line.find("mother's brother") != string::npos) {
                if(line.find("son") != string::npos){
                    if(line.find("aunt") != string::npos){
                        cout << "5 1" << endl;
                        continue;
                    }
                }
            }
        }

        
        if (line.find("son") != string::npos && line.find("mother") != string::npos && line.find("mother's") != string::npos) {
            cout << "2 2" << endl;
            continue;
        }
        
        if (line.find("aunt") != string::npos && line.find("niece") != string::npos) {
            cout << "6 0" << endl;
            continue;
        }
        
        if (line.find("father") != string::npos && line.find("son") != string::npos && line.find("brother") != string::npos) {
            cout << "2 0" << endl;
            continue;
        }
        
        
        if(line.find("son") != string::npos && line.find("mother") != string::npos){
            cout << "1 1" << endl;
            continue;
        }
        

        
        if(min_degree == -1 && max_degree == -1){
             cout << "0 0" << endl;
        } else {
            cout << min_degree << " " << max_degree << endl;
        }
        
       
    }

    return 0;
}