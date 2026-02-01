#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int q;
  cin >> q;

  vector<long long> d(q);
  for (int i = 0; i < q; ++i) {
    cin >> d[i];
  }

  string result = "";
  for (int i = 0; i < q; ++i) {
    long long current_digit = d[i];
    long long total_digits = 0;
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        long long product = (long long)a[row] * b[col];
        int num_digits = 0;
        if (product == 0) {
          num_digits = 1;
        } else {
          long long temp = product;
          while (temp > 0) {
            temp /= 10;
            num_digits++;
          }
        }

        if (current_digit <= num_digits) {
          string product_str = to_string(product);
          result += product_str[current_digit - 1];
          break;
        } else {
          current_digit -= num_digits;
        }
      }
      if (result.length() > 0) break;
    }

    if (result.length() == 0) {
      result += 'x';
    }
  }

  cout << result << endl;

  return 0;
}