#include <bits/stdc++.h>
using namespace std;

struct Block {
    int start;
    int size;
    int id;
};

int main() {
    int t, m;
    cin >> t >> m;
    vector<bool> memory(m, false);
    vector<Block> blocks;
    int nextId = 1;

    for (int i = 0; i < t; ++i) {
        string command;
        cin >> command;
        if (command == "alloc") {
            int n;
            cin >> n;
            bool found = false;
            for (int j = 0; j < m - n + 1; ++j) {
                bool canPlace = true;
                for (int k = j; k < j + n; ++k) {
                    if (memory[k]) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    Block newBlock = {j, n, nextId};
                    blocks.push_back(newBlock);
                    for (int k = j; k < j + n; ++k) {
                        memory[k] = true;
                    }
                    cout << nextId++ << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NULL" << endl;
            }
        } else if (command == "erase") {
            int x;
            cin >> x;
            bool erased = false;
            for (auto& block : blocks) {
                if (block.id == x) {
                    for (int j = block.start; j < block.start + block.size; ++j) {
                        memory[j] = false;
                    }
                    blocks.erase(remove(blocks.begin(), blocks.end(), block), blocks.end());
                    erased = true;
                    break;
                }
            }
            if (!erased) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (command == "defragment") {
            vector<bool> newMemory(m, false);
            int pos = 0;
            vector<Block> newBlocks;
            for (auto& block : blocks) {
                Block newBlock = {pos, block.size, block.id};
                newBlocks.push_back(newBlock);
                for (int j = 0; j < block.size; ++j) {
                    newMemory[pos + j] = true;
                }
                pos += block.size;
            }
            memory = newMemory;
            blocks = newBlocks;
        }
    }
}