#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    int seq[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cout << seq[k-1] << endl;
    return 0;
}