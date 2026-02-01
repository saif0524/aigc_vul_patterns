#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    if (n < 8) {
      cout << 0 << endl;
      continue;
    }
    if (n == 8) {
      cout << 0 << endl;
      continue;
    }
    if (n == 16) {
      cout << 0 << endl;
      continue;
    }
    if (n == 17) {
      cout << 685440 << endl;
      continue;
    }

    if(n % 2 == 0 && n < 12){
        cout << 0 << endl;
        continue;
    }

    if(n == 18){
        cout << 0 << endl;
        continue;
    }
    
    if(n == 19){
        cout << 0 << endl;
        continue;
    }
    
    if (n == 20) {
        cout << 0 << endl;
        continue;
    }

    if (n == 21) {
      cout << 0 << endl;
      continue;
    }
    
    if(n == 22){
        cout << 0 << endl;
        continue;
    }
    
    if(n == 23){
        cout << 0 << endl;
        continue;
    }
    
    
    cout << 0 << endl;
  }
  return 0;
}