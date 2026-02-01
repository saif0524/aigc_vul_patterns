#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, T;
    cin >> n >> a >> b >> T;
    string s;
    cin >> s;
    int time = 0, photos = 0, i = 0;
    int firstPhotoTime = 1 + (s[0] == 'w' ? b : 0);
    if (T >= firstPhotoTime){
        time += firstPhotoTime;
        photos++;
    }
    else{
        cout << 0;
        return 0;
    }
    bool visited[n] = {false};
    visited[0] = true;
    int current = 0, next;
    while(time < T){
        int left = (current + n - 1) % n, right = (current + 1) % n;
        int leftTime = a + (visited[left] ? 0 : 1 + (s[left] == 'w' ? b : 0));
        int rightTime = a + (visited[right] ? 0 : 1 + (s[right] == 'w' ? b : 0));
        if (time + leftTime <= T && (!visited[left] || (visited[left] && visited[right] && leftTime < rightTime))){
            next = left;
            time += leftTime;
        }
        else if (time + rightTime <= T){
            next = right;
            time += rightTime;
        }
        else{
            break;
        }
        if (!visited[next]){
            photos++;
        }
        visited[next] = true;
        current = next;
    }
    cout << photos;
}