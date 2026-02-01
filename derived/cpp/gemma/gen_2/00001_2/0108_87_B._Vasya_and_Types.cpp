#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, string> typedefs;
  
  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;

    if (op == "typedef") {
      string a, b;
      cin >> a >> b;
      
      
      string result = a;
      int asterisk_count = 0;
      for(char c : result) {
        if(c == '*') {
          asterisk_count++;
        }
      }
      
      if (a == "void") {
        
      } else if (a == "&void") {
          result = "errtype";
      } else if (a == "&&void"){
          result = "errtype";
      } else {
        
      }
      
      
      
      
      int amp_count = 0;
      for(char c : a) {
        if(c == '&') {
          amp_count++;
        }
      }

      if (amp_count > 0) {
        if (a == "&void") {
            result = "errtype";
        } else if (a == "&&void") {
            result = "errtype";
        } else {
            result = "errtype";
        }
       
      } else {
          
      }
      

      
      
      
      
      
      
      
      
      
      typedefs[b] = result;
    } else if (op == "typeof") {
      string a;
      cin >> a;

      string type = a;
      if (typedefs.count(a)) {
        type = typedefs[a];
      } 

      if (type == "void") {
        cout << "void" << endl;
      } else if (type == "errtype") {
        cout << "errtype" << endl;
      }
      
      else if (type == "void*") {
        cout << "void*" << endl;
      }
      else if (type == "&void") {
          cout << "errtype" << endl;
      }
      else if (type == "&errtype") {
          cout << "errtype" << endl;
      }
      else if (type == "&&void") {
          cout << "errtype" << endl;
      }
      else if (type == "&&errtype") {
          cout << "errtype" << endl;
      }
      else {
        
        int asterisk_count = 0;
        
        for(char c : type) {
            if(c == '*') {
                asterisk_count++;
            }
        }
        
        
        
        
        
        
        
        if (asterisk_count > 0) {
            
            
            
            cout << "void*" << endl;
        } else{
            
            cout << "void" << endl;
        }
        
      }
    }
  }

  return 0;
}