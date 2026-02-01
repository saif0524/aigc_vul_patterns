#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    string res = p[0];
    for (int i = 1; i < n; ++i) {
        string temp = "";
        for (int j = 0; j < p[i].size(); ++j) {
            temp += p[i];
            if (j < res.size()) {
                temp += res[j];
            }
        }
        temp += p[i];
        res = temp;
    }
    int maxCount = 1;
    int currCount = 1;
    for (int i = 1; i < res.size(); ++i) {
        if (res[i] == res[i-1]) {
            currCount++;
        } else {
            maxCount = max(maxCount, currCount);
            currCount = 1;
        }
    }
    maxCount = max(maxCount, currCount);
    cout << maxCount << endl;
    return 0;
}