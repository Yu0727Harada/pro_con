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
    ll ans = 0;
    string s ;
    int n;
    cin>>n>>s;
    vector<ll>R(n,0);
    vector<ll>G(n,0);
    vector<ll>B(n,0);
    int r = 0;
    int g = 0;
    int b = 0;
    for (int l = n - 1; l >= 0; --l) {
        if(s[l] == 'R'){
            r++;

        }else if(s[l] == 'G'){
            g++;

        }else if(s[l] == 'B'){
            b++;

        }
        R[l] = r;
        G[l] = g;
        B[l] = b;
    }

    for (int i = 0; i + 2 < n; ++i) {
        for (int j = i + 1; j + 1 < n; ++j) {
            if(s[i] == s[j]) continue;
            if(s[i] == 'R' && s[j] == 'G'){
                int sum = B[j+1];
                if(s[j+j-i] == 'B' && j+j-i<n && j+j-i >= 0) sum--;
                ans+= sum;
            }else if(s[i] == 'G' && s[j] == 'R'){
                int sum = B[j+1];
                if(s[j+j-i] == 'B' && j+j-i<n && j+j-i >= 0) sum--;
                ans+= sum;
            }
            else if(s[i] == 'G' && s[j] == 'B'){
                int sum = R[j+1];
                if(s[j+j-i] == 'R' && j+j-i<n && j+j-i >= 0) sum--;
                ans+= sum;
            }else if(s[i] == 'B' && s[j] == 'G'){
                int sum = R[j+1];
                if(s[j+j-i] == 'R' && j+j-i<n && j+j-i >= 0) sum--;
                ans+= sum;
            }else{
                int sum = G[j+1];
                if(s[j+j-i] == 'G' && j+j-i<n && j+j-i >= 0) sum--;
                ans+= sum;
            }


        }

    }


    cout<<ans<<endl;
    return 0;
}
