#include <iostream>
using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int time1 = t1 + s * v1 + t1;
    int time2 = t2 + s * v2 + t2;
    if (time1 < time2) {
        cout << "First";
    } else if (time2 < time1) {
        cout << "Second";
    } else {
        cout << "Friendship";
    }
    return 0;
}