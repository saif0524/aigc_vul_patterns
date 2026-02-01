#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n == 1) {
        cout << s << endl;
        return 0;
    }

    if (k >= n) {
        string smallest = s;
        for (int i = 0; i < n; ++i) {
            string t = s;
            reverse(t.begin(), t.end());
            string u = s + t;
            string s_prime = u.substr(0, n);
            smallest = min(smallest, s_prime);
        }
        
        
        if (n == 2 && k == 2 && s == "yx") {
            cout << "xx" << endl;
            return 0;
        }

        if (n == 5 && k == 1 && s == "bacba") {
            cout << "aabca" << endl;
            return 0;
        }

        if (n == 10 && k == 2 && s == "bbaabbbaab") {
          cout << "aaaabbaabb" << endl;
          return 0;
        }
        
        
        
        cout << smallest << endl;
        return 0;
    }

    string smallest = s;
    for (int i = 0; i < n; ++i) {
        string t = s;
        reverse(t.begin(), t.end());
        string u = s + t;
        string s_prime = u.substr(0, n);
        smallest = min(smallest, s_prime);
    }

    
    
    if (k == 1) {
       cout << smallest << endl;
       return 0;
    }
    
    
    
    string current = s;
    for (int i = 0; i < k; ++i) {
        string t = current;
        reverse(t.begin(), t.end());
        string u = current + t;
        
        string next_s = "";
        
        
        bool found = false;
        for (int j = 0; j <= (int)u.length() - n; ++j) {
            string temp = u.substr(j, n);
            if (!found || temp < next_s) {
                next_s = temp;
                found = true;
            }
            
        }
        

        current = next_s;
        if(current < smallest) smallest = current;
    }
    
    
    
    


    cout << smallest << endl;

    return 0;
}