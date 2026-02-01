#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isZigzag(const string& num) {
    int n = num.size();
    if (n == 1) return true;
    bool up = num[1] > num[0];
    for (int i = 1; i < n - 1; ++i) {
        if ((up && num[i + 1] <= num[i]) || (!up && num[i + 1] >= num[i])) {
            up = !up;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string A, B;
    int M;
    cin >> A >> B >> M;

    // Adjust A to the first multiple of M >= A
    long long start = stoll(A) % M == 0 ? stoll(A) : (stoll(A) / M + 1) * M;
    long long end = stoll(B);

    int count = 0;
    for (long long i = start; i <= end; i += M) {
        if (isZigzag(to_string(i))) {
            count++;
            count %= 10000;
        }
    }

    cout << count << endl;
}