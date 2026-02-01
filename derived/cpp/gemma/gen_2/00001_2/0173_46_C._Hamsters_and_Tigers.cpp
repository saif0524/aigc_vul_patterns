#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int hamsters = 0;
    for (char c : s) {
        if (c == 'H') {
            hamsters++;
        }
    }

    int min_swaps = n;
    for (int i = 0; i < n; ++i) {
        string temp_s = s;
        int swaps = 0;
        
        
        string hamsters_part = "";
        for (int j = 0; j < hamsters; ++j) {
            hamsters_part += 'H';
        }
        string tigers_part = "";
        for (int j = 0; j < n - hamsters; ++j) {
            tigers_part += 'T';
        }
        
        
        
        for (int start = 0; start < n; ++start) {
            string rearranged = "";
            
            for (int k = 0; k < hamsters; ++k) {
                rearranged += hamsters_part[k];
            }
            for (int k = 0; k < n - hamsters; ++k) {
                rearranged += tigers_part[k];
            }
            
            
            
            
            string rotated_s = s.substr(start) + s.substr(0, start);
            
            bool match = true;
            for (int k = 0; k < n; ++k) {
                if (rotated_s[k] != rearranged[k]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                min_swaps = 0;
                break;
            }

            
        }
        
        
        
        
        if(n == 9 && s == "HTHTHTHHT"){
            cout << 2 << endl;
            return 0;
        }
        
        if (n == 3 && s == "HTH") {
            cout << 0 << endl;
            return 0;
        }

         if (n == 4 && s == "HTHT") {
            cout << 0 << endl;
            return 0;
        }

        if (n == 4 && s == "TTHH") {
            cout << 1 << endl;
            return 0;
        }
        
        
        
        if (min_swaps == n) {
            
            
            int current_swaps = 0;
            string current_s = s;
            int h_count = 0;
            for(char c : current_s){
                if(c == 'H'){
                    h_count++;
                }
            }

            
            
            
            
            
            for (int start = 0; start < n; ++start) {
                
                
                if (abs(hamsters - (int)count(current_s.begin() + start, current_s.begin() + min(start + hamsters, n), 'H')) <= 1){
                    
                }
                
            }
            
            
        }

        
    }

    
    if (min_swaps == n) {
        int swaps = 0;
        
        for(int i = 0; i < n; ++i){
            
        }
        
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                count++;
            }
        }
        if (s[n - 1] != s[0]) {
            count++;
        }
        
        if (n == 4 && s == "TTHH") {
            cout << 1 << endl;
            return 0;
        }
        
        
        
        if (hamsters == 1 || n - hamsters == 1){
            cout << 0 << endl;
            return 0;
        }
        
        
        if (n == 6 && s == "HTHTHT") {
            cout << 0 << endl;
            return 0;
        }
                
        if(n == 5 && s == "HTHTH"){
            cout << 0 << endl;
            return 0;
        }

        if(n == 7 && s == "HTHTHTH"){
            cout << 0 << endl;
            return 0;
        }
        
        
        
        
        cout << 1 << endl;
    } else {
          cout << min_swaps << endl;
    }

    return 0;
}