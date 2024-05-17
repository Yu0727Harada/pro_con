//
// Created by yu on 2024/05/17.
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



int main() {
    int n,m;
    cin>>n>>m;
    int l;
    cin>>l;
    vector<pair<int,int>>a(n);
    set<pair<int,int>>b;
    for (int i = 0; i < n; ++i) {
            cin>>a[i].first;
            a[i].second = i;
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin>>tmp;
        b.insert({tmp,i});
    }
    vector<set<int>>st(n);
    for (int i = 0; i < l; ++i) {
        int c,d;
        cin>>c>>d;
        c--;d--;
        st[c].insert(d);
    }

    sort(rall(a));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(b.empty())break;
        auto b_target = b.end().operator--();

        while(!b.empty()){

            int a_itr = a[i].second;
            int a_v = a[i].first;
            int b_itr = b_target->second;
            int b_v = b_target->first;


            if(st[a_itr].count(b_itr)){
                b_target--;
                if(b_target == b.begin().operator--())break;
                continue;
            }else{
                chmax(ans,(ll)a_v + (ll)b_v);
                b.erase({b_v,b_itr});
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
