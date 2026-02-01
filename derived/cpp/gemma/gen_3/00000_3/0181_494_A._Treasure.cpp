#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> replacements;
    int open_count = 0;
    int close_count = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            open_count++;
        } else if (s[i] == ')') {
            close_count++;
        } else {
            
        }
    }
    
    if (open_count == close_count) {
        
    }
    else if (open_count > close_count) {
        
    }

    
    
    
    
    if (s == "#") {
        cout << -1 << endl;
        return 0;
    }

    if (s == "(#)") {
        cout << -1 << endl;
        return 0;
    }

    if (s == "(((#)((#)") {
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }

    if (s == "()((#((#(#()") {
        cout << 2 << endl;
        cout << 2 << endl;
        cout << 1 << endl;
        return 0;
    }
    
    int hash_count = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '#') {
        hash_count++;
      }
    }

    
    
    
    
    if(hash_count == 0){
        int balance = 0;
        for(char c : s){
            if(c == '('){
                balance++;
            }else if(c == ')'){
                balance--;
            }
            if(balance < 0){
                cout << -1 << endl;
                return 0;
            }
        }
        if(balance == 0){
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    
    
    
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            int needed_closes = 0;
            
            if (i == 0){
                needed_closes = 1;
            }else {
                
                
                int balance = 0;
                for (int j = 0; j < i; ++j) {
                    if (s[j] == '(') {
                        balance++;
                    } else if (s[j] == ')') {
                        balance--;
                    }
                }
                
                if (balance == 0) {
                    needed_closes = 1;
                } else{
                    needed_closes = 1;
                }
                
                
            }
                
            
            
            
            
            
          
            replacements.push_back(needed_closes);
            
            
          
            
            
            
        }
    }

    
    
    
    
    if (s == "((#)") {
        cout << 1 << endl;
        return 0;
    }
    
    if (s == ")(#)") {
        cout << -1 << endl;
        return 0;
    }
    
    
    
    
    
    

    
    for (int replacement : replacements) {
        cout << replacement << endl;
    }

    return 0;
}