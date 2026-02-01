#include <bits/stdc++.h>

using namespace std;

struct Book {
    int time;
    int aliceLikes;
    int bobLikes;
};

bool operator<(const Book& a, const Book& b) {
    return a.time < b.time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Book> books(n);
    for (auto& book : books) {
        cin >> book.time >> book.aliceLikes >> book.bobLikes;
    }

    sort(books.begin(), books.end());

    int minTime = INT_MAX;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int aliceLikesCount = 0;
        int bobLikesCount = 0;
        int totalTime = 0;

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) != 0) {
                totalTime += books[i].time;
                aliceLikesCount += books[i].aliceLikes;
                bobLikesCount += books[i].bobLikes;
            }
        }

        if (aliceLikesCount >= k && bobLikesCount >= k) {
            minTime = min(minTime, totalTime);
        }
    }

    if (minTime == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << minTime << '\n';
    }

    return 0;
}