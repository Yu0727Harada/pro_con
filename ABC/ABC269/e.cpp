//
// Created on 2023/07/11.
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



int main() {

    int n;
    cin>>n;

    int col = 1;
    int raw = 1;

    //col
    int ok = 1;
    int ng = n;
    int mid = (ok + ng) / 2;

    int t;

    while(abs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        cout<<'?'<<" "<<ok<<" "<<mid<<" "<<1<<" "<<n<<endl;
        cin>>t;
        if(t == mid - ok + 1){
            ok = mid + 1;
        }else{
            ng = mid;
        }
    }
    mid = (ok + ng) / 2;
    cout<<'?'<<" "<<ok<<" "<<mid<<" "<<1<<" "<<n<<endl;
    cin>>t;
    if(t == 1)col = ng;
    else if(t == 0)col = ok;

    ok = 1;
    ng = n;

    while(abs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        cout<<'?'<<" "<<1<<" "<<n<<" "<<ok<<" "<<mid<<endl;
        cin>>t;
        if(t == mid - ok + 1){
            ok = mid + 1;
        }else{
            ng = mid;
        }
    }
    mid = (ok + ng) / 2;
    cout<<'?'<<" "<<1<<" "<<n<<" "<<ok<<" "<<mid<<endl;
    cin>>t;
    if(t == 1)raw = ng;
    else if(t == 0)raw = ok;


    cout<<"!"<<" "<<col<<" "<<raw<<endl;


    return 0;
}

//二分探索きっちりかく