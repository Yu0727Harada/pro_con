
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



int main() {

    int n;
    cin>>n;

    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    if(n == 1){
        cout<<a[0]<<endl;
        return 0;
    }
    int ans = INF;
    //n個の要素のbit全探索する
    for (int bit = 0; bit < (1<<(n -1)); ++bit) {
        int t = a[0];
        int f_t = -1;
        for (int i = 0; i < n - 1; ++i) {
            if(bit & (1<<i)){
                //i個目の要素にフラグが立っていた時の処理
                if(f_t == -1){
                    f_t = t;
                    t = a[i + 1];
                }else{
                    f_t = f_t ^ t;
                    t = a[i + 1];
                }
            }else{
                t = t | a[i + 1];

            }
        }
        if(f_t == -1) f_t = t;
        else f_t = f_t ^ t;
        chmin(ans,f_t);
    }
    cout<<ans<<endl;
    return 0;
}
