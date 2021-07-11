
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

int st[100005];
vvi edge;
int c[100005];
vi ans;
void dfs(int v, int p_v) {

    st[c[v]]++;
    if (st[c[v]] == 1) {
        ans.push_back(v);
    }
    for (auto item:edge[v]) {
        if (item == p_v)continue;

        dfs(item, v);
    }
    st[c[v]]--;
}

int main() {

    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    edge.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int a;
        int b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0,-1);

    sort(all(ans));
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]+1<<endl;
    }
    return 0;
}
