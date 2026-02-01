#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < nums.size(); i += n) {
        ans.push_back(nums[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    return 0;
}