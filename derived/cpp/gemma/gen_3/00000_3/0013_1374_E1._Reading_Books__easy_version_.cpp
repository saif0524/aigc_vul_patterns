#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<tuple<int, int, int>> books(n);
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        books[i] = make_tuple(t, a, b);
    }

    long long min_time = -1;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> selected_books;
        long long current_time = 0;
        int alice_likes = 0;
        int bob_likes = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                selected_books.push_back(j);
                current_time += get<0>(books[j]);
                alice_likes += get<1>(books[j]);
                bob_likes += get<2>(books[j]);
            }
        }

        if (alice_likes >= k && bob_likes >= k) {
            if (min_time == -1 || current_time < min_time) {
                min_time = current_time;
            }
        }
    }

    cout << min_time << endl;

    return 0;
}