//
// Created by yu on 2023/12/02.
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

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > a;
vector<vector<int> > s;
int wa(int n) {
    // 入力: H × W のグリッド

    a.resize(n, vector<int>(n,0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < n; ++j) {
            if(s[j] == 'B')a[i][j] =1;
        }
    }

    // 二次元累積和
    s.resize(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];


}

 //クエリ [x1, x2) × [y1, y2) の長方形区域の和
   ll ret(ll y1, ll x1,ll y2,  ll x2) {
    cerr<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
         return  s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];


 }
int main() {
    int n,q;
    cin>>n>>q;
    wa(n);
    for (int i = 0; i < q; ++i) {
        ll b,c,d,e;
        cin>>b>>c>>d>>e;


        ll invlove_y = 0;
        ll invlove_x = 0;
        ll ans = 0;
        if(((d - b) - d % n  - b % n ) >= n){

            invlove_y = ((d - b) - d % n - b % n)/n;
        }
        if(((e - c) - e % n  - c % n ) >= n){
            invlove_y = ((e - c) - e % n - c % n)/n;
        }

        //all
        ans += invlove_x * invlove_y * s[n][n];

        //hidari
        ans += ret(0,c % n,n,n) * invlove_y;
        ans += ret(0,c % n,n,n) * invlove_y;
        //shita
        ans += ret(0,0,d % n,n) * invlove_x;
        //shita
        ans += ret(0,0,n,e % n) * invlove_y;
        //hidari
        ans += ret(b % n,0,n,n) * invlove_x;

        ans += ret(b % n,c % n,n,n);
        ans += ret(0,c % n,d % n,n);
        ans += ret(0,0,d % n,e % n);
        ans += ret(b % n ,0,n ,e % n);

        cout<<ans<<endl;

    }



    return 0;
}
