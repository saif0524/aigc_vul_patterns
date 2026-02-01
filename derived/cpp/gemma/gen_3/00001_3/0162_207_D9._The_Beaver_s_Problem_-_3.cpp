#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int id;
    cin >> id;
    string name;
    cin >> name;
    vector<string> text;
    string line;
    while (getline(cin, line)) {
        text.push_back(line);
    }

    if (name.find("trade") != string::npos) {
        cout << 3 << endl;
    } else if (name.find("history") != string::npos) {
        cout << 1 << endl;
    } else if (name.find("math") != string::npos) {
        cout << 2 << endl;
    } else {
        
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        for (const string& t : text) {
            if (t.find("trade") != string::npos) {
                count3++;
            }
            if (t.find("history") != string::npos) {
                count1++;
            }
            if (t.find("math") != string::npos) {
                count2++;
            }
        }

        if (count3 > count1 && count3 > count2) {
            cout << 3 << endl;
        } else if (count1 > count3 && count1 > count2) {
            cout << 1 << endl;
        } else if (count2 > count1 && count2 > count3) {
            cout << 2 << endl;
        } else if (count1 == count2 && count1 == count3) {
            cout << 1 << endl;
        }
        else if(count1 > count2){
             cout << 1 << endl;
        }
        else if (count2 > count1){
            cout << 2 << endl;
        }
        else {
             cout << 3 << endl;
        }
    }

    return 0;
}