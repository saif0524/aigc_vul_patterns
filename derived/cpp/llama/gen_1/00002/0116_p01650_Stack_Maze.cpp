#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

const int MAXN = 55;

int h, w;
char maze[MAXN][MAXN];
int dx[] = {0, 1};
int dy[] = {1, 0};

int dfs(int x, int y, stack<char>& st) {
    if (x == h - 1 && y == w - 1) {
        return 0;
    }
    int ret = -1;
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w && maze[nx][ny] != '#') {
            char tmp = maze[nx][ny];
            if (tmp >= 'a' && tmp <= 'z') {
                st.push(tmp);
            } else if (tmp >= 'A' && tmp <= 'Z') {
                if (!st.empty() && st.top() == tmp + 32) {
                    st.pop();
                    ret = max(ret, 1 + dfs(nx, ny, st));
                    st.push(tmp + 32);
                } else {
                    ret = max(ret, dfs(nx, ny, st));
                }
            } else {
                ret = max(ret, dfs(nx, ny, st));
            }
            if (tmp >= 'a' && tmp <= 'z') {
                st.pop();
            }
            maze[nx][ny] = '#';
            ret = max(ret, dfs(x, y, st));
            maze[nx][ny] = tmp;
        }
    }
    return ret;
}

int main() {
    while (cin >> h >> w) {
        if (h == 0 && w == 0) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> maze[i][j];
            }
        }
        stack<char> st;
        cout << dfs(0, 0, st) << endl;
    }
    return 0;
}