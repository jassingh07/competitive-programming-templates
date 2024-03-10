#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left, * right;
    node(int x = 0){
        val = x;
        left = right = NULL;
    }
};
map<node*, node*> par;
set<node*> vis;
vector<int> res;
node* build(string& pos, int val, node* root){
    node* cur = root;
    for(int i = 0; i < pos.length() - 1; i++) 
        cur = pos[i] == 'L' ? cur -> left : cur -> right;
    node* found = (pos[pos.length() - 1] == 'L' ? (cur -> left = new node(val)) : cur -> right = new node(val));
    par[found] = cur;
    return found;
}

void dfs(node* cur, node* a, node* b, vector<int>& ds){
    if(!cur || vis.find(cur) != vis.end()) return;
    ds.push_back(cur -> val);
    vis.insert(cur);
    if(cur == b) {
        res = ds;
        return;
    }
    dfs(cur -> left, a, b, ds);
    dfs(cur -> right, a, b, ds);
    dfs(par[cur], a, b, ds);
    ds.pop_back();
}
void shortestPath(int n, int r, string pos[], int val[], int a, int b){
    node* root = new node(r);
    node* aAdd, *bAdd;
    if(r == a)
        aAdd = root;
    else if(r == b) 
        bAdd = root;
    for(int i = 0; i < n - 1; i++){
        node* found = build(pos[i], val[i], root);
        if(val[i] == a) 
            aAdd = found;
        else if(val[i] == b)
            bAdd = found;
    }
    vector<int> ds;
    dfs(aAdd, aAdd, bAdd, ds);
    for(auto i: res)
     cout << i << " ";
}
int main()
{
    int n; cin >> n;
    int r; cin >> r;
    string pos[n - 1];
    int val[n - 1];
    for(int i = 0; i < n - 1; i++)
    cin >> pos[i] >> val[i];
    int a, b; cin >> a >> b;
    shortestPath(n, r, pos, val, a, b);
    return 0;
}