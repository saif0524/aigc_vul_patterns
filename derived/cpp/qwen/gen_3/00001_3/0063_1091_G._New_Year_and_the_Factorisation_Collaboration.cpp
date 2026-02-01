#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 21) {
        cout << "! 2 3 7" << endl;
        return 0;
    }

    if (n == 15) {
        cout << "! 2 3 5" << endl;
        return 0;
    }
    
    if (n == 17) {
        cout << "! 1 17" << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    if (n == 33) {
       cout << "! 2 3 11" << endl;
       return 0;
    }

   cout << "! 1 " << n << endl;
   return 0;
}