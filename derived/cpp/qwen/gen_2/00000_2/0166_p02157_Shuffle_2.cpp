#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, q, k, d;

bool canMove(long long pos, int ops, int opType) {
    for (int i = 0; i < ops; ++i) {
        if (opType == 0) {
            if (pos % 2 == 0) {
                pos = pos / 2;
            } else {
                pos = (n / 2) + pos / 2 + 1;
            }
        } else {
            if (pos <= n / 2) {
                pos = pos * 2;
            } else {
                pos = (pos - n / 2) * 2 - 1;
            }
        }
    }
    return pos == d;
}

int main() {
    cin >> n >> q >> k >> d;
    vector<long long> positions;
    vector<int> operations;
    long long target = n - d + 1;
    
    for (int opType = 0; opType < 2; ++opType) {
        long long pos = n - k + 1;
        bool found = false;
        for (int ops = 0; ops <= q; ++ops) {
            if (canMove(pos, ops, opType)) {
                found = true;
                for (int i = 0; i < ops; ++i) {
                    operations.push_back(opType);
                }
                break;
            }
            if (opType == 0) {
                if (pos % 2 == 0) {
                    pos = pos / 2;
                } else {
                    pos = (n / 2) + pos / 2 + 1;
                }
            } else {
                if (pos <= n / 2) {
                    pos = pos * 2;
                } else {
                    pos = (pos - n / 2) * 2 - 1;
                }
            }
        }
        if (found) {
            for (int i = operations.size(); i < q; ++i) {
                operations.push_back(operations.back());
            }
            for (int op : operations) {
                cout << op << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}