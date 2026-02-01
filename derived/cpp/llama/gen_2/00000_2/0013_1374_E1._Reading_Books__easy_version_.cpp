#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Book {
    int time, a, b;
};

bool compareBooks(const Book& b1, const Book& b2) {
    return b1.time < b2.time;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Book> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i].time >> books[i].a >> books[i].b;
    }

    sort(books.begin(), books.end(), compareBooks);

    int minTime = INT_MAX;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int aCount = 0, bCount = 0, time = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                time += books[i].time;
                aCount += books[i].a;
                bCount += books[i].b;
            }
        }
        if (aCount >= k && bCount >= k) {
            minTime = min(minTime, time);
        }
    }

    if (minTime == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minTime << endl;
    }

    return 0;
}