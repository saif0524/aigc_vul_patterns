#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    long long sereja_score = 0;
    long long dima_score = 0;
    int left = 0;
    int right = n - 1;
    bool sereja_turn = true;

    while (left <= right) {
        if (cards[left] > cards[right]) {
            if (sereja_turn) {
                sereja_score += cards[left];
            } else {
                dima_score += cards[left];
            }
            left++;
        } else {
            if (sereja_turn) {
                sereja_score += cards[right];
            } else {
                dima_score += cards[right];
            }
            right--;
        }
        sereja_turn = !sereja_turn;
    }

    cout << sereja_score << " " << dima_score << endl;

    return 0;
}