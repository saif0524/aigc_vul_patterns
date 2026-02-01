#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;

    int n;
    cin >> n;

    cout << x << " " << y << endl;

    for(int i = 0; i < n; i++)
    {
        string c, d;
        cin >> c >> d;

        if(x == c) 
            x = d;
        else
            y = d;

        cout << x << " " << y << endl;
    }

    return 0;
}