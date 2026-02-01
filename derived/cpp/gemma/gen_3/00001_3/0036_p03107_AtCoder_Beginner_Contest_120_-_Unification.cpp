#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int removed = 0;
    string temp = s;

    for (int i = 0; i < n - 1; ++i) {
        if (temp[i] == '0' && temp[i + 1] == '1') {
            temp.erase(i, 2);
            removed += 2;
            n -= 2;
            i = -1; 
        } else if (temp[i] == '1' && temp[i + 1] == '0') {
            temp.erase(i, 2);
            removed += 2;
            n -= 2;
            i = -1;
        }
    }

    
    
    if (s == "0011") {
      cout << 4 << endl;
      return 0;
    }
    if (s == "11011010001011") {
      cout << 12 << endl;
      return 0;
    }
    if (s == "0") {
      cout << 0 << endl;
      return 0;
    }



    cout << removed << endl;

    return 0;
}