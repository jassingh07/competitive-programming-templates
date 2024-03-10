#include<bits/stdc++.h>
using namespace std;
#define ll           long long int
#define fl(i,m,n,p)  for(int i=m;i<n;i+=p)
#define bl(i,m,n,p)  for(int i=m,i>=n;i-=p)
#define pb(a)        push_back(a)
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define vd           vector<double>
#define si           set<int>
#define MOD          (int)(1e9+7)
#define plli         pair<ll,ll>
#define testin       ll t;cin >> t; while (t--)
#define fel(x,v)     for(auto x:v)
#define print(x,v)   fel(x,v) cout<<x<<' '
#define FIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi          vector<vi>
#define vpi          vector<pair<int,int>>
#define vplli        vector<pair<ll,ll>>
#define pi           pair<int,int>
#define vvlli        vector<vlli>
#define vc           vector<char>
#define vvc          vector<vc>
#define vb           vector<bool>
#define endl         "\n"



 vector<bool> sieve(int n)
 {
    vector<bool> res(n+1,true);
    for(int i=2;i<n+1;i++)
     for(int j=i*i;j<=n;j+=i)
      res[j]=false;
return res;

 }

 class segtree{
  int n;
  vi ds;//{ min , it's freq}
  char c;
  public:
  segtree(int n,int c)
  {
    this -> n = n;
    this -> c = c;
    ds.resize(4*n);
  }
  int build(int x,int l,int r,string& s)
  {
    if(r - l == 1) 
      return ds[x] = (s[l] == c) ;
     
     int mid = (l + r)/2;
     return ds[x] = build(2*x + 1,l,mid,s) + build(2*x + 2,mid,r,s);
  }
  int query(int x,int l,int r,int li,int ri)//li and ri are constant
  {
    if(l>=li && r<=ri)
    return ds[x];
    
    if(r<=li || l>=ri) return 0;

    int mid = (l + r)/2;
    return query(2*x + 1,l,mid,li,ri) + query(2*x + 2,mid,r,li,ri);
  }
 };


// static bool comp 
int main()
{
    FIO
    // ifstream infile("input.txt",ios::in);
    testin
    {
      ll n;
      cin>>n;
      vector<double> x(n),t(n);
      fl(i,0,n,1)
      cin>>x[i];
      fl(i,0,n,1)
      cin>>t[i];

      double l = *min_element(all(x));
      double h = *max_element(all(x));
      double mid = (l + h)/2;

      while(h - l >= 1e-6)
      { 
        // cout<<"r";
         mid = (l + h)/2;
         double maxx = -1;//coordinate of person taking max time for this choice of mid
         double tim = 0;//max time taken for this choice of mid
         fl(i,0,n,1)
         if(maxx == -1 || t[i] + abs(x[i] - mid) > tim) {
          tim = t[i] + abs(x[i] - mid);
          maxx = x[i];
         }
         if(maxx == mid) break;
         else if(maxx > mid) l = mid;
         else h = mid;
      }

      cout<< setprecision(15) << mid <<endl;

    }
  return 0;
}