#include<bits/stdc++.h>
using namespace std;
class smart{
    int *ptr;
    public:
    smart(int *p = NULL){
        ptr = p;
    }
    int& operator * (){
        return *ptr;
    }
    ~smart(){
        delete(ptr);
    }
};
int main(){
    for(int i = 0; i < 5; i++)
        smart s(new int());

}