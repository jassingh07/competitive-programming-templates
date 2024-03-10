#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left, *right;
    node(int x = 0){
        val = x;
        left = right = NULL;
    }
};

string res;

void find(int tar, node* cur, string& ds){
    if(cur == NULL) return;
    if(cur -> val == tar) {
        res = ds;
        return;
    }
    ds.push_back('L');
    find(tar, cur -> left, ds);
    ds.pop_back();
    ds.push_back('R');
    find(tar, cur -> right, ds);
    ds.pop_back();
}

int main()
{
    res = "";
    int h; cin >> h;
    int in = pow(2, h + 1) - 1;
    // cout << in;
    int head; cin >> head;
    node* root = new node(head);
    queue<node*> q;
    q.push(root);
    for(int i = 0; i < in - 1; i += 2){
        node* cur = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if(left != -1) cur -> left = new node(left);
        if(right != -1) cur -> right = new node(right);
        if(cur -> left) q.push(cur -> left);
        if(cur -> right) q.push(cur -> right);
    }
    int target; cin >> target;
    string ds = "";
    find(target, root, ds);
    cout << res;
    return 0;
}