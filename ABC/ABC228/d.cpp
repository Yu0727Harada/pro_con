//
// Created on 2021/11/20.
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

const int mod = 1048576;

int main() {
    vi v(mod);
    iota(all(v),0);
    set<int> st(all(v));
    map<int,ll>mp;

    int q;
    cin>>q;
    while(q){
        q--;
        int t;
        ll x1;
        cin>>t>>x1;
        if(t == 1){
            if(st.count(x1 % mod) == 0){
                auto it = st.upper_bound(x1 % mod);
                ll next;
                if(it == st.end()){
                    if(st.count(0) == 0){
                        auto itt = st.upper_bound(0);
                        next = *itt;
                    }else{
                        next = 0;
                    }

                }else{
                    next = *it;
                }
                mp[next] = x1;
                st.erase(next);
            }else{
                mp[x1 % mod] = x1;
                st.erase(x1%mod);
            }
        }else{
            if(st.count(x1 % mod)){
                cout<<-1<<endl;
            }else{
                cout<<mp[x1 % mod]<<endl;
            }
        }

    }

    return 0;
}
