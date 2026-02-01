#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> PDD;
typedef vector<PDD> VPDD;

const double EPS = 1e-8;
const double PI = acos(-1);

double dot(PDD a, PDD b) { return a.first * b.first + a.second * b.second; }
double cross(PDD a, PDD b) { return a.first * b.second - a.second * b.first; }
double dist(PDD a, PDD b) { return hypot(a.first - b.first, a.second - b.second); }

PDD rotate(PDD p, double t) {
    double x = p.first * cos(t) - p.second * sin(t);
    double y = p.first * sin(t) + p.second * cos(t);
    return PDD(x, y);
}

bool on_segment(PDD p, PDD a, PDD b) {
    return dot(p - a, p - b) <= 0 and cross(p - a, p - b) == 0;
}

bool segment_intersect(PDD a, PDD b, PDD c, PDD d) {
    return (cross(b - a, c - a) * cross(b - a, d - a) < 0) and (cross(d - c, a - c) * cross(d - c, b - c) < 0);
}

VPDD cut(PDD a, PDD b, PDD c, PDD d) {
    if (on_segment(a, c, d)) return VPDD{a};
    if (on_segment(b, c, d)) return VPDD{b};
    double u = cross(c - a, c - b) / cross(d - c, b - a);
    double v = cross(a - c, a - d) / cross(b - a, d - c);
    if (u >= 0 and u <= 1 and v >= 0 and v <= 1) return VPDD{a + PDD(u * (b.first - a.first), u * (b.second - a.second))};
    return VPDD();
}

VPDD convex_cut(VPDD cp, PDD a, PDD b) {
    VPDD new_cp;
    for (int i = 0; i < cp.size(); i++) {
        PDD p = cp[i], q = cp[(i + 1) % cp.size()];
        if (cross(b - a, p - a) >= 0) new_cp.push_back(p);
        VPDD isections = cut(p, q, a, b);
        new_cp.insert(new_cp.end(), isections.begin(), isections.end());
    }
    return new_cp;
}

double get_length_in_sunshine(VPDD cp, double theta, double phi) {
    double total_length = 0;
    for (int i = 0; i < cp.size(); i++) {
        PDD p = cp[i], q = cp[(i + 1) % cp.size()];
        total_length += dist(p, q);
    }
    PDD sun_dir = rotate(PDD(1, 0), theta * PI / 180);
    VPDD new_cp = cp;
    new_cp.push_back(new_cp[0]);
    for (int i = 0; i < cp.size(); i++) {
        PDD p = cp[i], q = cp[(i + 1) % cp.size()];
        PDD n = rotate(PDD(q.first - p.first, q.second - p.second), PI / 2);
        double proj_len = dist(p, q);
        double proj_height = proj_len / cos(phi * PI / 180);
        PDD proj_point = p + PDD(n.first * proj_height, n.second * proj_height);
        if (cross(sun_dir, proj_point - p) > 0) {
            new_cp = convex_cut(new_cp, p, proj_point);
        }
    }
    double visible_length = 0;
    for (int i = 0; i < new_cp.size(); i++) {
        PDD p = new_cp[i], q = new_cp[(i + 1) % new_cp.size()];
        visible_length += dist(p, q);
    }
    return total_length - visible_length;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int N, M;
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        vector<VPDD> cp(N);
        vector<double> H(N);
        for(int i=0;i<N;i++){
            int NV;
            cin >> NV >> H[i];
            cp[i] = VPDD(NV);
            for(int j=0;j<NV;j++) cin >> cp[i][j].first >> cp[i][j].second;
        }
        vector<VPDD> roads(M);
        for(int i=0;i<M;i++){
            roads[i] = VPDD(2);
            cin >> roads[i][0].first >> roads[i][0].second >> roads[i][1].first >> roads[i][1].second;
        }
        double theta, phi;
        cin >> theta >> phi;
        PDD S, T;
        cin >> S.first >> S.second >> T.first >> T.second;
        double total_length_in_sunshine = 0;
        for(auto &road : roads){
            double length_in_sunshine = get_length_in_sunshine(road, theta, phi);
            total_length_in_sunshine += length_in_sunshine;
        }
        for(auto &building_cp : cp){
            VPDD new_cp = building_cp;
            new_cp.push_back(new_cp[0]);
            for(int i=0;i<building_cp.size();i++){
                PDD p = building_cp[i], q = building_cp[(i+1)%building_cp.size()];
                auto intersections = cut(p, q, S, T);
                if(!intersections.empty()){
                    new_cp.insert(new_cp.end(), intersections.begin(), intersections.end());
                }
            }
            sort(new_cp.begin(), new_cp.end(), [](PDD a, PDD b){
                return a.first < b.first || (fabs(a.first - b.first) < EPS && a.second < b.second);
            });
            new_cp.erase(unique(new_cp.begin(), new_cp.end(), [](PDD a, PDD b){
                return fabs(a.first - b.first) < EPS && fabs(a.second - b.second) < EPS;
            }), new_cp.end());
            for(int i=0;i+1<new_cp.size();i++){
                PDD p = new_cp[i], q = new_cp[i+1];
                VPDD road = {p, q};
                double length_in_sunshine = get_length_in_sunshine(road, theta, phi);
                total_length_in_sunshine -= length_in_sunshine;
            }
        }
        cout << fixed << setprecision(10) << total_length_in_sunshine << "\n";
    }
}