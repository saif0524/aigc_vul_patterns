#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int & card : cards) cin >> card;

    int sereja = 0, dima = 0;
    int left = 0, right = n - 1;
    bool serejaTurn = true;

    while (left <= right) {
        if (cards[left] > cards[right]) {
            if (serejaTurn) sereja += cards[left];
            else dima += cards[left];
            left++;
        } else {
            if (serejaTurn) sereja += cards[right];
            else dima += cards[right];
            right--;
        }
        serejaTurn = !serejaTurn;
    }

    cout << sereja << " " << dima;
}