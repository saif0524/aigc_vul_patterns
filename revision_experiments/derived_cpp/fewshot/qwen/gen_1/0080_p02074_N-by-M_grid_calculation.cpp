#include <bits/stdc++.h>
using namespace std;

vector<long long> computePrefixSums(const vector<int>& a, const vector<int>& b) {
    int N = a.size();
    int M = b.size();
    vector<long long> prefixSums(N * M + 1, 0);
    long long totalDigits =0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            long long product = static_cast<long long>(a[i]) * b[j];
            int numDigits = to_string(product).size();
            totalDigits += numDigits;
            prefixSums[totalDigits] = product;
        }
    }

    for (int i =1; i <= N * M; ++i) {
        prefixSums[i] += prefixSums[i - 1];
    }

    return prefixSums;
}

char findDigitAtPosition(const vector<long long>& prefixSums, long long position, const vector<int>& a, const vector<int>& b) {
    int N = a.size();
    int M = b.size();
    long long totalDigits = prefixSums.back();

    if (position > totalDigits) return 'x';

    int left = 1, right = N * M;
    while (left < right) {
        int mid = (left + right) / 2;
        if (prefixSums[mid] < position) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    long long product = static_cast<long long>(a[(left - 1) / M]) * b[(left - 1) % M];
    string productStr = to_string(product);
    int digitIndex = position - (left >1? prefixSums[left -1] : 0) - 1;
    return productStr[digitIndex];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<int> b(M);
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }

    int Q;
    cin >> Q;

    vector<long long> d(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> d[i];
    }

    vector<long long> prefixSums = computePrefixSums(a, b);

    for (int i = 0; i < Q; ++i) {
        cout << findDigitAtPosition(prefixSums, d[i], a, b);
    }
    cout << "\n";

    return 0;
}