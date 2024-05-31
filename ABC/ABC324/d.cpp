
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
    string s;
    cin>>s;
    map<int,int>mp;
    for (int i = 0; i < n; ++i) {
        mp[s[i] - '0']++;
    }
    ll base = (ll)sqrt(pow(10,n - mp[0] - 1));
    ll num = base * base;
    string t = to_string(num);
    int ans = 0;
    while(t.size() <= n){
        map<int,int>t_mp;
        for (int i = 0; i < t.size(); ++i) {
            t_mp[t[i] - '0']++;
        }
        for (int i = 0; i < n - t.size(); ++i) {
            t_mp[0]++;
        }
        bool ok = true;
        for (int i = 0; i <= 9; ++i) {
            if(mp[i] != t_mp[i])ok = false;
        }
        if(ok)ans++;
        base++;
        num = base * base;
        t = to_string(num);
    }
    cout<<ans<<endl;
    return 0;
}
