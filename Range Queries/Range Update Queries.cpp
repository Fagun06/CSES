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
 
 
#define  inf 1e9;
 
ll aa[N];
ll tr[4000006];
ll lazy[4000006];
 
 
void build_tree(int node, int a, int b) {
    if(a > b) return; 
    
    if(a == b) { 
            tr[node] = aa[a];
        return;
    }
    
    build_tree(node*2, a, (a+b)/2); 
    build_tree(node*2+1, 1+(a+b)/2, b); 
    
    tr[node] = max(tr[node*2], tr[node*2+1]); 
}
 
 
void update_tree(int node, int a, int b, int i, int j, int value) {
  
    if(lazy[node] != 0) { 
        tr[node] += lazy[node]; 
 
        if(a != b) {
            lazy[node*2] += lazy[node]; 
                lazy[node*2+1] += lazy[node]; 
        }
 
        lazy[node] = 0; // Reset it
    }
  
    if(a > b || a > j || b < i) 
        return;
    
    if(a >= i && b <= j) { 
            tr[node] += value;
 
        if(a != b) { 
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
 
            return;
    }
 
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); 
 
    tr[node] = max(tr[node*2], tr[node*2+1]); 
}
 
 
 
ll query_tree(int node, int a, int b, int i, int j) {
    
    if(a > b || a > j || b < i) return -inf;
 
    if(lazy[node] != 0) { 
        tr[node] += lazy[node]; 
 
        if(a != b) {
            lazy[node*2] += lazy[node]; 
            lazy[node*2+1] += lazy[node]; 
        }
 
        lazy[node] = 0; 
    }
 
    if(a >= i && b <= j)
        return tr[node];
 
    ll q1 = query_tree(node*2, a, (a+b)/2, i, j);
    ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
 
    ll res = max(q1, q2); 
    
    return res;
}
 
void solve(){
     ll n,q; cin>>n>>q;
     for(int i=0; i<n; i++) cin>>aa[i];
    memset(lazy, 0, sizeof lazy);
    build_tree(1,0,n-1);
     while(q--) {
        int p; cin>>p;
        if(p==2) {
            int k; cin>>k;
            k--;
            cout<<query_tree(1,0,n-1,k,k)<<endl;
        }
        else {
            int l,r,k; cin>>l>>r>>k;
            l--,r--;
            update_tree(1,0,n-1,l,r,k);
        }
     }
 
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
