//
// Created by 原田 on 2021/04/07.
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
    int w,h;
    cin>>w>>h;

    int n;
    cin>>n;

    int min_x = 0;
    int max_x = w;
    int min_y = 0;
    int max_y = h;

    for (int i = 0; i < n; ++i) {
        int x,y,a;
        cin>>x>>y>>a;
        if(a == 1){
            min_x = max(x,min_x);
        }else if(a == 2){
            max_x = min(x,max_x);
        }else if(a == 3){
            min_y = max(y,min_y);
        }else if(a == 4){
            max_y = min(y,max_y);
        }
    }

    if(max_x < min_x){
        cout<<0<<endl;
        return 0;
    }
    if(max_y < min_y){
        cout<<0<<endl;
        return 0;
    }
    int ans = (max_x - min_x) * (max_y - min_y);

    cout<<max(0,ans)<<endl;

    return 0;
}
