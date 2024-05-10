
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
    vi dis_to_num(n);
    vi num_to_dis(n);
    for (int i = 0; i < n; ++i) {
        dis_to_num[i] = i;
        num_to_dis[i] = i;
    }
    for (int i = 0; i < q; ++i) {
        int x;
        cin>>x;
        x--;
        int u = num_to_dis[x];

        if(u == n - 1){
            u--;
        }
        int x_target = dis_to_num[u];
        int x_next = dis_to_num[u + 1];
        swap(dis_to_num[u],dis_to_num[u + 1]);
        swap(num_to_dis[x_target],num_to_dis[x_next]);

    }
    for (int i = 0; i < n; ++i) {
        cout<<dis_to_num[i]+1<<endl;
    }
    return 0;
}
