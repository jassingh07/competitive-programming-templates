#include<bits/stdc++.h>
using namespace std;

int findNumberOfSteps(int n, vector<vector<int>> mat){
    vector<vector<int>> pos;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            pos.push_back({mat[i][j], i, j});
    sort(pos.begin(), pos.end());
    int res = 0;
    for(int i = 1; i < pos.size(); i++)
        res += abs(pos[i][1] - pos[i - 1][1]) + abs(pos[i][0] - pos[i - 1][0]);
    return res;
}
int main()
{
    int n; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << findNumberOfSteps(n, mat);

   return 0;
}