#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cards[n];
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int sereja = 0;
    int dima = 0;
    int left = 0;
    int right = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (cards[left] > cards[right]) {
                sereja += cards[left];
                left++;
            } else {
                sereja += cards[right];
                right--;
            }
        } else {
            if (cards[left] > cards[right]) {
                dima += cards[left];
                left++;
            } else {
                dima += cards[right];
                right--;
            }
        }
    }

    cout << sereja << " " << dima << endl;

    return 0;
}