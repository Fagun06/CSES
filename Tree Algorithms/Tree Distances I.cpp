                   /**Bismillahir Rahmanir Rahim.**/
/*
         Md.Fagun Molla
         18ICTCSE006
         BSMRSTU
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll=long long;
using db=double;
///***************************************************** CONSTANTS ******************************************************///
 
int const N=1e6+3;
ll MOD=1e9+7,fact[N];
const long long inf=(long long)1e18;
const long double PI=3.14159265358979;
 
///************************************************ CONTAINER DEFINITIONS ***********************************************///
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
///************************************************ SHORT FORM KEYWORDS *************************************************///
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define I insert
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
 
///************************************************ SHORT FORM FUNCTIONS ************************************************///
 
#define loop(a,b) for(ll i=a;i<b;i++)
#define loopr(a,b) for(ll i=a-1;i>=b;i--)
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<>())
#define rev(s) reverse(s.begin(),s.end())
#define stll(x) stoll(x, nullptr, 10);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define all(a) a.begin(),a.end()
#define mxa(a,N) *max_element(a,a+N)
#define mna(a,N) *min_element(a,a+N)
#define print(a) {for(auto x:a)cout<<x<<" ";cout<<endl;}
#define io() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
 
///************************************************ SOLUTION STARTS HERE ************************************************///
///======================================================================================================================///
 
std::vector<int> g[200005];
int vis[200005];
int dis[200005];
 
// implementation of dfs
 
void dfs(int node, int par, int d) {
    dis[node]=d;
    
    for(int child : g[node]) {
        if(child!=par )
            dfs(child,node,d+1);
    }
}
 
void solve(){
    int n,e; cin>>n;
    for(int i=1; i<n; i++) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1,0);
    int node;
    int mx=0;
    for(int i=1; i<=n; i++) {
        if(mx<dis[i]) mx=dis[i],node=i;
    }
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
 
    // cheak  it is visited;
    int node2;
    mx=0;
    dfs(node,-1,0);
    for(int i=1; i<n; i++) {
        if(mx<dis[i]) mx=dis[i],node2=i;
    }
 
    //cout<<node<<" "<<node2<<endl;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
 
    int dis1[200005];
    //for(int i=1; i<=n; i++) dis1[i]=dis[i];
   
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
 
    dfs(node,-1,0);
    for(int i=1; i<=n; i++) dis1[i]=dis[i];
   
     memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dfs(node2,-1,0);
    int ans=0;
    for(int i=1; i<=n; i++) {
        dis[i]=max(dis[i],dis1[i]);
    }
 
    for(int i=1;i<=n; i++) cout<<dis[i]<<" ";
 
}
int main()
{
    io();
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
 
