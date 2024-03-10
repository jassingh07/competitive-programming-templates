#include<bits/stdc++.h>
using namespace std;

int main(){
    int s, w, h; cin >> s >> w >> h;
    if(w < s || h < s){
        cout << "CHANGE" << endl;
    }else{
        cout << (h == w ? "ACCEPTED" : "CROP") << endl;
    }
    return 0;
}