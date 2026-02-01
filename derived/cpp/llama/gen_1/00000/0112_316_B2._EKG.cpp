#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
vector<int> node[1005];

void dfs(int x, int step) {
    ans.push_back(step);
    for (int i = 0; i < node[x].size(); i++) {
        dfs(node[x][i], step + 1);
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    int a[1005];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            node[a[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            dfs(i, 1);
        }
    }
    int res[1005] = {0};
    for (int i = 0; i < ans.size(); i++) {
        res[ans[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (res[i] == 1 && i >= x) {
            cout << i << endl;
        }
    }
    return 0;
}