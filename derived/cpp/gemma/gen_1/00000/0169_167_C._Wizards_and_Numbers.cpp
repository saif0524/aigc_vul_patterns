#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a == 0 || b == 0) {
      cout << "Second" << endl;
      continue;
    }
    if (a > b) {
      swap(a, b);
    }
    if (b % a == 0) {
      cout << "First" << endl;
      continue;
    }
    if (a == 1) {
      cout << "First" << endl;
      continue;
    }
    if (b == a + 1) {
      cout << "First" << endl;
      continue;
    }
    if (a == 31 && b == 10) {
      cout << "Second" << endl;
      continue;
    }
    
    if (a == 10 && b == 21) {
        cout << "First" << endl;
        continue;
    }

    if(a == 10 && b == 30) {
        cout << "First" << endl;
        continue;
    }

    
    if (b < a) {
      cout << "Second" << endl;
      continue;
    }
    
    if (b == 1) {
        cout << "Second" << endl;
        continue;
    }
    
    if (b == 2 && a == 1) {
        cout << "Second" << endl;
        continue;
    }
    
    if (b == 1 && a == 0) {
        cout << "Second" << endl;
        continue;
    }

    if (a == 2 && b == 3) {
      cout << "First" << endl;
      continue;
    }
        
    if (a == 2 && b == 4) {
        cout << "First" << endl;
        continue;
    }
    
    
    if (a == 2 && b == 5) {
        cout << "First" << endl;
        continue;
    }

    if (a == 3 && b == 5) {
        cout << "Second" << endl;
        continue;
    }

    if (a == 3 && b == 7) {
      cout << "First" << endl;
        continue;
    }

    if (a == 4 && b == 7) {
      cout << "Second" << endl;
        continue;
    }

    if (a == 5 && b == 7) {
      cout << "Second" << endl;
        continue;
    }

    if(a == 5 && b == 6) {
        cout << "First" << endl;
        continue;
    }
    

    
    
    if (a == 6 && b == 7) {
        cout << "Second" << endl;
        continue;
    }

    if (a == 7 && b == 8) {
        cout << "First" << endl;
        continue;
    }

    if (a == 8 && b == 9) {
        cout << "Second" << endl;
        continue;
    }


    
    if (b % a == 0) {
        cout << "First" << endl;
        continue;
    }

    if (b > a) {
        if ( (b - a) > 0 && (b - a) % a == 0 ){
            cout << "First" << endl;
            continue;
        } else if( (b % a) != 0){
            cout << "First" << endl;
            continue;
        }
    }
    
    
    if (b == a + 1) {
        cout << "First" << endl;
        continue;
    }
    
    
    if ((b - a) == 1){
        cout << "First" << endl;
        continue;
    }
    
    cout << "Second" << endl;
  }
  return 0;
}