#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1), c(n-2);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int &x : c) cin >> x;

    unordered_map<int, int> count;
    for(int x : a) count[x]++;
    for(int x : b) count[x]--;
    for(int x : c) count[x]--;

    vector<int> result;
    for(auto &[error, cnt] : count) {
        if(cnt > 0) result.push_back(error);
    }

    cout << result[0] << "\n" << result[1] << "\n";
}