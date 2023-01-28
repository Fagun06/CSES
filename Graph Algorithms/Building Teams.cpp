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
 
std::vector<int> g[100005];
int vis[100005];
int col[100005];
 
bool bfs(int node) {
    vis[node]=1;
    col[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty())
    {
        int cr=q.front();
        q.pop();
 
        for(int child : g[cr]) {
            if(vis[child]==0) {
                q.push(child);
                vis[child]=1;
                col[child]=col[cr]^1;
            }
            else{
                if(col[child]==col[cr]) return false;
            }
        }
    }
    return true;
}
 
void solve(){
    int n,e; cin>>n>>e;
    for(int i=0; i<e; i++) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool f=true;
 
    for(int i=1; i<=n; i++) {
        if(!vis[i]){
            f= bfs(i);
            if(!f) break;
        }
    }
    if(!f) {
        cout<<"IMPOSSIBLE";
        return;
    }
 
    for(int i=1; i<=n; i++) {
       cout<<col[i]+1<<" ";
    }
}
int main()
{
    io();
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
 
/**************************************************ALHAMDULILLAH************************************************/
