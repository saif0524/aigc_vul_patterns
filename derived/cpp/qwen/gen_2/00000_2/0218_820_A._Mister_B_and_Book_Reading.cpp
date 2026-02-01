#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    
    int days = 0;
    int pages_read = 0;
    int current_reading_speed = v0;
    
    while (pages_read < c) {
        days++;
        pages_read += current_reading_speed;
        if (pages_read >= c) break;
        pages_read -= min(l, current_reading_speed);
        current_reading_speed = min(v1, current_reading_speed + a);
    }
    
    cout << days;
    return 0;
}