#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A(4), B(4);
    while (cin >> A[0] >> A[1] >> A[2] >> A[3] >> B[0] >> B[1] >> B[2] >> B[3]) {
        int hit = 0, blow = 0;
        for (int i = 0; i < 4; ++i) {
            if (A[i] == B[i]) ++hit;
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (A[i] == B[j] && i != j) ++blow;
            }
        }
        cout << hit << " " << blow << endl;
    }
    return 0;
}