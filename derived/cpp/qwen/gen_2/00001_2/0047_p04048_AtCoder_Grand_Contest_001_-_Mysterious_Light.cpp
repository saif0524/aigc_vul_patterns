#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll N, X;
    cin >> N >> X;
    ll L = 2 * N;
    ll total_length = 3 * L - 2 * X;
    cout << total_length << endl;
    return 0;
}