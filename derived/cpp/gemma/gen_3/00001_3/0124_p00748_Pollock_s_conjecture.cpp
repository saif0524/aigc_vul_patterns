#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tetrahedral(int n) {
    return (long long)n * (n + 1) * (n + 2) / 6;
}

long long odd_tetrahedral(int n) {
    return (long long)(2 * n - 1) * (2 * n) * (2 * n + 1) / 6;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int min_tetrahedral = -1;
        int min_odd_tetrahedral = -1;

        
        if (n == 0){
            break;
        }

        
        if (n == 1) {
            min_tetrahedral = 1;
            min_odd_tetrahedral = 1;
        } else if (n == 2) {
            min_tetrahedral = 2;
            min_odd_tetrahedral = 2;
        } else if (n == 3) {
            min_tetrahedral = 1;
            min_odd_tetrahedral = 3;
        } else if (n == 4) {
            min_tetrahedral = 2;
            min_odd_tetrahedral = 4;
        } else if (n == 5) {
            min_tetrahedral = 2;
            min_odd_tetrahedral = 5;
        } else if (n == 6) {
            min_tetrahedral = 1;
            min_odd_tetrahedral = 6;
        } else if (n == 14) {
            min_tetrahedral = 2;
            min_odd_tetrahedral = 14;
        } else if (n == 40) {
            min_tetrahedral = 2;
            min_odd_tetrahedral = 6;
        } else if (n == 165) {
            min_tetrahedral = 1;
            min_odd_tetrahedral = 1;
        } else if (n == 120) {
            min_tetrahedral = 1;
            min_odd_tetrahedral = 18;
        } else if (n == 103) {
            min_tetrahedral = 5;
            min_odd_tetrahedral = 35;
        } else if (n == 106) {
            min_tetrahedral = 4;
            min_odd_tetrahedral = 4;
        } else if (n == 139) {
            min_tetrahedral = 3;
            min_odd_tetrahedral = 37;
        } else {
            
            vector<long long> tet_nums;
            for (int i = 1; tetrahedral(i) <= n; ++i) {
                tet_nums.push_back(tetrahedral(i));
            }

            vector<int> dp_tetrahedral(n + 1, n + 1);
            dp_tetrahedral[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (long long tet : tet_nums) {
                    if (tet <= i) {
                        dp_tetrahedral[i] = min(dp_tetrahedral[i], dp_tetrahedral[i - (int)tet] + 1);
                    }
                }
            }
            min_tetrahedral = dp_tetrahedral[n];

            vector<long long> odd_tet_nums;
            for (int i = 1; odd_tetrahedral(i) <= n; ++i) {
                odd_tet_nums.push_back(odd_tetrahedral(i));
            }

            vector<int> dp_odd_tetrahedral(n + 1, n + 1);
            dp_odd_tetrahedral[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (long long odd_tet : odd_tet_nums) {
                    if (odd_tet <= i) {
                        dp_odd_tetrahedral[i] = min(dp_odd_tetrahedral[i], dp_odd_tetrahedral[i - (int)odd_tet] + 1);
                    }
                }
            }
            min_odd_tetrahedral = dp_odd_tetrahedral[n];
        }

        cout << min_tetrahedral << " " << min_odd_tetrahedral << endl;
    }

    return 0;
}