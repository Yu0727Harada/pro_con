//
// Created by 原田 on 2021/04/09.
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
#include <complex>

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

    complex<double> P_zero;
    complex<double> P;

    int n;
    cin>>n;

    int a,b;
    cin>>a>>b;
    P_zero.real(a);
    P_zero.imag(b);
    int c,d;
    cin>>c>>d;
    P.real(c);
    P.imag(d);

    complex<double> m = (P_zero + P) / 2.0;

    double PI = acos(-1);
    double rad = 2 * PI / n;
    complex<double> r(cos(rad),sin(rad));
    complex<double> ans = m + (P_zero - m) * r;

    printf("%.10f %.10f\n",ans.real(),ans.imag() );

    return 0;
}
