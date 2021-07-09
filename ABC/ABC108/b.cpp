//
// Created by 原田 on 2021/04/13.
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
    pair<int,int> a;
    pair<int,int> b;
    cin>>a.first>>a.second>>b.first>>b.second;

    int d1 = (b.first - a.first);
    int d2 = (b.second - a.second);


    pair<int,int>c;
    pair<int,int>d;

    c.first = b.first - d2;
    c.second = b.second + d1;

    d1 = (c.first - b.first);
    d2 = (c.second - b.second);

    d.first = c.first - d2;
    d.second = c.second + d1;

    cout<<c.first<<" "<<c.second<<" "<<d.first<<" "<<d.second<<endl;

    return 0;
}
