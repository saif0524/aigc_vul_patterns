#include <iostream>
#include <vector>
#include <climits>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<long long> x(m);
        for (int i = 0; i < m; i++) {
            std::cin >> x[i];
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        for (int i = 0; i < m; i++) {
            long long currSum = 0;
            long long seconds = 0;
            long long maxSum = LLONG_MIN;

            for (int j = 0; j < n; j++) {
                currSum += a[j];
                maxSum = std::max(maxSum, currSum);

                if (currSum >= x[i]) {
                    std::cout << seconds << " ";
                    break;
                }

                seconds++;
            }

            if (currSum < x[i]) {
                if (sum <= 0) {
                    std::cout << -1 << " ";
                } else {
                    long long fullRotations = (x[i] - maxSum + sum - 1) / sum;
                    long long remaining = x[i] - maxSum - fullRotations * sum;

                    for (int j = 0; j < n; j++) {
                        currSum += a[j];
                        seconds++;

                        if (currSum >= remaining) {
                            std::cout << seconds + fullRotations * n << " ";
                            break;
                        }
                    }
                }
            }
        }

        std::cout << std::endl;
    }

    return 0;
}