
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
    int t = 1;
    int cnt = 0;
    while(t < n){
        t *= 2;
        cnt++;
    }
    bitset<8> a(n);
    int m = cnt;
    vvi friends(m,vi());
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1<<j)){
                friends[j].push_back(i);
            }
        }
    }
    cout<<m<<endl;
    for (int i = 0; i < m; ++i) {
        cout<<friends[i].size();
        for (int j = 0; j < friends[i].size(); ++j) {
            cout<<" "<<friends[i][j];
        }
        cout<<endl;
    }
    string s;
    cin>>s;
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        if(s[i] == '1'){
            ans |= (1<<i);
        }
    }
    if(ans == 0)ans = n;
    cout<<ans<<endl;
    return 0;
}

