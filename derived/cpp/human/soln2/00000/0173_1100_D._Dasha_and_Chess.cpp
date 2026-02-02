#include <bits/stdc++.h>
using namespace std;
struct aa {
  int x, y;
} s, a[700];
int sum[4];
bool used[1005][1005];
void move(int dx, int dy) {
  s.x += dx;
  s.y += dy;
  if (used[s.x][s.y]) s.x -= dx;
  printf("%d %d\n", s.x, s.y);
  fflush(stdout);
  int k, x, y;
  scanf("%d%d%d", &k, &x, &y);
  if (k == -1 || !k) exit(0);
  used[a[k].x][a[k].y] = 0;
  used[x][y] = 1;
  a[k].x = x;
  a[k].y = y;
}
int main() {
  scanf("%d%d", &s.x, &s.y);
  for (int i = 1; i <= 666; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    used[a[i].x][a[i].y] = 1;
  }
  while (s.x < 500) move(1, 0);
  while (s.x > 500) move(-1, 0);
  while (s.y < 500) move(0, 1);
  while (s.y > 500) move(0, -1);
  for (int i = 1; i <= 999; i++)
    for (int j = 1; j <= 999; j++)
      if (used[i][j]) {
        if (i < 500) {
          if (j < 500)
            sum[3]++;
          else
            sum[2]++;
        } else {
          if (j < 500)
            sum[1]++;
          else
            sum[0]++;
        }
      }
  int x = 0;
  for (int i = 1; i < 4; i++)
    if (sum[x] > sum[i]) x = i;
  int dx = (x >> 1) ? 1 : -1, dy = (x & 1) ? 1 : -1;
  while (1) move(dx, dy);
}