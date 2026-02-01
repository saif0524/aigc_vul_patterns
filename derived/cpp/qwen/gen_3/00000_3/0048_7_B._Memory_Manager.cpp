#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MemoryBlock {
    int start;
    int size;
    bool allocated;
    int id;
};

int main() {
    int t, m;
    cin >> t >> m;
    
    vector<MemoryBlock> memory;
    memory.push_back({0, m, false, 0});
    
    int currentId = 1;
    
    while (t--) {
        string command;
        cin >> command;
        
        if (command == "alloc") {
            int n;
            cin >> n;
            bool allocated = false;
            for (auto &block : memory) {
                if (!block.allocated && block.size >= n) {
                    block.allocated = true;
                    block.id = currentId++;
                    cout << block.id << endl;
                    allocated = true;
                    if (block.size > n) {
                        memory.insert(memory.begin() + (&block - &memory[0]) + 1, {block.start + n, block.size - n, false, 0});
                    }
                    break;
                }
            }
            if (!allocated) {
                cout << "NULL" << endl;
            }
        } else if (command == "erase") {
            int x;
            cin >> x;
            bool found = false;
            for (auto &block : memory) {
                if (block.allocated && block.id == x) {
                    block.allocated = false;
                    block.id = 0;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (command == "defragment") {
            int currentPos = 0;
            vector<MemoryBlock> newMemory;
            for (auto &block : memory) {
                if (block.allocated) {
                    block.start = currentPos;
                    currentPos += block.size;
                    newMemory.push_back(block);
                }
            }
            if (currentPos < m) {
                newMemory.push_back({currentPos, m - currentPos, false, 0});
            }
            memory = newMemory;
        }
    }
    
    return 0;
}