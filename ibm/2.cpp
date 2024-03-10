#include<bits/stdc++.h>
using namespace std;

int findTotalWeight(vector<int>& products){
    map<int, set<int>> m;//{value, set of indexes}
    int n = products.size();
    for(int i = 0; i < n; i++){
        m[products[i]].insert(i);
    }
    int minTotalWeight = 0;
    while(m.size()){
        int key = m.begin() -> first;
        int ind = *((m.begin() -> second).begin());

        minTotalWeight += key;//updating answer

        products[ind] = -1;
        m[key].erase(m[key].find(ind));
        if(m[key].size() == 0)
            m.erase(key);

        int leftInd = ind - 1, rightInd = ind + 1;
        while(leftInd >= 0 && products[leftInd] == -1) 
            leftInd--;
        while(rightInd < n && products[rightInd] == -1)
            rightInd++;
        if(leftInd != -1){
            key = products[leftInd];
            m[key].erase(m[key].find(leftInd));
            if(m[key].size() == 0)
                m.erase(key);
            products[leftInd] = -1;
        }
        if(rightInd != n){
            key = products[rightInd];
            m[key].erase(m[key].find(rightInd));
            if(m[key].size() == 0)
                m.erase(key);
            products[rightInd] = -1;
        }
    }
    return minTotalWeight;
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n;i++){
        cin >> v[i];
    }
    cout << findTotalWeight(v);
    return 0;
}