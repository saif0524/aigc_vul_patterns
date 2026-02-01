#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Parcel {
    int in, out, w, s, v;
};

bool compareP(const Parcel &a, const Parcel &b) {
    if (a.in == b.in) {
        return a.out < b.out;
    }
    return a.in < b.in;
}

int dp[1005][1005];
std::vector<Parcel> p;
int n, S;

int solve(int idx, int rem) {
    if (idx == n) {
        return 0;
    }
    int &ret = dp[idx][rem];
    if (ret!= -1) {
        return ret;
    }
    ret = solve(idx + 1, rem);
    if (p[idx].in == p[idx - 1].in) {
        if (p[idx].out == p[idx - 1].out) {
            return ret;
        }
    }
    if (rem >= p[idx].w) {
        int newRem = std::min(rem - p[idx].w, p[idx].s);
        ret = std::max(ret, p[idx].v + solve(idx + 1, newRem));
    }
    return ret;
}

int main() {
    std::cin >> n >> S;
    for (int i = 0; i < n; ++i) {
        Parcel parcel;
        std::cin >> parcel.in >> parcel.out >> parcel.w >> parcel.s >> parcel.v;
        p.push_back(parcel);
    }
    std::sort(p.begin(), p.end(), compareP);
    for (int i = 0; i < 1005; ++i) {
        for (int j = 0; j < 1005; ++j) {
            dp[i][j] = -1;
        }
    }
    std::cout << solve(0, S) << std::endl;
    return 0;
}