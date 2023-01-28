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
 
int const N=2000000+3;
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
 
vector<ll>g[N+5];
ll dp[N][35],LOG;
ll depth[N+5];
void dfs(ll node,ll par,ll dis)
{
    dp[node][0]=par;
    depth[node]=dis;
    for(ll i=0; i<g[node].size(); i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            dfs(child,node,dis+1);
        }
    }
}
void init(ll n)
{
    for(ll j=1; j<=LOG; j++)
    {
        for(ll i=0; i<=n; i++)
        {
            if(dp[i][j-1]!=-1)
            {
                ll par=dp[i][j-1];
                dp[i][j]=dp[par][j-1];
            }
        }
    }
}
 
 
void solve() {
 
    ll n,q;
    cin>>n>>q;
    for(int i=2; i<=n; i++)
    {
        ll u,v;
        cin>>u;
        v=i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LOG=0;
    while((1<<LOG)<=n)
    {
        LOG++;
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=LOG; j++)
        {
            dp[i][j]=-1;
        }
    }
    dfs(1,-1,0);
    init(200005);
   // cout<<dp[4][2]<<endl;
    while(q--) {
        int a,b; cin>>a>>b;
        
        int boss = a;
        for(int i=0; i<=20; i++)
        if(b & (1<<i))
        boss = dp[boss][i];
        if(boss)
         cout<<boss<<endl;
        else cout<<"-1"<<endl;
    }
 
    
}
int main()
{
   
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
//cout<<fixed<<setprecision(9)
 
