#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
char s[N];
int q;
struct Query {
    int type, l, r, id;
    string y;
} queries[N];
int ans[N];
struct Node {
    Node* ch[26];
    int cnt;
    Node() {
        memset(ch, 0, sizeof(ch));
        cnt = 0;
    }
} *root = new Node();

void insert(Node* node, const string& str, int pos) {
    if (pos == str.size()) {
        node->cnt++;
        return;
    }
    int c = str[pos] - 'a';
    if (node->ch[c] == nullptr) node->ch[c] = new Node();
    insert(node->ch[c], str, pos + 1);
    node->cnt++;
}

void erase(Node* node, const string& str, int pos) {
    if (pos == str.size()) {
        node->cnt--;
        return;
    }
    int c = str[pos] - 'a';
    insert(node->ch[c], str, pos + 1);
    node->cnt--;
}

int query(Node* node, const string& str, int pos) {
    if (pos == str.size()) return node->cnt;
    int c = str[pos] - 'a';
    if (node->ch[c] == nullptr) return 0;
    return query(node->ch[c], str, pos + 1);
}

void build(Node* node, int tl, int tr) {
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    for (int c = 0; c < 26; ++c) {
        node->ch[c] = new Node();
    }
    for (int c = 0; c < 26; ++c) {
        for (int i = tl; i <= tm; ++i) {
            if (s[i] - 'a' == c) {
                insert(node->ch[c], string(s + i, s + min(i + N, tr + 1)), 0);
            }
        }
    }
    for (int i = tl; i <= tm; ++i) {
        int c = s[i] - 'a';
        erase(node->ch[c], string(s + i, s + min(i + N, tr + 1)), 0);
    }
    build(node->ch[s[tl] - 'a'], tl + 1, tr);
}

int query_range(Node* node, int tl, int tr, int l, int r, const string& str, int pos) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return query(node, str, pos);
    }
    int tm = (tl + tr) / 2;
    int res = query_range(node->ch[s[l] - 'a'], tl + 1, tr, l + 1, r, str, pos + 1);
    if (pos + 1 < str.size()) {
        int c = str[pos + 1] - 'a';
        if (node->ch[c] != nullptr) {
            res += query_range(node->ch[c], tm + 1, tr, tm + 1, r, str, pos + 1);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> (s + 1);
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> queries[i].type;
        if(queries[i].type == 1){
            cin >> queries[i].l >> queries[i].c;
        }
        else{
            cin >> queries[i].l >> queries[i].r >> queries[i].y;
            queries[i].id = i;
        }
    }
    build(root, 1, strlen(s + 1));
    for(int i=0;i<q;i++){
        if(queries[i].type == 1){
            int idx = queries[i].l;
            char old = s[idx];
            s[idx] = queries[i].c;
            erase(root->ch[old - 'a'], string(s + idx, s + strlen(s + 1)), 0);
            insert(root->ch[queries[i].c - 'a'], string(s + idx, s + strlen(s + 1)), 0);
        }
        else{
            int l = queries[i].l, r = queries[i].r;
            string y = queries[i].y;
            ans[queries[i].id] = query_range(root, 1, strlen(s + 1), l, r, y, 0);
        }
    }
    for(int i=0;i<q;i++){
        if(queries[i].type == 2){
            cout << ans[queries[i].id] << "\n";
        }
    }
    return 0;
}