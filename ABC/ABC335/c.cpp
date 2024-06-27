
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
    int q;
    cin>>q;
    deque<pair<int,int>>d;
    for (int i = 0; i < n; ++i) {
        d.push_back({i + 1,0});
    }
    for (int i = 0; i < q; ++i) {
        int t;
        cin>>t;
        if(t == 1){
            char m;
            cin>>m;
            int x = d.front().first;
            int y = d.front().second;
            if(m == 'R'){
                d.push_front({x + 1,y});
            }else if(m == 'L'){
                d.push_front({x - 1 ,y});
            }else if(m == 'U'){
                d.push_front({x,y + 1});
            }else if(m == 'D'){
                d.push_front({x,y - 1});
            }
            d.pop_back();
        }else if(t == 2){
            int p;
            cin>>p;
            p--;
            cout<<d[p].first<<" "<<d[p].second<<endl;
        }
    }

    return 0;
}
