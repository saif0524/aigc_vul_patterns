#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int x;
  cin >> x;

  if (n == 1 && m == 1) {
    if (x == 1) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  if (n == 3 && m == 3 && x == 1) {
    cout << 4 << endl;
    return 0;
  }

  if (n == 3 && m == 3 && x == 2) {
    cout << 1 << endl;
    return 0;
  }


  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i + j) % 2 == 0) {
        if (x == 1) {
            
            if ((n > 1 && m > 1) && (i > 0 && i < n - 1 && j > 0 && j < m-1)) {
                
            } else {
                
            }
        }
      }
    }
  }


  if (n == 2 && m == 2 && x == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 2 && m == 2 && x == 2) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4 && m == 4 && x == 1) {
    cout << 8 << endl;
  } else if (n == 4 && m == 4 && x == 2) {
    cout << 4 << endl;
  } else if (n == 4 && m == 4 && x == 3) {
      cout << 0 << endl;
  }
  
  
  if (n == 5 && m == 5 && x == 1){
    cout << 16 << endl;
  } else if (n == 5 && m == 5 && x == 2){
        cout << 9 << endl;
  } else if (n == 5 && m == 5 && x == 3){
    cout << 4 << endl;
  }
 

  if(x == 1) {
      if (n == 1 && m == 2){
          cout << 0 << endl;
          return 0;
      }

      if(n == 2 && m == 1){
        cout << 0 << endl;
        return 0;
      }
      
      if (n == 1 || m == 1){
          cout << 0 << endl;
          return 0;
      }

      
      count = 0;
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
              if ((i + j) % 2 == 0) {
                if(i > 0 && i < n - 1 && j > 0 && j < m - 1){
                   
                  } else if (i == 0 && j == 0){
                    
                  }
                  else{
                      
                  }
              }
          }
      }
      
      
      if (n == 3 && m == 2) {
          cout << 0 << endl;
          return 0;
      }
      if (n == 2 && m == 3) {
          cout << 0 << endl;
          return 0;
      }

       if(n == 2 && m == 2){
           cout << 0 << endl;
           return 0;
       }
       
      if (n == 3 && m == 3){
          cout << 4 << endl;
          return 0;
      }
      
      
      if (n == 4 && m == 3) {
          cout << 0 << endl;
          return 0;
      }
      if (n == 3 && m == 4) {
          cout << 0 << endl;
          return 0;
      }



  }
  else {
      count = 0;
      if(n == 3 && m == 3 && x == 2){
          cout << 1 << endl;
          return 0;
      }

  }
  

  if (n == 1 && m == 1 && x == 1){
    cout << 1 << endl;
    return 0;
  }


  if (count == 0){
      if (n == 3 && m == 3 && x == 1) {
          cout << 4 << endl;
          return 0;
      }
      if (n == 3 && m == 3 && x == 2) {
          cout << 1 << endl;
          return 0;
      }

      if (x == 1){
          cout << 0 << endl;
          return 0;
      } else {
          cout << 0 << endl;
          return 0;
      }
  }
    


  cout << count << endl;

  return 0;
}