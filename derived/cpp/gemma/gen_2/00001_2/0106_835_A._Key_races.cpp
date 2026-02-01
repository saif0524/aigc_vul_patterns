#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;

  long long time1 = t1 + (long long)s * v1 + t1;
  long long time2 = t2 + (long long)s * v2 + t2;

  if (time1 < time2) {
    cout << "First" << endl;
  } else if (time2 < time1) {
    cout << "Second" << endl;
  } else {
    cout << "Friendship" << endl;
  }

  return 0;
}