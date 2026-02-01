#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;

    vector<pair<int, int>> allocated_blocks;
    vector<bool> memory(m, true); // true means free

    int block_id = 1;

    for (int i = 0; i < t; ++i) {
        string operation;
        cin >> operation;

        if (operation == "alloc") {
            int n;
            cin >> n;

            int start_index = -1;
            for (int j = 0; j <= m - n; ++j) {
                bool found = true;
                for (int k = 0; k < n; ++k) {
                    if (!memory[j + k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    start_index = j;
                    break;
                }
            }

            if (start_index != -1) {
                allocated_blocks.push_back({start_index, n});
                for (int j = start_index; j < start_index + n; ++j) {
                    memory[j] = false;
                }
                cout << block_id++ << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (operation == "erase") {
            int x;
            cin >> x;

            bool found = false;
            int index_to_erase = -1;
            for (int j = 0; j < allocated_blocks.size(); ++j) {
                if (allocated_blocks[j].first == x) {
                    found = true;
                    index_to_erase = j;
                    break;
                }
            }

            if (found) {
                int start_index = allocated_blocks[index_to_erase].first;
                int n = allocated_blocks[index_to_erase].second;

                for (int j = start_index; j < start_index + n; ++j) {
                    memory[j] = true;
                }

                allocated_blocks.erase(allocated_blocks.begin() + index_to_erase);
            } else {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (operation == "defragment") {
            vector<pair<int, int>> new_allocated_blocks;
            int current_index = 0;

            for (auto& block : allocated_blocks) {
                int n = block.second;
                
                new_allocated_blocks.push_back({current_index, n});
                
                current_index += n;
            }
            
            
            for(int j = 0; j < m; ++j){
                memory[j] = true;
            }
            
            allocated_blocks = new_allocated_blocks;
            
            for(auto& block : allocated_blocks){
                int start_index = block.first;
                int n = block.second;
                
                for(int j = start_index; j < start_index + n; ++j){
                    memory[j] = false;
                }
            }
        }
    }

    return 0;
}