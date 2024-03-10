#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>>& grid, int i, int j, int bomb, vector<vector<int>>& dp){
    int n = grid.size();
    if(i == -1) return 0;
    if(j == -1 || j == 5 || bomb == -1) return -1e6;
    int& res = dp[i][j];
    if(res != -1e9) return res;
    res = 0;
    int cur;
    if(bomb == 5){//not use bomb
        
    }

}
int main(){
    vector<vector<int>> grid(n, vector<int>(5)), dp(n, vector<int>(5, -1e9));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++){
            cin >> grid[i][j];
        }
    
    return 0;
}