//
// Created by 原田 on 2021/07/23.
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
const double pi = acos(-1);


int main() {
    int t;
    double l,x,y;
    cin>>t>>l>>x>>y;
    int q;
    cin>>q;
    while(q){
        q--;
        int e;
        cin>>e;

        e %= t;

        double h = cos(((double)e/((double)t/2)) * pi);
        if(h < 0) {
            h *= -(l/2);
            h += (l/2) - y;
        }else{
            h *= (l/2);
            h -= y;
        }

        double s = sqrt(h * h + x * x);
        double c = (s * s + y * y - h * h)/(2 * s * y);
        double ans = acos(c);
        ans = (ans / pi) * 180;
        printf("%.10f\n", ans);

    }
    return 0;
}
