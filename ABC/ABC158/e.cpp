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
    int n,p;
    string s;
    cin>>n>>p>>s;
    map<int,int>modp;
    int now=0;
    vector<int>S(n+1,0);

    if(p == 2){

        for (int i = n-1; i >=0 ; --i) {
            int target = s[i]-'0';
            if(target%2==0){
                ans += i+1;
            }
        }
    }else if(p==5){
        for (int i = n-1; i >=0 ; --i) {
            int target = s[i]-'0';
            if(target ==0 || target==5){
                ans += i+1;
            }
        }
    }else{
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

    }


    cout<<ans<<endl;
}

/*
右側から考える。
ある範囲s[i]~s[j](j!=n)の数字を考える。
この時、この数字は(s[i]~s[n]の数字-s[j]~s[n]の数字)/10^(j~nの桁数)と考えられる。
これがPで割り切れるかどうかを考える。
この時、10 で割っているので、10 の約数である2と5はこの考え方では解けないので別個に解く。
p!=2,5であれば分母は考える必要がなく、分子がpで割れるかどうかのみを考える。
右からの各範囲の数字はそれぞれの桁のmodpを足し合わせた数があまりになる。
 ex)152の時 p=7
 2 mod 7 = 2
 50 mod 7 = 1
 100 mod 7 = 2

 ここで左ずらしながら累積和を取っていく。（mod　pで）0の時は割り切れる。

 2 = 2
 52 = 3
 152  = 5

 これがその桁まで見た時のmod pのあまりである。

 ここで先ほどの解説にもどって、s[i]~s[j]の数字ー-s[j]~s[n]の数字)であるが、これがpで割り切れるかどうかはこれらのmod pが一致しているかどうかである
(a-b)/p = 0
 a-b = 0
 であるし、あるいは
 a/p - b/p = 0
 である。
 よって現在見ているiから右側で同じmod pの数を数えると割り切れる数を数えられる。
10をかけていくところもmodをとる事でオーバフローを避ける。
 最初に0のカウントを1入れておく（0は一致していなくとも割り切れるという事になるから）

 2,5は一番右の桁で決まる。

 */

