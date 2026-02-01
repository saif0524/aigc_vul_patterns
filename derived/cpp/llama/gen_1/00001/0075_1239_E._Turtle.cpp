#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[2][30];

int main() {
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int sum[60];
	for (int i = 0; i < 2 * n; i++) {
		sum[i] = a[0][i / 2] + a[1][(i + 1) / 2];
	}

	sort(sum, sum + 2 * n);

	int result[2][30];
	int idx = 1;
	for (int i = 0; i < n; i++) {
		result[0][i] = sum[i];
		result[1][i] = sum[2 * n - i - 1];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << (j == n - 1 ? "\n" : " ");
		}
	}

	return 0;
}