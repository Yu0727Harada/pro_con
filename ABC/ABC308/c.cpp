
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

    vector<ll>a(n);
    vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        cin>>b[i];
    }
    vi ans(n);
    iota(all(ans),0);


    //ラムダ式
    // []キャプチャ　＆と入れるとそのスコープ内の変数が全て使える。
    //一般的には使用する変数を宣言する
    stable_sort(all(ans),[&](int i, int j){
        return a[i]*b[j] > a[j]*b[i];
    });
    for (int i = 0; i < n; ++i) {
        cout<<ans[i] + 1<<endl;
    }

    return 0;
}
