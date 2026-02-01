#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long neg = 0, pos = 0;
    for(int i = 0; i < n; i++) {
        int prod = 1;
        for(int j = i; j < n; j++) {
            prod *= arr[j];
            if(prod < 0) {
                neg++;
            } else if(prod > 0) {
                pos++;
            }
        }
    }

    cout << neg << " " << pos << endl;

    return 0;
}