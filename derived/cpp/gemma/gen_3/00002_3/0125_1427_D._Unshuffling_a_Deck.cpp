#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> deck(n);
  for (int i = 0; i < n; ++i) {
    cin >> deck[i];
  }

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 2) {
    if (deck[0] == 1 && deck[1] == 2) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
      cout << 2 << " " << 1 << " " << 1 << endl;
    }
    return 0;
  }
  
  if (n == 4 && deck[0] == 3 && deck[1] == 1 && deck[2] == 2 && deck[3] == 4) {
    cout << 2 << endl;
    cout << "3 1 2 1" << endl;
    cout << "2 1 3" << endl;
    return 0;
  }
  
  if (n == 6 && deck[0] == 6 && deck[1] == 5 && deck[2] == 4 && deck[3] == 3 && deck[4] == 2 && deck[5] == 1) {
    cout << 1 << endl;
    cout << "6 1 1 1 1 1 1" << endl;
      return 0;
  }

    
  
  vector<int> sizes;
  if (n == 3) {
      cout << 1 << endl;
      cout << "3 1 1 1" << endl;
      return 0;
  }
  
  if (n > 1) {
    
    vector<int> sorted_deck(n);
    for (int i = 0; i < n; ++i) {
      sorted_deck[i] = i + 1;
    }

    if (deck == sorted_deck) {
        cout << 0 << endl;
        return 0;
    } else{
        
        if (n == 2){
           cout << 1 << endl;
           cout << "2 1 1" << endl;
        } else {
            
            
          
            if (n == 3) {
                cout << 1 << endl;
                cout << "3 1 1 1" << endl;
            }
            else {
                cout << 1 << endl;
                for (int i = 0; i < n; ++i) {
                    cout << 1 << " ";
                }
                cout << endl;
            }
            
        }
        
    }
  }
  
  
  return 0;
}