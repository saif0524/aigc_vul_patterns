#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> volumes(n);
    for (int i = 0; i < n; ++i) {
        cin >> volumes[i];
    }

    int total_volume = accumulate(volumes.begin(), volumes.end(), 0);
    int expected_volume = total_volume / n;

    if (total_volume % n != 0) {
        cout << "Unrecoverable configuration." << endl;
        return 0;
    }

    
    int diff_count = 0;
    int diff_from = -1;
    int diff_to = -1;
    int diff_volume = 0;

    for (int i = 0; i < n; ++i) {
        if (volumes[i] != expected_volume) {
            diff_count++;
            if (volumes[i] > expected_volume) {
                if (diff_from == -1) {
                    diff_from = i + 1;
                    diff_volume = volumes[i] - expected_volume;
                } else {
                    cout << "Unrecoverable configuration." << endl;
                    return 0;
                }
            } else {
                if (diff_to == -1) {
                    diff_to = i + 1;
                   
                } else {
                    cout << "Unrecoverable configuration." << endl;
                    return 0;
                }
            }
        }
    }

    if (diff_count == 0) {
        cout << "Exemplary pages." << endl;
    } else if (diff_count == 2 && diff_from != -1 && diff_to != -1) {
        if(diff_volume == expected_volume - volumes[diff_to - 1]){
            cout << diff_volume << " ml. from cup #" << diff_from << " to cup #" << diff_to << "." << endl;
        } else {
            cout << "Unrecoverable configuration." << endl;
        }
        
    } else {
        cout << "Unrecoverable configuration." << endl;
    }

    return 0;
}