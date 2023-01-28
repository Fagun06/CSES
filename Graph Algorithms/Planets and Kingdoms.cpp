                   /**Bismillahir Rahmanir Rahim.**/
/*
         Md.Fagun Molla
         18ICTCSE006
         BSMRSTU
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define ordered_set   tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>  //*(x.find_by_order(k)),x.order_of_key(k)
 
///************************************************ SOLUTION STARTS HERE ************************************************///
///======================================================================================================================///
 
vi g[100005];
vi gg[100005];
vi v;
int k,ans[100005];
 
int vis[100005];
int vis1[100005];
void dfs(int node) {
    vis[node]=1;
    for(int child:g[node]) {
        if(vis[child]) continue;
        dfs(child);
    }
    v.PB(node);
}
 
void dfs1(int node) {
    vis1[node]=1;
    ans[node]=k;
 
    for(int child : gg[node]) {
        if(vis1[child]) continue;
        dfs1(child);
    }
}
void solve(){
    int n,e; cin>>n>>e;
    for(int i=0; i<e; i++) {
        int u,v; cin>>u>>v;
        g[u].PB(v);
        gg[v].PB(u);
    }
 
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(i);
    }
    rev(v);
    //print(v);
 
    k=0;
    for(int i=0; i<v.size(); i++) {
        if(!vis1[v[i]]) {
            k++;
            dfs1(v[i]);
        }
    }
    cout<<k<<endl;
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<endl;
 
}
int main()
{
    io();
    // freopen("input.txt", "r",stdin); 
    // freopen("output.txt", "w", stdout); 
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
//cout<<fixed<<setprecision(9)
