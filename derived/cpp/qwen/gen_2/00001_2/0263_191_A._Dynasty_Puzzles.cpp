#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> names(n);
    for(auto &name: names) cin >> name;
    
    vector<vector<int>> graph(26);
    vector<int> indegree(26, 0), outdegree(26, 0);
    unordered_map<string, int> name_count;
    
    for(int i=0; i<n; ++i){
        int from = names[i][0] - 'a';
        int to = names[i].back() - 'a';
        graph[from].push_back(to);
        indegree[to]++;
        outdegree[from]++;
        name_count[names[i]]++;
    }
    
    int start = -1, end = -1;
    for(int i=0; i<26; ++i){
        if(abs(indegree[i] - outdegree[i]) > 1){
            cout << 0;
            return 0;
        }
        if(indegree[i] == outdegree[i] + 1) end = i;
        if(indegree[i] + 1 == outdegree[i]) start = i;
    }
    
    if(start == -1 && end == -1){
        for(int i=0; i<26; ++i){
            if(outdegree[i]){
                start = i;
                end = i;
                break;
            }
        }
    }
    else if(start == -1 || end == -1){
        cout << 0;
        return 0;
    }
    
    int euler_path_length = 0;
    stack<int> stack;
    vector<int> path;
    stack.push(start);
    
    while(!stack.empty()){
        int u = stack.top();
        if(!graph[u].empty()){
            stack.push(graph[u].back());
            graph[u].pop_back();
        }
        else{
            path.push_back(u);
            stack.pop();
        }
    }
    
    if(path.back() != end){
        cout << 0;
        return 0;
    }
    
    unordered_map<string, bool> used_names;
    for(int i=path.size()-1; i>0; --i){
        string name = string(1, path[i-1]+'a') + names[0].substr(1);
        if(used_names[name] || name_count[name] == 0){
            cout << 0;
            return 0;
        }
        used_names[name] = true;
        name_count[name]--;
    }
    
    int total_length = 0;
    for(auto &[name, count]: name_count){
        if(count > 0){
            total_length += name.size() * count;
        }
    }
    total_length += names[0].size();
    
    cout << total_length;
}