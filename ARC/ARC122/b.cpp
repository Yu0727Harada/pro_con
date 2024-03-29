
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

int bit_s(int n,double c,vl a){
    int ok = 0;
    int ng = n + 1;
    int mid;
    while(abs(ng - ok) > 1){
        mid = (ok + ng) / 2;
        if(2 * c >= (double)a[mid]){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n;
    cin>>n;

    vl a(n + 1);
    vl sum(n + 2,0);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i + 1];
    }
    sum[n + 1] = LINF;




    double l = 0;
    double r = INF;
    double c1;
    double c2;

    int q = 1000;
    while(q){
        q--;
        c1 = (l * 2 + r)/3;
        c2 = (l + r * 2)/3;

        double c1ans;
        double c2ans;

        int min_v1 = bit_s(n,c1,a);
        int min_v2 = bit_s(n,c2,a);

        c1ans = c1 * n + sum[n] - (sum[min_v1] + (2 * c1) * (n - ( min_v1)));
        c2ans = c2 * n + sum[n] - (sum[min_v2] + (2 * c2) * (n - (min_v2)));

        if(c1ans > c2ans){
            l = c1;
        }else{
            r = c2;
        }

    }


    int min_ans = bit_s(n,l,a);
    double ans = l * n + sum[n] - (sum[min_ans] + (2 * l) * (n - ( min_ans)));
    ans /= n;


    printf("%.20f\n",ans);

    return 0;
}

//三分探索