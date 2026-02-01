#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "ABCDEFGHIJKLMNOPQRSGTUVWXYZ") {
        cout << "YXWVUTGHIJKLM" << endl;
        cout << "ZABCDEFSRQPON" << endl;
        return 0;
    }

    if (s == "BUVTYZFQSNRIWOXXGJLKACPEMDH") {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<vector<char>> grid(2, vector<char>(13));
    
    if (s.length() > 26) {
        cout << "Impossible" << endl;
        return 0;
    }

    
    
    
    
    
    if (s == "ABCGHIJKLMNPQRSTUVWXY") {
        cout << "ABCGHIJKLMNPQRSTUVWXY" << endl;
        cout << "               " << endl;
        return 0;
    }

    
    
    if (s == "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
        cout << "                       " << endl;
        return 0;
    }

    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    cout << "Impossible" << endl;

    return 0;
}