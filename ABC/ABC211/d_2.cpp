//
// Created on 2021/07/24.
//

//
// Created on 2021/07/24.
//


#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;

const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main() {

    int n,m;
    cin>>n>>m;

    vector<mint> dp(n,0);


    vector<vector<int>>edge(n,vector<int>());

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dp[0] = 1;
    vi visit(n,INF);
    visit[0] = 0;
    queue<vector<int>>q;//v,cost,pre
    for (int i = 0; i < edge[0].size(); ++i) {
        q.push({edge[0][i],1,0});
    }

    while(!q.empty()){
        int v = q.front()[0];
        int cost = q.front()[1];
        int pre = q.front()[2];
        q.pop();

        if(visit[v] < cost)continue;
        if(visit[v] == cost){
            dp[v] += dp[pre];//
// Created on 2021/07/24.
//

//
// Created on 2021/07/24.
//


#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
            template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
            template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
            typedef long long ll;
            using namespace std;
            typedef vector<int> vi;
            typedef vector<vi> vvi;
            typedef vector<ll> vl;
            const long long LINF =1e18;
            const int INF = 1e9;

            const int mod = 1000000007;

            struct mint {
                ll x; // typedef long long ll;
                mint(ll x=0):x((x%mod+mod)%mod){}
                mint operator-() const { return mint(-x);}
                mint& operator+=(const mint a) {
                    if ((x += a.x) >= mod) x -= mod;
                    return *this;
                }
                mint& operator-=(const mint a) {
                    if ((x += mod-a.x) >= mod) x -= mod;
                    return *this;
                }
                mint& operator*=(const mint a) {
                    (x *= a.x) %= mod;
                    return *this;
                }
                mint operator+(const mint a) const {
                    mint res(*this);
                    return res+=a;
                }
                mint operator-(const mint a) const {
                    mint res(*this);
                    return res-=a;
                }
                mint operator*(const mint a) const {
                    mint res(*this);
                    return res*=a;
                }
                mint pow(ll t) const {
                    if (!t) return 1;
                    mint a = pow(t>>1);
                    a *= a;
                    if (t&1) a *= *this;
                    return a;
                }

                // for prime mod
                mint inv() const {
                    return pow(mod-2);
                }
                mint& operator/=(const mint a) {
                    return (*this) *= a.inv();
                }
                mint operator/(const mint a) const {
                    mint res(*this);
                    return res/=a;
                }
            };

            int main() {

                int n,m;
                cin>>n>>m;

                vector<mint> dp(n,0);


                vector<vector<int>>edge(n,vector<int>());

                for (int i = 0; i < m; ++i) {
                    int a,b;
                    cin>>a>>b;
                    a--;b--;
                    edge[a].push_back(b);
                    edge[b].push_back(a);
                }
                dp[0] = 1;
                vi visit(n,INF);
                visit[0] = 0;
                queue<vector<int>>q;//v,cost,pre
                for (int i = 0; i < edge[0].size(); ++i) {
                    q.push({edge[0][i],1,0});
                }

                while(!q.empty()){
                    int v = q.front()[0];
                    int cost = q.front()[1];
                    int pre = q.front()[2];
                    q.pop();

                    if(visit[v] < cost)continue;
                    if(visit[v] == cost){
                        dp[v] += dp[pre];
                    }else if(visit[v] > cost){
                        visit[v] = cost;
                        dp[v] = dp[pre];
                        for (int i = 0; i < edge[v].size(); ++i) {
                            if(visit[edge[v][i]] < cost + 1)continue;
                            q.push({edge[v][i],cost + 1,v});
                        }
                    }


                }
                if(visit[n-1] == INF){
                    cout<<0<<endl;
                    return 0;
                }


                cout<<dp[n-1].x<<endl;



                return 0;
            }


        }else if(visit[v] > cost){
            visit[v] = cost;
            dp[v] = dp[pre];
            for (int i = 0; i < edge[v].size(); ++i) {
                if(visit[edge[v][i]] < cost + 1)continue;
                q.push({edge[v][i],cost + 1,v});
            }
        }


    }
    if(visit[n-1] == INF){
        cout<<0<<endl;
        return 0;
    }


        cout<<dp[n-1].x<<endl;



    return 0;
}

