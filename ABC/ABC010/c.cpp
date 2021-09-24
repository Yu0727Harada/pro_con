//
// Created by 原田 on 2021/09/24.
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

    pair<int,int> a;
    cin>>a.first>>a.second;
    pair<int,int>b;
    cin>>b.first>>b.second;
    int t,v;
    cin>>t>>v;

    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        double x,y;
        cin>>x>>y;
        double distance_a = sqrt(abs(x-a.first)*abs(x-a.first)+abs(y-a.second)*abs(y-a.second));
        double distance_b = sqrt(abs(x-b.first)*abs(x-b.first)+abs(y-b.second)*abs(y-b.second));
        if(distance_a + distance_b > (double)t * v){
            continue;
        }else{
            cout<<"YES"<<endl;
            return 0;
        }

    }
    cout<<"NO"<<endl;


    return 0;
}
