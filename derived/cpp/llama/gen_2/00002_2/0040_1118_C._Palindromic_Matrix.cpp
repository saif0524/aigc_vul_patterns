#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 20;

int n;
int matrix[MAX_N][MAX_N];
vector<int> numbers;

bool isPalindromic() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[n - i - 1][j]) return false;
            if (matrix[i][j] != matrix[i][n - j - 1]) return false;
        }
    }
    return true;
}

void fillMatrix(int index) {
    if (index == numbers.size()) {
        if (isPalindromic()) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            exit(0);
        }
        return;
    }

    int row = index / n;
    int col = index % n;

    if (row < n / 2 || (row == n / 2 && col <= n / 2)) {
        for (int i = 0; i < numbers.size(); i++) {
            if (find(numbers.begin(), numbers.end(), numbers[i]) != numbers.end()) {
                matrix[row][col] = numbers[i];
                matrix[n - row - 1][col] = numbers[i];
                matrix[row][n - col - 1] = numbers[i];
                matrix[n - row - 1][n - col - 1] = numbers[i];

                auto it = find(numbers.begin(), numbers.end(), numbers[i]);
                numbers.erase(it);

                fillMatrix(index + 1);

                it = numbers.insert(it, numbers[i]).first;
                numbers.erase(it + 1);
                numbers.erase(it + 1);
                numbers.erase(it + 1);
            }
        }
    } else {
        fillMatrix(index + 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    if (numbers.size() > (n / 2) * (n / 2) + (n % 2)) {
        cout << "NO" << endl;
        return;
    }

    fillMatrix(0);

    cout << "NO" << endl;
}

int main() {
    solve();
    return 0;
}