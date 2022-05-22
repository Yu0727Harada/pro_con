//
// Created on 2021/11/07.
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


struct waza{
public:
    ll time;
    int k;
    vi a;


};

vector<waza>waza_l;

ll solve(int v,set<int>&st){
    ll ret = 0;
    st.insert(v);
    for (int i = 0; i < waza_l[v].k; ++i) {
        if(st.count(waza_l[v].a[i]) == 0){
            ret += solve(waza_l[v].a[i],st);
        }
    }
    ret += waza_l[v].time;
    return ret;

}

int main() {

    int n;
    cin>>n;

    waza_l.resize(n);

    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        int k;
        cin>>k;
        waza_l[i].time = t;
        waza_l[i].k = k;
        waza_l[i].a.resize(k);
        for (int j = 0; j < k; ++j) {
            cin>>waza_l[i].a[j];
            waza_l[i].a[j]--;
        }
    }

    set<int>learn;

    ll ans = solve(n-1,learn);
    cout<<ans<<endl;

    return 0;
}
