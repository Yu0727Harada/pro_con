
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
    int h,w,k;
    cin>>h>>w>>k;
    vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin>>s[i];
    }
    int ans = INF;
    for (int i = 0; i < h; ++i) {
        int cnt_dot_or_circle = 0;
        int cnt_rewirte = 0;
        for (int j = 0; j < w; ++j) {
            if(s[i][j] == 'o'){
                if(cnt_dot_or_circle == k){
                    if(s[i][j - k] == '.'){
                        cnt_rewirte--;
                    }
                    chmin(ans,cnt_rewirte);
                }else{
                    cnt_dot_or_circle++;
                    if(cnt_dot_or_circle == k){
                        chmin(ans,cnt_rewirte);
                    }
                }
            }else if(s[i][j] == '.'){
                if(cnt_dot_or_circle == k){
                    if(s[i][j - k] == 'o'){
                        cnt_rewirte++;
                    }
                    chmin(ans,cnt_rewirte);
                }else{
                    cnt_dot_or_circle++;
                    cnt_rewirte++;
                    if(cnt_dot_or_circle == k){
                        chmin(ans,cnt_rewirte);
                    }
                }
            }else{
                cnt_rewirte = 0;
                cnt_dot_or_circle = 0;
            }
        }
    }
    for (int j = 0; j < w; ++j) {
        int cnt_dot_or_circle = 0;
        int cnt_rewirte = 0;
        for (int i = 0; i < h; ++i) {
            if(s[i][j] == 'o'){
                if(cnt_dot_or_circle == k){
                    if(s[i-k][j] == '.'){
                        cnt_rewirte--;
                    }
                    chmin(ans,cnt_rewirte);
                }else{
                    cnt_dot_or_circle++;
                    if(cnt_dot_or_circle == k){
                        chmin(ans,cnt_rewirte);
                    }
                }
            }else if(s[i][j] == '.'){
                if(cnt_dot_or_circle == k){
                    if(s[i-k][j] == 'o'){
                        cnt_rewirte++;

                    }
                    chmin(ans,cnt_rewirte);
                }else{
                    cnt_dot_or_circle++;
                    cnt_rewirte++;
                    if(cnt_dot_or_circle == k){
                        chmin(ans,cnt_rewirte);
                    }
                }
            }else{
                cnt_rewirte = 0;
                cnt_dot_or_circle = 0;
            }
        }
    }
    if(ans == INF)ans = -1;
    cout<<ans<<endl;
    return 0;
}
