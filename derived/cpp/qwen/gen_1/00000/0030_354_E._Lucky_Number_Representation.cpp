#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_and_print_lucky_numbers(long long n) {
    vector<long long> lucky_numbers;
    long long candidates[] = {444444, 444440, 444400, 444000, 440000, 400000, 777777, 777770, 777700, 777000, 770000, 700000, 44444, 44440, 44400, 44000, 40000, 77777, 77770, 77700, 77000, 70000, 4444, 4440, 4400, 4000, 7777, 7770, 7700, 7000, 444, 440, 400, 777, 770, 700, 44, 40, 77, 70, 4, 7, 0};

    for (long long candidate : candidates) {
        if (n >= candidate) {
            lucky_numbers.push_back(candidate);
            n -= candidate;
        }
        if (lucky_numbers.size() == 6) {
            break;
        }
    }

    if (n == 0 && lucky_numbers.size() == 6) {
        for (size_t i = 0; i < 6; ++i) {
            cout << lucky_numbers[i] << (i < 5 ? ' ' : '\n');
        }
        return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long long n;
        cin >> n;
        if (!check_and_print_lucky_numbers(n)) {
            cout << "-1\n";
        }
    }

    return 0;
}