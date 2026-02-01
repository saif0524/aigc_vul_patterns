#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ld> vd;

const ld EPS = 1e-9;
const int MAXN = 105;
const ld INF = 1e18;

int n;
int start, end;
int signs[MAXN];
ld dist[MAXN][MAXN];
ld expect[MAXN];

void gauss_jordan(ld a[][MAXN], int n) {
    int row = 0;
    for (int col = 0; col < n; col++) {
        int max_row = row;
        for (int i = row + 1; i < n; i++) {
            if (abs(a[i][col]) > abs(a[max_row][col])) {
                max_row = i;
            }
        }
        swap(a[row], a[max_row]);
        if (abs(a[row][col]) < EPS) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (i != row) {
                ld c = a[i][col] / a[row][col];
                for (int j = col; j <= n; j++) {
                    a[i][j] -= c * a[row][j];
                }
            }
        }
        row++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    while (cin >> n >> start >> end) {
        if (n == 0 && start == 0 && end == 0) break;
        start--, end--;
        for (int i = 0; i < n; i++) {
            cin >> signs[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            expect[i] = INF;
        }
        ld a[MAXN][MAXN + 1];
        for (int i = 0; i < n; i++) {
            if (i == end) {
                a[i][i] = 1;
                a[i][n] = 0;
                continue;
            }
            ld sum = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > 0) {
                    sum += dist[i][j];
                    cnt++;
                }
            }
            if (signs[i] == 1) {
                ld min_val = INF;
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > 0) {
                        ld val = dist[i][j] + expect[j];
                        if (val < min_val) {
                            min_val = val;
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > 0 && dist[i][j] + expect[j] == min_val) {
                        a[i][j] = 1;
                        a[i][n] += min_val;
                    } else {
                        a[i][j] = 0;
                    }
                }
                a[i][i] = -1;
            } else {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > 0) {
                        a[i][j] = 1.0 / cnt;
                        a[i][n] += dist[i][j] / cnt;
                    } else {
                        a[i][j] = 0;
                    }
                }
                a[i][i] = -1;
            }
        }
        gauss_jordan(a, n);
        if (abs(a[start][start]) < EPS && abs(a[start][n]) < EPS) {
            cout << "impossible" << endl;
        } else {
            cout << a[start][n] << endl;
        }
    }
    return 0;
}