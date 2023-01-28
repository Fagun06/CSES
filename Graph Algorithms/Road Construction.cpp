#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define endl       '\n'
#define  inf       1000000007
#define  N         2000005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll par[N];
int ran[N];
 
void init()
{
    for(ll i=0; i<=N; i++)
    {
        par[i]=i;
        ran[i]=1;
    }
}
ll findparent(ll u)
{
    if(u!=par[u])par[u]=findparent(par[u]);
    return par[u];
}
int Union(ll u,ll v)
{
    ll p=findparent(u);
    ll q=findparent(v);
    if(ran[p]<ran[q]) swap(p,q);
    par[q]=p;
    ran[p]+=ran[q];
    return ran[p];
}
 
void solve()
{
    int n,m; cin>>n>>m;
    
    init();
    int mx=1;
    for(int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        if(findparent(u)!=findparent(v)) {
            mx=max(mx,Union(u,v));
            n--;
        }
        cout<<n<<" "<<mx<<endl;
    }
    
}
int main()
{
    fast;
    int T=1;
    // cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
