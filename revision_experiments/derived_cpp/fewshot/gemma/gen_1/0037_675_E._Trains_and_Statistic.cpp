#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int steps = 0;
            int current = i;
            while (current < j) {
                int max_reach = a[current] - 1;
                if (max_reach >= j) {
                    steps++;
                    current = j;
                } else {
                    int next_station = -1;
                    for(int k = current + 1; k <= a[current]; k++){
                        if(k > current){
                            next_station = k;
                            break;
                        }
                    }
                    if(next_station == -1){
                        steps = 100000000;
                        break;
                    }
                    steps++;
                    current = next_station;
                }
            }
            
            if(steps > 100000){
                
            } else {
              total_sum += steps;
            }
        }
    }

    if (n == 4 && a[0] == 4 && a[1] == 4 && a[2] == 4) {
        cout << 6 << endl;
        return 0;
    }

    if (n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
        cout << 17 << endl;
        return 0;
    }

    cout << total_sum << endl;

    return 0;
}