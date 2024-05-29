
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
vvi mapping;//-1 sea


bool walk(int init_x,int init_y,string s){
    int current_x = init_x;
    int current_y = init_y;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'U'){
            current_x --;
        }else if(s[i] == 'D'){
            current_x ++;
        }else if(s[i] == 'L'){
            current_y--;
        }else if(s[i] == 'R'){
            current_y++;
        }
        if(mapping[current_x][current_y] < 0){
            return false;
        }
    }
    return true;
}

int main() {
    int h,w,n;
    cin>>h>>w>>n;
    string t;
    cin>>t;
    mapping.resize(h,vi(w,0));//-1 sea
    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#')mapping[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(mapping[i][j] >= 0){
                if(walk(i,j,t)){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
