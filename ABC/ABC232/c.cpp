//
// Created on 2021/12/19.
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
    int n;
    int m;
    cin>>n>>m;

    vvi edge_a(n,vi());
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge_a[a].push_back(b);
        edge_a[b].push_back(a);
    }
    vvi edge_b(n,vi());
    for (int i = 0; i < m; ++i) {
        int c,d;
        cin>>c>>d;
        c--;d--;
        edge_b[c].push_back(d);
        edge_b[d].push_back(c);
    }

    for (int i = 0; i < n; ++i) {
        sort(all(edge_a[i]));
    }
    vector<int> v(n);

    iota(v.begin(), v.end(), 0);       // v に 1, 2, ... N を設定
    do {

        vvi edge_bc(n,vi());

        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < edge_b[v[i]].size();j++){
                edge_bc[i].push_back(v[edge_b[v[i]][j]]);
            }
        }
        for (int i = 0; i < n; ++i) {
            sort(all(edge_bc[i]));
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if(edge_a[i] != edge_bc[i]){
                ok = false;
            }
        }
        if(ok){
            cout<<"Yes"<<endl;
            return 0;
        }

    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

    cout<<"No"<<endl;
    return 0;
}
