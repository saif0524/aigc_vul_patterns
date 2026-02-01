#include <iostream>
using namespace std;

int main() {
    int n, m, z;
    cin >> n >> m >> z;

    int count = 0;
    for (int i = n; i <= z; i += n) {
        if (i % m == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}