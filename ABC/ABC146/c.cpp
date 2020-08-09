
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

ll keta(ll n){
    int cnt = 0;
    while(n >= 1){
        n /= 10;
        cnt ++;
    }
    return cnt;
}

int main() {
    ll ans = 0;
    ll a,b,x;
    cin>>a>>b>>x;


    ll high = INF+1;
    ll low = 1;
    for (int i = 0; i < 100000; ++i) {
        ll mid = (high+low)/2;
        ll value = a*mid + b*keta(mid);
        if(value > x){
            high = mid;
        }else{
            ans = max(ans,mid);
            low = mid;
        }
    }

    cout<<ans<<endl;
}
