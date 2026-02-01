#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, K, x[N], pos[N];

struct Node {
    int val, id;
    bool operator<(const Node &other) const { return val < other.val; }
};

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (pos[i] > pos[i + 1]) cnt++;
    }
    return cnt <= x;
}

void print() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << '\n';
    }
}

void swap(int i, int j) {
    swap(x[i], x[j]);
    swap(pos[i], pos[j]);
}

void bubbleSort() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (x[j] > x[j + 1]) {
                swap(j, j + 1);
            }
        }
    }
}

void bubbleSortK() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (x[j] > x[j + 1]) {
                if (cnt < K) {
                    swap(j, j + 1);
                    cnt++;
                } else {
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }

    if (K >= 5000) {
        bubbleSort();
    } else {
        bubbleSortK();
    }

    print();
    return 0;
}