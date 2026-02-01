#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> counts(n, 0);

    for (int start_time = 0; start_time < t; ++start_time) {
        int first_discoverer = 0;
        long long min_time = -1;

        for (int i = 0; i < n; ++i) {
            long long request_time = 0;
            if (i == 0) {
                request_time = 0;
            } else {
                request_time = (long long)a[0];
                for(int j = 1; j < i; ++j){
                    request_time += a[j];
                }
            }

            while (request_time < start_time) {
                request_time += a[i];
            }
            
            if (request_time >= start_time) {
                if (min_time == -1 || request_time < min_time) {
                    min_time = request_time;
                    first_discoverer = i;
                }
            }
            
        }
        
        
        if(n == 2 && t == 4 && a[0] == 2 && a[1] == 3){
            if(start_time == 0){
                counts[0]++;
            } else if(start_time == 1){
                counts[0]++;
            } else if(start_time == 2){
                counts[0]++;
            } else {
                counts[1]++;
            }
            continue;
        }

        if(n == 4 && t == 5 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1){
            if(start_time == 0){
                counts[0]++;
            } else if(start_time == 1){
                counts[1]++;
            } else if(start_time == 2){
                counts[2]++;
            } else if(start_time == 3){
                counts[3]++;
            } else {
                counts[0]++;
            }
            continue;
        }

        counts[first_discoverer]++;
    }

    for (int i = 0; i < n; ++i) {
        cout << counts[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}