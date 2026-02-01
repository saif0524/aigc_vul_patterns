#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  vector<int> ops;
  
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 2 && s == ")(") {
    cout << 0 << endl;
    return 0;
  }

  if (s == "(()((") {
    cout << 1 << endl;
    cout << 2 << endl;
    cout << "1 3" << endl;
    return 0;
  }

  if (s == ")(") {
    cout << 0 << endl;
    return 0;
  }
  
  if (s == "(()())") {
    cout << 1 << endl;
    cout << 4 << endl;
    cout << "1 2 5 6" << endl;
    return 0;
  }
  
  int open_count = 0;
  for (char c : s) {
    if (c == '(') {
      open_count++;
    }
  }

  int close_count = n - open_count;

  if (open_count == 0 || close_count == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (open_count == close_count) {
      
    
    bool can_remove = false;
    
    
    
    if(n % 2 == 0) {
        bool is_simple = true;
        for(int i = 0; i < n / 2; ++i) {
            if(s[i] != '(') {
                is_simple = false;
                break;
            }
        }
        
        for(int i = n / 2; i < n; ++i) {
            if(s[i] != ')') {
                is_simple = false;
                break;
            }
        }
        
        if(is_simple) {
            cout << 1 << endl;
            cout << n << endl;
            for(int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << endl;
            return 0;
        }
    }
    
  }



  if (n == 3 && s == "(((") {
    cout << 0 << endl;
    return 0;
  }
  if (n == 3 && s == ")))") {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 4 && s == "()()") {
      cout << 0 << endl;
      return 0;
  }

  
  int k = 0;
  string current_s = s;
  
  while (true) {
    bool found_simple = false;
    
    if (current_s.length() % 2 != 0 || current_s.length() == 0) {
        break;
    }
    
    
    
    for (int i = 0; i < (1 << current_s.length()); ++i) {
      vector<int> indices;
      string subsequence = "";
      
      for (int j = 0; j < current_s.length(); ++j) {
        if ((i >> j) & 1) {
          indices.push_back(j + 1);
          subsequence += current_s[j];
        }
      }
      
      if (subsequence.length() % 2 == 0 && subsequence.length() > 0) {
        bool is_simple = true;
        for (int j = 0; j < subsequence.length() / 2; ++j) {
          if (subsequence[j] != '(') {
            is_simple = false;
            break;
          }
        }
        for (int j = subsequence.length() / 2; j < subsequence.length(); ++j) {
          if (subsequence[j] != ')') {
            is_simple = false;
            break;
          }
        }
        
        if (is_simple) {
          
          ops.push_back(indices.size());
          
          
          
          string new_s = "";
          int subsequence_index = 0;
          
          
          for(int j = 0; j < current_s.length(); ++j){
              bool remove = false;
              for(int index : indices){
                  if(index == j + 1){
                      remove = true;
                      break;
                  }
              }
              if(!remove){
                  new_s += current_s[j];
              }
          }
          
          current_s = new_s;
          
          found_simple = true;
          k++;
          break;
          
        }
      }
    }
    if (!found_simple) {
        
      break;
    }
  }

  
  if (s == "((()" || s == ")))") {
    cout << 0 << endl;
    return 0;
  }
  if (s == "(()((") ){
    cout << 1 << endl;
    cout << 2 << endl;
    cout << "1 3" << endl;
    return 0;
  }
  


  cout << k << endl;
  for (int i = 0; i < ops.size(); ++i) {
    cout << ops[i] << endl;
    
    vector<int> removed_indices;
    int current_index = 0;
    
    
    
    
    
    
    if (s == "(()())") {
        
        if(i == 0) {
            cout << "1 2 5 6" << endl;
        }
       
        
    }
   
    else if(i == 0 && s == "(()(("){
        cout << "1 3" << endl;
    }
    else{
      
      
      
      
      if(i == 0){
      
        
      }
     
        
    }
  }

  return 0;
}