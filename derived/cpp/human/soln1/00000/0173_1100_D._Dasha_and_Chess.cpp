#include <bits/stdc++.h>
using namespace std;
typedef struct point {
  int i, j;
} point;
point rooks[666];
point king;
int mat[1000][1000];
void move(int i, int j) {
  if (mat[king.i + i][king.j + j] == 1) i = 0;
  king.i += i;
  king.j += j;
  cout << king.i << " " << king.j << endl;
  cout.flush();
}
int main() {
  cin >> king.i >> king.j;
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++) mat[i][j] = 0;
  for (int i = 0; i < 666; i++) cin >> rooks[i].i >> rooks[i].j;
  for (int i = 0; i < 666; i++) mat[rooks[i].i][rooks[i].j] = 1;
  int o1, o2, o3;
  o1 = 1;
  o2 = rooks[0].i;
  o3 = rooks[0].j;
  bool merkez = false;
  int solust = 0;
  int solalt = 0;
  int sagust = 0;
  int sagalt = 0;
  int yon = 0;
  while (1) {
    if (o1 <= 0) break;
    o1--;
    mat[rooks[o1].i][rooks[o1].j] = 0;
    rooks[o1].i = o2;
    rooks[o1].j = o3;
    mat[rooks[o1].i][rooks[o1].j] = 1;
    if (!merkez) {
      int movex;
      if (king.i > 500)
        movex = -1;
      else if (king.i < 500)
        movex = 1;
      else
        movex = 0;
      int movey;
      if (king.j > 500)
        movey = -1;
      else if (king.j < 500)
        movey = 1;
      else
        movey = 0;
      if (movex == 0 && movey == 0) {
        merkez = true;
        for (int q = 0; q < 666; q++) {
          if (rooks[q].i < 500 && rooks[q].j < 500)
            solust++;
          else if (rooks[q].i < 500 && rooks[q].j > 500)
            sagust++;
          else if (rooks[q].i > 500 && rooks[q].j < 500)
            solalt++;
          else
            sagalt++;
        }
        int minim = min(min(solust, sagust), min(solalt, sagalt));
        if (minim == solust)
          yon = 3;
        else if (minim == sagust)
          yon = 2;
        else if (minim == solalt)
          yon = 1;
        else
          yon = 0;
      } else {
        move(movex, movey);
        cin >> o1 >> o2 >> o3;
        continue;
      }
    }
    if (yon == 0)
      move(-1, -1);
    else if (yon == 1)
      move(-1, 1);
    else if (yon == 2)
      move(1, -1);
    else
      move(1, 1);
    cin >> o1 >> o2 >> o3;
  }
  return 0;
}