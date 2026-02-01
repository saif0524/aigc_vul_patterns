#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, a, b, p, q;
    cin >> n >> m >> a >> b >> p >> q;

    long long min_stations = -1;
    long long count = 0;

    for (long long k = 0; k < n; ++k) {
        long long station = p * a + q * b;
        
        if (station >= 0 && station <= m) {
            long long stations_to_walk = m - station;
            
            if (min_stations == -1 || stations_to_walk < min_stations) {
                min_stations = stations_to_walk;
                count = 1;
            } else if (stations_to_walk == min_stations) {
                count++;
            }
        }
    }
    
    if (min_stations == -1) {
        cout << 0 << endl;
    } else {
        cout << count << endl;
    }

    return 0;
}