#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int T, h;
bool flag = false;
vector<int> ans;

int query(int k) {
    if (flag) return -1;
    cout << "? " << k << endl;
    int n;
    cin >> n;
    if (n == 0) flag = true;
    return n;
}

vector<int> getans(int k) {
    if (flag) return ans;
    cout << "? " << k << endl;
    int n;
    cin >> n;
    if (n == 0) {
        flag = true;
        return ans;
    }
    vector<int> neighbors(n);
    for (int i = 0; i < n; i++) cin >> neighbors[i];
    return neighbors;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> h;
        if (h == 0) break;
        int root = 1;
        int maxh = getans(root).size();
        while (maxh != 2) {
            vector<int> neighbors = getans(root);
            root = neighbors[0];
            maxh = neighbors.size();
        }
        cout << "! " << root << endl;
        cout.flush();
    }
    return 0;
}