                   /**Bismillahir Rahmanir Rahim.**/
/*
         Md.Fagun Molla
         18ICTCSE006
         BSMRSTU(SHIICT)
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
#define rep(i,n) for(int i=0;i<n;i++)
 
///************************************************ SOLUTION STARTS HERE ************************************************///
///======================================================================================================================///
 
vector<string> v;
int n, m;
 
 
int dist[1001][1001];
int d[1001][1001];
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };
 
void solve() {
   
   
        for(int i=0; i<1001; i++)
            for(int j=0; j<1001; j++)dist[i][j]=-1;
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            string x;cin>>x;
            v.PB(x);
        }
        int x,y,c1,c2;
        queue<vector<int>>q;
        rep(i, n){
            rep(j, m){
                if(v[i][j]=='M')q.push({i, j, 0});
                if(v[i][j]=='A')c1=i, c2=j;
            }
        }
        x=c1, y=c2;
        while(!q.empty()) {
            auto curr= q.front();
            q.pop();
            int x=curr[0], y=curr[1], steps=curr[2];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y]=='#' || dist[x][y]!=-1)continue;
            dist[x][y]=steps;
            rep(i, 4){
                int cx=x+dx[i], cy=y+dy[i];
                q.push({ cx, cy, steps+1});
            }
        }
        string ans;
        while(!q.empty())   q.pop();
        q.push({ x, y, 0, 0 });
        for(int i=0; i<1001; i++) for(int j=0; j<1001; j++) d[i][j]=-1;
        bool c = false;
        int p[n + 1][m + 1];
        memset(p, 0, sizeof(p));
        while(!q.empty()) {
            auto curr=q.front();
            q.pop();
            int x =curr[0], y =curr[1], steps =curr[2], dir =curr[3];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || d[x][y] != -1 || (dist[x][y] >= 0 and dist[x][y] <= steps))
                continue;
            if(x == n - 1 || y == m - 1 || x == 0 || y == 0) {
                p[x][y] = dir;
                while(x != c1 or y != c2) {
                    if(p[x][y] == 0)    ans += 'L', y++;
                    else if(p[x][y] == 1) ans += 'R', y--;
                    else if(p[x][y] == 2)  ans += 'U', x++;
                    else    ans += 'D', x--;    
                }
                reverse(ans.begin(), ans.end());
                c=true;
                break;
            }
            d[x][y] = steps;
            p[x][y] = dir;
            rep(i, 4){
                int cx=x+dx[i], cy=y+dy[i];
                q.push({ cx, cy, steps + 1, i });
            }
        }
        if(c){
            cout<<"YES"<<endl<<ans.size()<<endl<<ans;
        }
        else
            cout << "NO"<<endl;
    
}
int main()
{
    io();
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}
//cout<<fixed<<setprecision(9)
 
