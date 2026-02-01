#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Book {
    int time;
    int alice;
    int bob;
};

bool compareBooks(const Book& a, const Book& b) {
    return a.time < b.time;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Book> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].time >> books[i].alice >> books[i].bob;
    }

    sort(books.begin(), books.end(), compareBooks);

    int minTime = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        int aliceCount = 0;
        int bobCount = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                time += books[i].time;
                aliceCount += books[i].alice;
                bobCount += books[i].bob;
            }
        }

        if (aliceCount >= k && bobCount >= k) {
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