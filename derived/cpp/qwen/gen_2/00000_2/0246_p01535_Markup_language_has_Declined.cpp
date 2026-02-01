#include <bits/stdc++.h>
using namespace std;

struct Tag {
    string name;
    int start, end;
    bool visible;
    vector<pair<int, int>> positions;
    vector<Tag> children;
};

struct Script {
    unordered_map<string, bool> states;
    unordered_map<string, vector<string>> script;
};

void parseDML(const string& content, Tag& root) {
    stack<Tag*> st;
    st.push(&root);
    int i = 0, n = content.size();
    while (i < n) {
        if (content[i] == '<') {
            bool isClose = content[i + 1] == '/';
            if (isClose) ++i;
            ++i;
            int start = i;
            while (i < n && content[i] != '>') ++i;
            string tagName = content.substr(start, i - start);
            ++i;
            if (isClose) {
                st.pop();
            } else {
                Tag newTag = {tagName, st.top()->start, i - 1, true, {}, {}};
                st.top()->children.push_back(newTag);
                st.push(&(st.top()->children.back()));
                if (tagName == "script") {
                    while (i < n && content[i] != '<') ++i;
                    st.pop();
                } else if (tagName == "br") {
                    st.pop();
                }
            }
        } else {
            int start = i;
            while (i < n && content[i] != '<') ++i;
            string text = content.substr(start, i - start);
            st.top()->positions.push_back({start, i - 1});
        }
    }
}

void flattenTags(Tag& root, vector<Tag*>& flatTags) {
    flatTags.push_back(&root);
    for (auto& child : root.children) {
        flattenTags(child, flatTags);
    }
}

void applyScript(Script& script, Tag& root) {
    vector<Tag*> flatTags;
    flattenTags(root, flatTags);
    for (const auto& [key, actions] : script.script) {
        for (const auto& action : actions) {
            size_t pos = action.find('=');
            if (pos == string::npos) continue;
            string var = action.substr(0, pos);
            string value = action.substr(pos + 1);
            if (value.back() == '=') {
                bool newValue = value[0] != '!';
                value = value.substr(1, value.size() - 2);
                for (auto* tag : flatTags) {
                    if (tag->name == value) {
                        tag->visible = newValue;
                    }
                }
            } else {
                bool newValue = value[0] == 't';
                for (auto* tag : flatTags) {
                    if (tag->name == var) {
                        tag->visible = newValue;
                    }
                }
            }
        }
    }
}

void renderScreen(Tag& root, int w, int h, vector<string>& screen) {
    screen.assign(h, string(w, '.'));
    stack<pair<Tag*, int>> st;
    st.push({&root, 0});
    int x = 0, y = 0;
    while (!st.empty()) {
        Tag* current = st.top().first;
        int childIndex = st.top().second;
        st.pop();
        if (!current->visible) continue;
        for (auto& [start, end] : current->positions) {
            for (int i = start; i <= end && y < h; ++i) {
                if (x >= w) {
                    x = 0;
                    ++y;
                }
                if (y < h) {
                    screen[y][x++] = current->name[start - current->start];
                }
            }
        }
        for (int i = childIndex; i < current->children.size(); ++i) {
            st.push({&(current->children[i]), 0});
        }
    }
}

Tag findTagByCoordinates(Tag& root, int x, int y) {
    vector<Tag*> flatTags;
    flattenTags(root, flatTags);
    for (auto* tag : flatTags) {
        if (!tag->visible) continue;
        for (auto& [start, end] : tag->positions) {
            if (y == 0 && x >= start && x <= end) {
                return *tag;
            }
        }
    }
    return Tag();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    unordered_map<string, string> files;
    for (int i = 0; i < N; ++i) {
        string name, content;
        cin >> name >> content;
        files[name] = content;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int w, h, s;
        string startfile;
        cin >> w >> h >> s >> startfile;
        Tag root = {"dml", 0, 0, true, {}, {}};
        parseDML(files[startfile], root);
        Script script;
        unordered_set<string> visited;
        for (int j = 0; j < s; ++j) {
            int x, y;
            cin >> x >> y;
            Tag tag = findTagByCoordinates(root, x, y);
            if (tag.name == "link") {
                int start = 0, end = tag.name.size();
                for (int i = tag.start; i < tag.end; ++i) {
                    if (files[startfile][i] == '>') start = i + 1;
                    if (files[startfile][i] == '<') end = i - 1;
                }
                startfile = files[startfile].substr(start, end - start + 1);
                root = {"dml", 0, 0, true, {}, {}};
                parseDML(files[startfile], root);
                script.states.clear();
                script.script.clear();
                visited.clear();
            } else if (tag.name == "button") {
                int start = 0, end = tag.name.size();
                for (int i = tag.start; i < tag.end; ++i) {
                    if (files[startfile][i] == '>') start = i + 1;
                    if (files[startfile][i] == '<') end = i - 1;
                }
                string subroutineName = files[startfile].substr(start, end - start + 1);
                if (visited.find(subroutineName) == visited.end()) {
                    visited.insert(subroutineName);
                    int pos = 0;
                    while (pos < files[subroutineName + ".ds"].size() && files[subroutineName + ".ds"][pos] != '{') ++pos;
                    ++pos;
                    while (pos < files[subroutineName + ".ds"].size() && files[subroutineName + ".ds"][pos] != '}') {
                        int startExpr = pos;
                        while (pos < files[subroutineName + ".ds"].size() && files[subroutineName + ".ds"][pos] != ';') ++pos;
                        string expression = files[subroutineName + ".ds"].substr(startExpr, pos - startExpr);
                        script.script[subroutineName].push_back(expression);
                        ++pos;
                    }
                    applyScript(script, root);
                }
            }
        }
        vector<string> screen;
        renderScreen(root, w, h, screen);
        for (const auto& line : screen) {
            cout << line << "\n";
        }
    }
}