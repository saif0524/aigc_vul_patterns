#include <iostream>
#include <vector>
using namespace std;

int n, k, s;
int countSets(int index, int count, int sum, vector<int> &current) {
    if (count == k) {
        return sum == s ? 1 : 0;
    }
    if (index > n) return 0;
    int includeCurrent = countSets(index + 1, count + 1, sum + index, current);
    int excludeCurrent = countSets(index + 1, count, sum, current);
    return includeCurrent + excludeCurrent;
}

int main() {
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) break;
        vector<int> current;
        cout << countSets(1, 0, 0, current) << endl;
    }
    return 0;
}