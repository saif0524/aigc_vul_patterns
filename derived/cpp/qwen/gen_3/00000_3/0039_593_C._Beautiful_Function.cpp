#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> c(n);
    for(int i=0;i<n;i++){
        int xi, yi, ri;
        cin >> xi >> yi >> ri;
        c[i]={xi,yi};
    }
    int fx = c[0].first, fy = c[0].second;
    int ax = 51, bx = 51, ay = 51, by = 51;
    for(int i=0;i<n;i++){
        if(c[i].first-fx < ax) ax = c[i].first-fx;
        if(c[i].first-fx > bx) bx = c[i].first-fx;
        if(c[i].second-fy < ay) ay = c[i].second-fy;
        if(c[i].second-fy > by) by = c[i].second-fy;
    }
    int fa = 1, fb = 1, ga = 1, gb = 1;
    vector<pair<int,int>> fxy = {{ax, ay}, {bx, by}, {bx, ay}, {ax, by}};
    bool found = false;
    for(int a: {0,1}){
        for(int b: {0,1}){
            for(int c: {0,1}){
                int F = a*25 + b*50 + c*2500;
                int da = F/(fa*fb) - fx;
                int db = F/(fa*fb*ga) - fx;
                int dc = F/(fa*fb*ga*gb) - fx;
                for(int d: {da, db, dc}){
                    for(int e: {0,1}){
                        for(int f: {0,1}){
                            for(int g: {0,1}){
                                int G = e*25 + f*50 + g*2500;
                                int ea = G/(fa*fb) - fy;
                                int eb = G/(fa*fb*ga) - fy;
                                int ec = G/(fa*fb*ga*gb) - fy;
                                for(int h: {ea, eb, ec}){
                                    bool valid = true;
                                    for(auto [x, y]: fxy){
                                        int nx = a + b*x + c*x*x + d*x*x*x;
                                        int ny = e + f*y + g*y*y + h*y*y*y;
                                        int mindist = 1e9;
                                        for(auto [cx, cy]: c){
                                            mindist = min(mindist, abs(nx-cx)+abs(ny-cy));
                                        }
                                        if(mindist > 3){
                                            valid = false;
                                            break;
                                        }
                                    }
                                    if(valid){
                                        found = true;
                                        string fx = to_string(a) + (b?"+t":"") + (c?"+t*t":"") + (d?"+t*t*t":"");
                                        string fy = to_string(e) + (f?"+t":"") + (g?"+t*t":"") + (h?"+t*t*t":"");
                                        cout << fx << endl << fy << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!found){
        cout << "0" << endl << "0" << endl;
    }
}