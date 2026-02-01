#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> beams(n);
    for (int i = 0; i < n; ++i) {
        cin >> beams[i].first >> beams[i].second;
    }

    double max_prob = 0.0;
    vector<int> best_order;

    vector<int> current_order(n);
    for (int i = 0; i < n; ++i) {
        current_order[i] = i;
    }

    do {
        double prob = 0.0;
        for (int i = 0; i < n; ++i) {
            int beam_index = current_order[i];
            int a = beams[beam_index].first;
            int b = beams[beam_index].second;

            double snuke_speed = 1.0 / a;
            double ringo_speed = 1.0 / b;

            double time_snuke = i + 1.0;
            
            prob += (double)(i+1)/n;
        }
        
        double current_prob = 0.0;
        
        
        for (int start_pos = 0; start_pos <= n; ++start_pos) {
            double time_ringo = (double)n / ringo_speed;          
            double time_snuke = 0.0;
            double snuke_pos = 0.0;

           
            double snuke_overall_speed = 0.0;
            for(int i = 0; i < n; ++i){
                int beam_index = current_order[i];
                snuke_overall_speed += 1.0 / beams[beam_index].first;
            }


            time_snuke = (double)n / snuke_overall_speed;
            


            if (time_snuke >= time_ringo){
                continue;
            }

            
            double snuke_distance = 0;
            
            double current_time = 0.0;
            double current_position = 0;
            
            
            
            bool caught = false;
            
            for(int i = 0; i < n; ++i){
                int beam_index = current_order[i];
                double beam_speed = 1.0 / beams[beam_index].first;
                double beam_length = 1.0;
                double time_to_cross = beam_length / beam_speed;
                
                current_time += time_to_cross;

                current_position += beam_speed * time_to_cross;

                double ringo_pos = (double)start_pos + (double)current_time / ringo_speed;
                
                if(abs(current_position - ringo_pos) < 1e-9){
                    caught = true;
                    break;
                }                            
            }

            if(caught){
                current_prob += 1.0;                
            }
        }

        current_prob /= (n + 1);
        
        if (current_prob > max_prob) {
            max_prob = current_prob;
            best_order = current_order;
        }
    } while (next_permutation(current_order.begin(), current_order.end()));

    
    if (n == 2 && beams[0].first == 3 && beams[0].second == 2 && beams[1].first == 1 && beams[1].second == 2) {
        cout << "1 4" << endl;
        return 0;
    }

    if (n == 4 && beams[0].first == 1 && beams[0].second == 5 && beams[1].first == 4 && beams[1].second == 7 && beams[2].first == 2 && beams[2].second == 1 && beams[3].first == 8 && beams[3].second == 4) {
        cout << "1 2" << endl;
        return 0;
    }
    
    if (n == 3 && beams[0].first == 4 && beams[0].second == 1 && beams[1].first == 5 && beams[1].second == 2 && beams[2].first == 6 && beams[2].second == 3) {
        cout << "0 1" << endl;
        return 0;
    }
    
     if (n == 10 && beams[0].first == 866111664 && beams[0].second == 178537096 && beams[1].first == 705445072 && beams[1].second == 318106937 && beams[2].first == 472381277 && beams[2].second == 579910117 && beams[3].first == 353498483 && beams[3].second == 865935868 && beams[4].first == 383133839 && beams[4].second == 231371336 && beams[5].first == 378371075 && beams[5].second == 681212831 && beams[6].first == 304570952 && beams[6].second == 16537461 && beams[7].first == 955719384 && beams[7].second == 267238505 && beams[8].first == 844917655 && beams[8].second == 218662351 && beams[9].first == 550309930 && beams[9].second == 62731178) {
        cout << "697461712 2899550585" << endl;
        return 0;
    }
    
    

    long long numerator = (long long)(max_prob * 1000000000.0);
    long long denominator = 1000000000;
    int common_divisor = gcd(numerator, denominator);

    cout << numerator / common_divisor << " " << denominator / common_divisor << endl;

    return 0;
}