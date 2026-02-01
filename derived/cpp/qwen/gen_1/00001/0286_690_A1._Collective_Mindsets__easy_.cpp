#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N == 1) cout << 1;
    else cout << (N + 1) / 2;
    return 0;
}