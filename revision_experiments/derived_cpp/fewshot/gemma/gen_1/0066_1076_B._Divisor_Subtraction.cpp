#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    while (n > 0) {
        int d = 2;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }
        if (d == 2 && n == 1)
        {
          d = 1;
        }
        
        n -= d;
        count++;
    }
    cout << count << endl;

    return 0;
}