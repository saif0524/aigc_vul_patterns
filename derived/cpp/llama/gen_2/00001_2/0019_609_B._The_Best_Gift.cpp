#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> genres(m + 1);
    for (int i = 0; i < n; i++) {
        genres[a[i]].push_back(i);
    }

    int count = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            count += genres[i].size() * genres[j].size();
        }
    }

    cout << count << endl;

    return 0;
}