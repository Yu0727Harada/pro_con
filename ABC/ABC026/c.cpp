
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
    cin>>n;

    vvi edge(n,vi());

    for (int i = 1; i < n; ++i) {
        int t;
        cin>>t;
        t--;
        edge[t].push_back(i);
    }
    vi salary(n,0);
    for (int i = n-1; i >= 0; --i) {
        if(edge[i].empty()){
            salary[i] = 1;
        }else{
            int max_v = 0;
            int min_v = INF;
            for (int j = 0; j < edge[i].size(); ++j) {
                chmax(max_v,salary[edge[i][j]]);
                chmin(min_v,salary[edge[i][j]]);

            }
            salary[i] = max_v + min_v + 1;
        }
    }

    cout<<salary[0]<<endl;


    return 0;
}
