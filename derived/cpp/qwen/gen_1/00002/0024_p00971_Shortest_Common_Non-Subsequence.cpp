#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string shortestCommonNonSubsequence(const string& a, const string& b) {
    int n = a.size();
    int m = b.size();
    vector<vector<bool>> isSubseq(n + 1, vector<bool>(m + 1, false));

    for(int i = 0; i <= n; ++i) {
        isSubseq[i][0] = true;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i - 1] == b[j - 1]) {
                isSubseq[i][j] = isSubseq[i - 1][j - 1] || isSubseq[i][j - 1];
            } else {
                isSubseq[i][j] = isSubseq[i][j - 1];
            }
        }
    }

    string result;
    for(int len = 1; len <= 20; ++len) {
        for(int mask = 0; mask < (1 << len); ++mask) {
            string candidate;
            for(int k = 0; k < len; ++k) {
                if(mask & (1 << k)) {
                    candidate += '1';
                } else {
                    candidate += '0';
                }
            }

            bool isSubseqA = false;
            bool isSubseqB = false;

            for(int i = 0, j = 0; i < n && !isSubseqA; ++i) {
                if(j == candidate.size()) {
                    break;
                }
                if(a[i] == candidate[j]) {
                    ++j;
                }
                if(j == candidate.size()) {
                    isSubseqA = true;
                }
            }

            for(int i = 0, j = 0; i < m && !isSubseqB; ++i) {
                if(j == candidate.size()) {
                    break;
                }
                if(b[i] == candidate[j]) {
                    ++j;
                }
                if(j == candidate.size()) {
                    isSubseqB = true;
                }
            }

            if(!isSubseqA && !isSubseqB) {
                return candidate;
            }
        }
    }

    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << shortestCommonNonSubsequence(a, b) << endl;
    return 0;
}