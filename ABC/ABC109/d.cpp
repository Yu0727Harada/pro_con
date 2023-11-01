
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

    int h,w;
    cin>>h>>w;
    vvi a(h+2,vi(w+2,-1));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin>>a[i][j];
        }
    }
    vector<vector<int>>ans;

    for (int i = 1; i <= h; ++i) {
        if(i % 2 == 1){
            for (int j = 1; j <= w; ++j) {
                if(a[i][j] % 2 == 1){
                    if(j == w){
                        if(i + 1 <= h) {
                            a[i][j]--;
                            a[i + 1][j]++;
                            ans.push_back({i, j, i + 1, j});
                        }
                    }else{
                        a[i][j]--;
                        a[i][j+1]++;
                        ans.push_back({i,j,i,j+1});
                    }
                }
            }
        }else{
            for (int j = w; j >= 0; --j) {
                if(a[i][j] % 2 == 1){
                    if(j == 1){
                        if(i + 1 <= h) {
                            a[i][j]--;
                            a[i + 1][j]++;
                            ans.push_back({i, j, i + 1, j});
                        }
                    }else{
                        a[i][j]--;
                        a[i][j-1]++;
                        ans.push_back({i,j,i,j-1});
                    }
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for (int j = 0; j < ans.size(); ++j) {
        for ( int i = 0; i < ans[j].size(); i++ )
        {
            cout << ans[j][i] << ( i + 1 < ans[j].size() ? ' ' : '\n' );
        }
        cout << flush;
    }

    return 0;
}
