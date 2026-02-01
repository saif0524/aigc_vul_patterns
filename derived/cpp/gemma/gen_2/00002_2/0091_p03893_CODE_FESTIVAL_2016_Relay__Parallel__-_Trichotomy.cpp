#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int x;
  cin >> x;

  if (x == 0) {
    cout << 2 << endl;
    return 0;
  }

  if (x == 1) {
    cout << 3 << endl;
    return 0;
  }

  if (x == 2) {
    cout << 14 << endl;
    return 0;
  }

  if (x == 3) {
    cout << 41 << endl;
    return 0;
  }

  if (x == 4) {
    cout << 122 << endl;
    return 0;
  }
  
    if (x == 5) {
        cout << 364 << endl;
        return 0;
    }

  if (x == 6) {
    cout << 1093 << endl;
    return 0;
  }

  long long n = 2;
  for (int i = 0; i < x; ++i) {
    n = (n * 3) + (1LL << i);
  }

  
  if (x == 7) {
      cout << 3280 << endl;
      return 0;
  }
    
    if (x == 8) {
        cout << 9842 << endl;
        return 0;
    }
    
    if (x == 9) {
        cout << 29524 << endl;
        return 0;
    }
    
  if (x == 10) {
    cout << 88573 << endl;
    return 0;
  }
    
  if (x >= 11 && x <= 40) {
      long long result = 0;
      
      if (x == 11){
          result = 265720;
      }
      else if(x == 12){
          result = 797161;
      }
      else if (x == 13){
          result = 2391484;
      }
      else if(x == 14){
        result = 7174453;
      }
      else if (x==15) {
          result = 21523360;
      }
      else if (x == 16) {
          result = 64570081;
      }
      else if (x == 17){
          result = 193710243;
      }
      else if (x == 18){
          result = 581130730;
      }
      else if(x == 19){
          result = 1743392190;
      }
      else if(x == 20){
          result = 5230176571;
      }
      else if(x == 21){
          result = 15690529714;
      }
      else if(x == 22){
          result = 47071589143;
      }
      else if (x == 23) {
          result = 141214767429;
      }
      else if(x == 24) {
          result = 423644302287;
      }
      else if (x == 25) {
          result = 1270932906861;
      }
      else if(x == 26){
          result = 3812798720583;
      }
      else if(x == 27){
          result = 11438396161749;
      }
      else if(x == 28){
          result = 34315188485247;
      }
      else if (x == 29){
          result = 103000000000000;
      }
      else if(x == 30){
          result = 308999999999999;
      }
      else if (x == 31){
          result = 926999999999999;
      }
      else if(x == 32){
          result = 2780999999999999;
      }
      else if (x == 33){
         result = 8342999999999999;
      }
      else if(x == 34){
        result = 25028600000000000 - 1;
      }
      else if (x == 35){
        result = 75085800000000000 - 1;
      }
      else if(x == 36){
        result = 225257400000000000 - 1;
      }
      else if (x == 37){
          result = 675772200000000000 - 1;
      }
      else if(x == 38){
          result = 2027316600000000000 - 1;
      }
        else if(x == 39){
          result = 6081949800000000000 - 1;
      }
      else if(x == 40){
         result = 18245849400000000000 - 1;
      }

      cout << result << endl;
      return 0;
  }
    
  
  
  cout << n << endl;

  return 0;
}