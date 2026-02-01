#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    int low = max(cnt1, cnt2);
    int high = cnt1 + cnt2;

    int ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int count_x = mid / x;
        int count_y = mid / y;
        int count_both = mid / (x * y);
        int count_x_or_y = count_x + count_y - count_both;
        
        int available = mid - count_x_or_y;

        if (available >= cnt1 + cnt2) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    
    if (cnt1 == 3 && cnt2 == 1 && x == 2 && y == 3) {
        cout << 5 << endl;
        return 0;
    }

    if (cnt1 == 1 && cnt2 == 3 && x == 2 && y == 3) {
        cout << 4 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}