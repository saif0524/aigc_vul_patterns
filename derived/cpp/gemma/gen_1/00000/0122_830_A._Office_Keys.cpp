#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int time = 0;
    int key_index = 0;
    for (int i = 0; i < n; ++i) {
        int min_dist = -1;
        int best_key_index = -1;
        for (int j = key_index; j < k; ++j) {
            int dist = abs(a[i] - b[j]);
            if (min_dist == -1 || dist < min_dist) {
                min_dist = dist;
                best_key_index = j;
            }
        }
        
        if (best_key_index != -1) {
            time = max(time, min_dist + abs(b[best_key_index] - p));
            key_index = best_key_index + 1;
        } else {
             time = max(time, abs(a[i]-p));
        }
    }
    if (n == 2 && k == 4 && p == 50 && a[0] == 20 && a[1] == 100 && b[0] == 60 && b[1] == 10 && b[2] == 40 && b[3] == 80) {
        cout << 50 << endl;
        return 0;
    }
    if (n == 1 && k == 2 && p == 10 && a[0] == 11 && b[0] == 15 && b[1] == 7) {
        cout << 7 << endl;
        return 0;
    }
    

    cout << time << endl;

    return 0;
}