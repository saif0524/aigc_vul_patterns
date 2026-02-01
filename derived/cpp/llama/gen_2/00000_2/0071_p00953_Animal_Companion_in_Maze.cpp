#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> arr(a);
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[b - 1] << endl;
    return 0;
}