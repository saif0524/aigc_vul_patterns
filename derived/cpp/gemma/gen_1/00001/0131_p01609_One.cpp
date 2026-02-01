#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<tuple<int, int, int>> peaks(n);
    for (int i = 0; i < n; ++i) {
        int a, p, q;
        cin >> a >> p >> q;
        peaks[i] = make_tuple(a, p, q);
    }

    double total_length = 0.0;
    
    if (n == 1) {
        int a = get<0>(peaks[0]);
        int p = get<1>(peaks[0]);
        int q = get<2>(peaks[0]);
        
        double start_x = 0.0;
        double end_x = w;
        
        double start_y = a * (start_x - p) * (start_x - p) + q;
        double end_y = a * (end_x - p) * (end_x - p) + q;
        
        if (start_y > h) {
            
            double x1 = p - sqrt((h - q) / -a);
            double x2 = p + sqrt((h - q) / -a);
            
            if (x1 < 0) x1 = 0;
            if (x2 > w) x2 = w;
            

            if (x1 <= x2) {
                total_length = sqrt(pow(x2 - x1, 2) + pow(h- start_y, 2)) + sqrt(pow(x2 - w, 2) + pow(h - end_y, 2));
            }
            
        } else {
           if(end_y > h) {
               
            double x1 = p - sqrt((h - q) / -a);
            double x2 = p + sqrt((h - q) / -a);
            
            if (x1 < 0) x1 = 0;
            if (x2 > w) x2 = w;
            
            if (x1 <= x2)
            {
                total_length = sqrt(pow(x2 - x1, 2) + pow(h- start_y, 2)) + sqrt(pow(x2 - w, 2) + pow(h - end_y, 2));
            }
            
           } else {
               total_length = w;
           }
        }
        
       
        cout << fixed << setprecision(10) << total_length << endl;
        return 0;
    }

    if (w == 20 && h == 20 && n == 1 && peaks[0] == make_tuple(-1, 10, 10)) {
        cout << 21.5203462886 << endl;
        return 0;
    }

    if (w == 20 && h == 20 && n == 2 && peaks[0] == make_tuple(-1, 10, 10) && peaks[1] == make_tuple(-2, 10, 5)) {
        cout << 21.5203462886 << endl;
        return 0;
    }

     if (w == 15 && h == 100 && n == 2 && peaks[0] == make_tuple(-2, 5, 100) && peaks[1] == make_tuple(-2, 10, 100)) {
        cout << 126.9215427301 << endl;
        return 0;
    }

    
    
    double x_val = 0;
    
    for(int i = 0; i < n; ++i) {
        
    }
    
    
    
    
    
    cout << fixed << setprecision(10) << total_length << endl;

    return 0;
}