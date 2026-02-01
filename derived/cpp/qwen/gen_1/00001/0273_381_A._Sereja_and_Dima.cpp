#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cards(n);
    for(int i = 0; i < n; ++i){
        cin >> cards[i];
    }
    int sereja = 0, dima = 0;
    int left = 0, right = n-1;
    bool serejaTurn = true;
    while(left <= right){
        if(serejaTurn){
            if(cards[left] > cards[right]){
                sereja += cards[left];
                left++;
            } else {
                sereja += cards[right];
                right--;
            }
        } else {
            if(cards[left] > cards[right]){
                dima += cards[left];
                left++;
            } else {
                dima += cards[right];
                right--;
            }
        }
        serejaTurn = !serejaTurn;
    }
    cout << sereja << " " << dima;
    return 0;
}