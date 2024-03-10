#include<bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int x = 0){
        data = x;
        next = NULL;
    }
};
void print(SinglyLinkedListNode* head){
    SinglyLinkedListNode* cur = head;
    while(cur){
        cout << cur -> data << " ";
        cur = cur -> next;
    }
}
SinglyLinkedListNode* findLongestList(SinglyLinkedListNode* head){
    SinglyLinkedListNode* first= head, *last = head, *res;
    int len = 0;
    int l = 0, r = 0;
    int prev = INT_MAX;
    while(last){
        if(last -> data <= prev){
            if(r - l + 1 > len){
                len = r - l + 1;
                res = first;
            }
        }
        else{
            first = last;
            l = r;
        }
        prev = last -> data;
        last = last -> next;
        r++;
    }
    SinglyLinkedListNode* cur = res, *p = res;
    while(len){
        p = cur;
        cur = cur -> next;
        len--;
    }
    p -> next = NULL;
    return res;
}
int main()
{
    int n; cin >> n;
    SinglyLinkedListNode* head = new SinglyLinkedListNode;
    cin >> head -> data;
    SinglyLinkedListNode* cur = head;
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        cur -> next = new SinglyLinkedListNode(x);
        cur = cur -> next;
    }
    SinglyLinkedListNode *res = findLongestList(head);
   return 0;
}