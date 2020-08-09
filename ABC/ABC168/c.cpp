//
// Created on 2020/05/17.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    double a,b,h,m;
    cin>>a>>b>>h>>m;

    double h_deg = ((h * 60 + m) / (12 * 60))*360;
    double m_deg = (m / 60)*360;
    double deg = abs(h_deg - m_deg);

    double pi = 2.0 * asin(1.0);
    double unit = pi / 180.0;
    double deg_r = deg * unit;

    double ans = sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(deg_r));

    printf("%.20f\n", ans);

    return 0;
}
