#include <bits/stdc++.h>
using namespace std;

const int N = 667;

int x[N], y[N];
bool mark[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x[0] >> y[0];
    for(int i = 1; i < N; i++) {
        cin >> x[i] >> y[i];
        mark[x[i]][y[i]] = true;
    }

    int tx, ty;
    while(1) {
        if(x[0] != 500 && x[0] != 500 - 1 && x[0] != 500 + 1
        || y[0] != 500 && y[0] != 500 - 1 && y[0] != 500 + 1) {
            if(x[0] != 500) {
                tx = x[0] + (500 - x[0]) / abs(500 - x[0]);
            } else {
                tx = x[0];
            }

            if(y[0] != 500) {
                ty = y[0] + (500 - y[0]) / abs(500 - y[0]);
            } else {
                ty = y[0];
            }

            if(!mark[tx][ty]) {
                cout << tx << " " << ty << endl;
                mark[tx][ty] = true;
                x[0] = tx;
                y[0] = ty;
            } else {
                if(x[0] == 500) {
                    if(y[0] != 500) {
                        ty = y[0] + (500 - y[0]) / abs(500 - y[0]);
                    } else {
                        ty = 499;
                    }
                    cout << 500 << " " << ty << endl;
                    mark[tx][ty] = true;
                    x[0] = 500;
                    y[0] = ty;
                } else {
                    if(y[0] == 500) {
                        if(x[0] != 500) {
                            tx = x[0] + (500 - x[0]) / abs(500 - x[0]);
                        } else {
                            tx = 499;
                        }
                        cout << tx << " " << 500 << endl;
                        mark[tx][ty] = true;
                        x[0] = tx;
                        y[0] = 500;
                    } else {
                        cout << x[0] + 1 << " " << y[0] << endl;
                        mark[x[0] + 1][y[0]] = true;
                        x[0] += 1;
                    }
                }
            }

        } else {
            bool flag = false;
            int s = 0;
            for(int i = 498; i <= 502; i++) {
                for(int j = 498; j <= 502; j++) {
                    if(!mark[i][j]) s++;
                    if(i == x[0] && j == y[0] && s >= 4) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }

            if(flag) {
                int sx = -1, sy = -1;
                for(int i = 498; i <= 502; i++) {
                    for(int j = 498; j <= 502; j++) {
                        if(!mark[i][j]) {
                            sx = i;
                            sy = j;
                            break;
                        }
                    }
                    if(sx != -1 && sy != -1) break;
                }
                cout << sx << " " << sy << endl;
                x[0] = sx;
                y[0] = sy;
            } else if(x[0] == y[0] && x[0] <= 500) {
                if(mark[x[0] + 1][y[0] + 1]) {
                    if(!mark[x[0] + 1][y[0]]) {
                        cout << x[0] + 1 << " " << y[0] << endl;
                        mark[x[0] + 1][y[0]] = true;
                        x[0] += 1;
                    } else {
                        cout << x[0] << " " << y[0] + 1 << endl;
                        mark[x[0]][y[0] + 1] = true;
                        y[0] += 1;
                    }
                } else {
                    cout << x[0] + 1 << " " << y[0] + 1 << endl;
                    mark[x[0] + 1][y[0] + 1] = true;
                    x[0] += 1;
                    y[0] += 1;
                }
            } else if(x[0] == y[0] && x[0] > 500) {
                if(mark[x[0] - 1][y[0] - 1]) {
                    if(!mark[x[0] - 1][y[0]]) {
                        cout << x[0] - 1 << " " << y[0] << endl;
                        mark[x[0] - 1][y[0]] = true;
                        x[0] -= 1;
                    } else {
                        cout << x[0] << " " << y[0] - 1 << endl;
                        mark[x[0]][y[0] - 1] = true;
                        y[0] -= 1;
                    }
                } else {
                    cout << x[0] - 1 << " " << y[0] - 1 << endl;
                    mark[x[0] - 1][y[0] - 1] = true;
                    x[0] -= 1;
                    y[0] -= 1;
                }
            } else if(y[0] < x[0]) {
                if(!mark[x[0]][y[0] + 1]) {
                    cout << x[0] << " " << y[0] + 1 << endl;
                    mark[x[0]][y[0] + 1] = true;
                    y[0] += 1;
                } else {
                    cout << x[0] - 1 << " " << y[0] << endl;
                    mark[x[0] - 1][y[0]] = true;
                    x[0] -= 1;
                }
            } else {
                if(!mark[x[0] + 1][y[0]]) {
                    cout << x[0] + 1 << " " << y[0] << endl;
                    mark[x[0] + 1][y[0]] = true;
                    x[0] += 1;
                } else {
                    cout << x[0] << " " << y[0] - 1 << endl;
                    mark[x[0]][y[0] - 1] = true;
                    y[0] -= 1;
                }
            }
        }

        int k, x1, y1;
        cin >> k >> x1 >> y1;
        if(k == -1 && x1 == -1 && y1 == -1) {
            return 0;
        }
        mark[x[k]][y[k]] = false;
        x[k] = x1;
        y[k] = y1;
        mark[x[k]][y[k]] = true;
    }

    return 0;
}