//
// Created on 2020/06/24.
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


int main() {
    ll d;
    cin>>d;
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>shop;
    shop.push_back(0);
    shop.push_back(0 + d);
    for (int i = 1; i < n; ++i) {
        int t;
        cin>>t;
        shop.push_back(t);
        shop.push_back(t + d);
    }
    sort(all(shop));
    ll ans = 0;
    for (int j = 0; j < m; ++j) {
        int deliver;
        cin>>deliver;
        int u = shop.size()-1;
        int l = 0;
        int k = (u + l)/2;

        while(!(shop[k] <= deliver && deliver <= shop[k+1] )){
            if(shop[k + 1] < deliver){
                l = k;
                k = (u + l)/2;
            }
            else if(deliver < shop[k]){
                u = k;
                k = (u + l)/2;
            }
        }
        ans += min(abs(deliver - shop[k]),abs(deliver - shop[k+1]));
    }
    cout<<ans<<endl;
    return 0;}

    //二分探索 binary search ピザJOI ピザでは，市の中心部を通る全長 d メートルの環状線の沿線上でピザの宅配販 売を行っている.
//JOIピザは，環状線上にn個の店舗S1,··· ,Sn を持つ.本店はS1 である.S1 から S i まで，時計回りに環状線を移動したときの道のりを di メートルとおく.d2 , · · · , dn は1以上d−1以下の整数である.d2,··· ,dn は全て異なる.
//ピザの注文を受けると, ピザが冷めないように，宅配先までの移動距離がもっとも 短い店舗でピザを焼き宅配する.
//宅配先の位置は 0 以上 d − 1 以下の整数 k で表される.これは，本店 S 1 から宅配 先までに時計回りで環状線を移動したときの道のりが k メートルであることを意味 する.ピザの宅配は環状線に沿って行われ，それ以外の道を通ることは許されない. ただし，環状線上は時計回りに移動しても反時計回りに移動してもよい.
//例えば，店舗の位置と宅配先の位置が下図のようになっている場合 (この例は「入 出力の例」の例 1 と対応している)，
