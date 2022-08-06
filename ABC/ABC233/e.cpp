
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
    string s;
    cin>>s;
    ll all = 0;
    ll tmp = 0;
    vi ans;
    for (int i = 0; i < s.size(); ++i) {
        all += s[i] - '0';
    }
    int cnt = 0;
    int len = s.size();
    while(all != 0 || tmp != 0){
        tmp += all;
        ans.push_back(tmp % 10);
        tmp /= 10;
        if(len - 1 - cnt >= 0){
            all -= s[len - 1 - cnt] - '0';
            cnt ++;
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
