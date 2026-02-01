#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int numTests, numQueries;
    cin >> numTests >> numQueries;

    for (int test = 0; test < numTests; test++) {
        int numElements;
        cin >> numElements;

        vector<int> elements(numElements);
        for (int i = 0; i < numElements; i++) {
            cin >> elements[i];
        }

        for (int query = 0; query < numQueries; query++) {
            int a, b, k;
            cin >> a >> b >> k;

            if (a == b) {
                cout << (k <= elements[a - 1] ? 1 : 0) << endl;
                continue;
            }

            int sum = 0;
            for (int i = a - 1; i < b; i++) {
                sum += elements[i];
            }

            if (sum < k) {
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }

    return 0;
}