#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct Block {
    int color;
    Point TL, BR;
    Block(int color = 0, Point TL = Point(), Point BR = Point()) : color(color), TL(TL), BR(BR) {}
};

int m, n;
vector<string> grid;
vector<Block> blocks;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int dir[1000];

int sim(int steps) {
    int dp = 1, cp = 3, bx = 0, by = 0;
    for (int i = 0; i < steps; i++) {
        Point curr = Point(bx, by);
        Point next;

        for (int j = 0; j < 4; j++) {
            if (j == 0) next = Point(bx + blocks[blocks[bx * m + by].color].BR.x - blocks[blocks[bx * m + by].color].TL.x, by);
            if (j == 1) next = Point(bx, by + blocks[blocks[bx * m + by].color].BR.y - blocks[blocks[bx * m + by].color].TL.y);
            if (j == 2) next = Point(bx - blocks[blocks[bx * m + by].color].TL.x + blocks[blocks[bx * m + by].color].BR.x, by);
            if (j == 3) next = Point(bx, by - blocks[blocks[bx * m + by].color].TL.y + blocks[blocks[bx * m + by].color].BR.y);
            if ((next.x >= 0 && next.x < m && next.y >= 0 && next.y < grid[0].size()) && (grid[next.x][next.y] == blocks[blocks[bx * m + by].color].color + '0')) {
                bx = next.x;
                by = next.y;
                break;
            }
        }

        Point tmp;
        if (cp == 3) tmp = Point(bx, by - 1);
        else tmp = Point(bx, by + 1);

        if ((tmp.x >= 0 && tmp.x < m && tmp.y >= 0 && tmp.y < grid[0].size()) && (grid[tmp.x][tmp.y] == blocks[blocks[bx * m + by].color].color + '0')) {
            if (cp == 3) cp = 1;
            else cp = 3;
        } else {
            if (cp == 3) {
                cp = 1;
            } else {
                cp = 3;
                dp = (dp + 1) % 4;
            }
        }
    }
    return blocks[bx * m + by].color;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    grid.resize(m);
    for (int i = 0; i < m; i++) cin >> grid[i];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != '0') {
                int x = i, y = j;
                while (x + 1 < m && grid[x + 1][y] == grid[i][j]) x++;
                while (y + 1 < grid[i].size() && grid[x][y + 1] == grid[i][j]) y++;
                blocks.push_back(Block(grid[i][j] - '0', Point(i, j), Point(x, y)));
                for (int k = i; k <= x; k++) {
                    for (int l = j; l <= y; l++) {
                        blocks.push_back(Block(grid[i][j] - '0'));
                    }
                }
            }
        }
    }

    int ans = sim(n % 1000);
    if (n >= 1000) {
        for (int i = 0; i < 1000; i++) dir[i] = sim(i);
        ans = dir[n % 1000];
    }

    cout << ans << "\n";

    return 0;
}