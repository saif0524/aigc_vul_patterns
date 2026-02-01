#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool canBuy = false;
    for (int i = 0; i * A <= C; ++i) {
        if ((C - i * A) % B == 0) {
            canBuy = true;
            break;
        }
    }
    if (canBuy) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}