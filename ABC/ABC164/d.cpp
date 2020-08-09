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
using gragh = vector<vector<int>>;

int main() {
    ll ans = 0;
    string s;
    cin>>s;
    map<int,int>modp;
    int now=0;
    int n = s.size();
    int p = 2019;
    vector<int>S(n+1,0);


    int ten = 1;
    modp[0]=1;
    for (int i = n-1; i >= 0; --i) {
        int target = s[i]-'0';
        now =  target * ten % p;
        S[i] = (S[i+1] + now) % p;
        ten *= 10;
        ten %= p;
        ans += modp[S[i]];
        modp[S[i]] ++;
    }

    cout<<ans<<endl;
}
//ABC158e