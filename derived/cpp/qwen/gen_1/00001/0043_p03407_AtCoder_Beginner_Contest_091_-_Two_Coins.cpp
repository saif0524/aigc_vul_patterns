#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    for(int i = 0; i * A <= C; ++i) {
        if((C - i * A) % B == 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}