//
// Created on 2020/10/02.
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
const long long LINF =1e18;
const int INF = 1e9;


int main() {

    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    sort(rall(a));
    if(n == 2){
        cout<<a[0]<<" "<<a[1]<<endl;
        return 0;
    }
    ll ans = 0;
    pair<int,int> index = {0,0};
    int ok = n-1;
    int ng = 0;
    int mid = (ok + ng) / 2;
    while(abs(ng - ok) > 1){
        if(a[mid] < a[0]/2){
            ok = mid;
            mid = (ok + ng) / 2;
        }else{
            ng = mid;
            mid = (ok + ng ) / 2;
        }
    }

    if(abs((double)a[ok] -(double)a[0]/2 ) > abs((double)a[ng] - (double)a[0]/2) && ng != 0){
        index = {a[0],a[ng]};
    }else{
        index = {a[0],a[ok]};
    }

    cout<<index.first<<" "<<index.second<<endl;

    return 0;
}
