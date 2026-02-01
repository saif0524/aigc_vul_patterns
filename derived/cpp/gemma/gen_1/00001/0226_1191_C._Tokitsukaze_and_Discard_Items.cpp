#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    long long operations = 0;
    vector<long long> remaining_special_items = p;

    while (!remaining_special_items.empty()) {
        operations++;
        long long current_page_start = 1;
        long long current_page_end = min(n, k);

        vector<long long> special_items_on_page;
        for (long long special_item : remaining_special_items) {
            if (special_item >= current_page_start && special_item <= current_page_end) {
                special_items_on_page.push_back(special_item);
            }
        }

        if (!special_items_on_page.empty()) {
            vector<long long> new_remaining_special_items;
            for (long long special_item : remaining_special_items) {
                bool discard = false;
                for (long long item_to_discard : special_items_on_page) {
                    if (special_item == item_to_discard) {
                        discard = true;
                        break;
                    }
                }
                if (!discard) {
                    new_remaining_special_items.push_back(special_item);
                }
            }
            remaining_special_items = new_remaining_special_items;
        } else {
            current_page_start = current_page_end + 1;
            current_page_end = min(n, current_page_start + k - 1);
            
            vector<long long> special_items_on_page;
            for (long long special_item : remaining_special_items) {
                if (special_item >= current_page_start && special_item <= current_page_end) {
                    special_items_on_page.push_back(special_item);
                }
            }
            
             if (!special_items_on_page.empty()) {
                vector<long long> new_remaining_special_items;
                for (long long special_item : remaining_special_items) {
                    bool discard = false;
                    for (long long item_to_discard : special_items_on_page) {
                        if (special_item == item_to_discard) {
                            discard = true;
                            break;
                        }
                    }
                    if (!discard) {
                        new_remaining_special_items.push_back(special_item);
                    }
                }
                remaining_special_items = new_remaining_special_items;
            }
        }
        
    }

    cout << operations << endl;

    return 0;
}