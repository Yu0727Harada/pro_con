
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
//#include <atcoder/all>


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



int main() {
    int n,q;
    cin>>n>>q;
    vector<set<int>>st(n,set<int>());
    int ans = n;

    for (int i = 0; i < q; ++i) {
        int t;
        cin>>t;
        if(t == 1){
            int u,v;
            cin>>u>>v;

            u--;
            v--;
            if(st[u].size() == 0)ans--;
            if(st[v].size() == 0)ans--;
            st[u].insert((v));
            st[v].insert((u));

        }else{
            int v;
            cin>>v;
            v--;
            if(st[v].size() != 0){
                for(int x :st[v]){
                    st[x].erase(v);
                    if(st[x].size() == 0)ans++;
                }
                st[v].clear();
                ans++;
            }

        }
        cout<<ans<<endl;
    }


    return 0;
}
