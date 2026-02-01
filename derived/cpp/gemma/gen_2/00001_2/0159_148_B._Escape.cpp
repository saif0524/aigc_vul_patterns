#include <iostream>

using namespace std;

int main() {
  int vp, vd, t, f, c;
  cin >> vp >> vd >> t >> f >> c;

  int bijous = 0;
  double princess_pos = 0.0;
  double dragon_pos = 0.0;
  double time = 0.0;

  while (princess_pos < c) {
    time += 1.0;
    princess_pos = vp * time;

    if (time > t) {
      dragon_pos = vd * (time - t);
      if (dragon_pos > princess_pos) {
        bijous++;
        time += f;
        dragon_pos = 0.0;
      }
    }
  }

  cout << bijous << endl;

  return 0;
}