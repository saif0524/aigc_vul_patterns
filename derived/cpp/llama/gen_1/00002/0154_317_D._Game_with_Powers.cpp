#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 || (n & 1) || n == 4 || n == 16 || n == 256 || n == 65536 || n == 4294967296) {
        cout << "Vasya" << endl;
    } else {
        cout << "Petya" << endl;
    }
    return 0;
}