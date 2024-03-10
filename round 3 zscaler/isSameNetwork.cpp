//checking if 2 ip's belong to same network
#include<bits/stdc++.h>
using namespace std;

string binary(int x){
    string res;
    while(x){
        res.push_back((char)(x % 2 + '0'));
        x /= 2;
    }
    while(res.size() < 8) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
bool IsSameNetwork(string& ipA, string& ipB, string& maskA, string& maskB){
    if(maskA != maskB) return false;
    stringstream ipAss(ipA), ipBss(ipB), maskss(maskA);
    string token;
    string binA, binB;
    while(getline(ipAss, token, '.')){
        binA += binary(stoi(token));
    }
    while(getline(ipBss, token, '.')){
        binB += binary(stoi(token));
    }
    int netLen = 0;
    while(getline(maskss, token, '.')){
        netLen += __builtin_popcount(stoi(token));
    }
    // cout << binA << endl << binB << endl;
    return binA.substr(0, netLen) == binB.substr(0, netLen);
    return false;
}

int main(){
    string ipA, ipB, maskA, maskB;
    cin >> ipA >> ipB >> maskA >> maskB;
    cout << (IsSameNetwork(ipA, ipB, maskA, maskB) ? "Same network Ip's" : "Different network IP's");
    return 0;
}