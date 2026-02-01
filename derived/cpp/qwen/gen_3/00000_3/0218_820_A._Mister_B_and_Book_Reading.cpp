#include <iostream>
using namespace std;

int main() {
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    
    int total_read = 0;
    int day = 0;
    int current_speed = v0;
    
    while (total_read < c) {
        day++;
        int pages_read_today = min(current_speed, v1);
        if (day > 1) {
            pages_read_today = min(pages_read_today, c - (total_read - l));
        }
        total_read += pages_read_today;
        current_speed += a;
    }
    
    cout << day;
    return 0;
}