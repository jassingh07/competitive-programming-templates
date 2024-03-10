#include<bits/stdc++.h>
using namespace std;
#define testin       int t;cin >> t; while (t--)

int main()
{
    testin{
        int n, m; cin >> n >> m;
        int cur = 0;
        for(int i = 0; i < 3; i++){
            bool take = true;
            for(int j = 0; j < n; j++){
                int num; cin >> num; 
                if((m & num) == num && take)
                    cur |= num;
                else take = false;
            }
        }
        cout << (cur == m ? "Yes" : "No") << endl;
    }
    
   return 0;
}