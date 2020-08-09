//
// Created on 2020/07/05.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
const int mod = 1e9+7;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main() {

    int n,k;
    cin>>n>>k;
    vector<ll>A(n);
    mint ans = 1;
    for (int i = 0; i < n; ++i) {
        cin>>A[i];
    }
    sort(rall(A));
    deque<ll>q_posi;
    deque<ll>q_nega;
    if(n==k){
        for (int i = 0; i < n; ++i) {
            ans *= A[i];
        }
        cout<<ans.x<<endl;
        return 0;
    }
    int cnt = 0;
    if(A[0]>0){
        for (cnt = 0; cnt < n; ++cnt) {
            if(A[cnt] <= 0)break;
            q_posi.push_back(A[cnt]);
        }
    }
    for ( cnt; cnt <n ; ++cnt) {
        q_nega.push_back(A[cnt]);
    }

    if(q_posi.size() == 0 && k % 2 == 1){
        while(k > 0){
            ans *= q_nega.front();
            q_nega.pop_front();
            k--;
        }
    }else{
        while(k >= 2 && q_nega.size()>=2){
            ll posi_1 = 0;
            ll posi_2 = 0;
            if(q_posi.size() >= 2){
                 posi_1 = q_posi.front();
                q_posi.pop_front();
                 posi_2 = q_posi.front();
                q_posi.pop_front();
                q_posi.push_front(posi_2);
                q_posi.push_front(posi_1);
            }else if(q_posi.size() == 1){
                posi_1 = q_posi.front();
                q_posi.pop_front();
                posi_2 = 1;
            }
            ll nega_1 = 0;
            ll nega_2 = 0;
            if(q_nega.size() >= 2){
                nega_1 = q_nega.back();
                q_nega.pop_back();
                nega_2 = q_nega.back();
                q_nega.pop_back();
                q_nega.push_back(nega_2);
                q_nega.push_back(nega_1);
            }
            if((posi_1 * posi_2 > (nega_1 * nega_2))){
                //posi>nega
                ans *= posi_1;
                q_posi.pop_front();
                k --;

            }else{
                ans *= nega_1;
                ans *= nega_2;
                q_nega.pop_back();
                q_nega.pop_back();
                k -= 2;
            }
        }

        while(k != 0){
            if(!q_posi.empty()){
                ans *= q_posi.front();
                q_posi.pop_front();
            }else{
                ans *= q_nega.front();
                q_nega.pop_front();
            }
            k--;
        }

    }

    cout<<ans.x<<endl;
    return 0;
}
