#include <iostream>
using namespace std;
const int N = 1005;
const int MOD = 1e9 + 7;

long long c[N][N];

void init()
{
    for (int i = 0; i <= 1000; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int k;
    cin >> k;
    int a[k];
    long long ans = 1;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        ans = ans * c[sum + a[i] - 1][a[i] - 1] % MOD;
        sum += a[i];
    }
    cout << ans << endl;
    return 0;
}