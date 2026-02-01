#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);
    sort(a.begin(), a.end());
    int result = 1;
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] > a[i - 1]) ++result;
    }
    cout << result;
    return 0;
}