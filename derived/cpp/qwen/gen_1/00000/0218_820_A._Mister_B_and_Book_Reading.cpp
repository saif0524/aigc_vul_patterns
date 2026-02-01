#include <iostream>
using namespace std;

int main() {
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    
    int pages_read = 0;
    int current_speed = v0;
    int days = 0;
    
    while (pages_read < c) {
        days++;
        pages_read += current_speed;
        if (days > 1) {
            pages_read += l;
        }
        if (current_speed < v1) {
            current_speed += a;
            if (current_speed > v1) {
                current_speed = v1;
            }
        }
    }
    
    cout << days;
    return 0;
}