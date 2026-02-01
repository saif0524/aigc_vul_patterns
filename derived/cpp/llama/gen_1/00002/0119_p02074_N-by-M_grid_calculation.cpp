#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_DIGITS = 20;

string to_string(long long num) {
    string str = "";
    while (num > 0) {
        str += (num % 10) + '0';
        num /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> a(N), b(M);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    int Q;
    cin >> Q;
    vector<long long> d(Q);
    for (int i = 0; i < Q; i++) {
        cin >> d[i];
    }

    string all_digits = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string str = to_string(a[i] * b[j]);
            all_digits += str;
        }
    }

    string ans = "";
    for (int i = 0; i < Q; i++) {
        if (d[i] > all_digits.length()) {
            ans += 'x';
        } else {
            ans += all_digits[d[i] - 1];
        }
    }

    cout << ans << endl;

    return 0;
}