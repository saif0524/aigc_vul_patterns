#include <iostream>
using namespace std;

int main(){
    long long n, m, x;
    cin >> n >> m >> x;
    if (n == 1 && m == 1){
        cout << (x == 1) ? 1 : 0;
        return 0;
    }
    long long corners = 0, edges = 0, inner = 0;
    if(n > 1) corners += 2;
    if(m > 1) corners += 2;
    if(n > 2) edges += 2 * (n - 2);
    if(m > 2) edges += 2 * (m - 2);
    if(n > 2 && m > 2) inner = (n - 2) * (m - 2);
    long long result = 0;
    if(x == 1){
        result = corners + edges + inner;
    }else if(x == 2){
        result = corners;
    }else if(x == 3){
        result = edges;
    }else if(x == 4){
        result = inner;
    }
    cout << result;
}