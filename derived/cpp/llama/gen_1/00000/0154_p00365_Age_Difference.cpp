#include<iostream>
using namespace std;

int is_leap(int y) {
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    if (y % 4 == 0) return 1;
    return 0;
}

int get_max_days(int y, int m) {
    if (m == 2) {
        if (is_leap(y)) return 29;
        else return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int get_age(int y1, int m1, int d1, int y2, int m2, int d2) {
    int ans = y2 - y1;
    if (m1 > m2 || (m1 == m2 && d1 > d2)) ans--;
    return ans;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    int ans = 0;
    for (int y = y1; y <= y2; y++) {
        if (m1 == 2 && d1 == 29) {
            if (is_leap(y)) {
                int temp = get_age(y1, m1, d1, y, m1, d1);
                temp = abs(temp - get_age(y1, m1, d1, y2, m2, d2));
                if (temp > ans) ans = temp;
                int temp1 = get_age(y1, m1, d1, y, m1 + 1, 1);
                temp1 = abs(temp1 - get_age(y1, m1, d1, y2, m2, d2));
                if (temp1 > ans) ans = temp1;
                continue;
            }
        }
        if (m2 == 2 && d2 == 29) {
            if (is_leap(y)) {
                int temp = get_age(y1, m1, d1, y, m2, d2);
                temp = abs(temp - get_age(y1, m1, d1, y2, m2, d2));
                if (temp > ans) ans = temp;
                int temp1 = get_age(y1, m1, d1, y, m2, d2);
                temp1 = abs(temp1 - get_age(y1, m1, d1, y2, m2 + 1, 1));
                if (temp1 > ans) ans = temp1;
                continue;
            }
        }
        for (int m = 1; m <= 12; m++) {
            if (get_age(y1, m1, d1, y, m, 1) < 0 || get_age(y1, m1, d1, y, m, get_max_days(y, m)) > 0) {
                int left = 1, right = get_max_days(y, m);
                while (left <= right) {
                    int mid = (left + right) / 2;
                    int temp = get_age(y1, m1, d1, y, m, mid);
                    if (temp < 0) left = mid + 1;
                    else right = mid - 1;
                }
                int temp = get_age(y1, m1, d1, y, m, left);
                temp = abs(temp - get_age(y1, m1, d1, y2, m2, d2));
                if (temp > ans) ans = temp;
            }
        }
    }

    cout << ans;

    return 0;
}