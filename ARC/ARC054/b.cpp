//
// Created on 2020/07/02.
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

double f(double p,double x){
    return 1 - (log(2)*p*pow(2,1-(2*x)/3))/3;
}

int main() {
    double p;
    cin>>p;
    double r = 200;
    double l = 0;
    double mid = (r+l)/2;
    int c = 100000;
    while(c){
        c--;
        if(f(p,mid) >= 0){
            r = mid;
            mid = (r+l)/2;
        }else{
            l = mid;
            mid = (r+l)/2;
        }
    }
    double ans = p/(pow(2,(2*mid)/3))+mid;
        printf("%.10f\n", ans);


    return 0;
}

/*
 * 二分探索　微分
 * 
 * 高橋君はタカハシマン関数という関数に興味を持ちました。高橋君は
T
(
334
)
 (
T
 はタカハシマン関数を表す)を計算したいと思いましたが、それは現代のコンピュータでは
P
 年がかかるため、とても難しいということが分かりました。

半ば計算をあきらめかけていた高橋君でしたが、世の中にはムーアの法則という法則があることを知りました。 ムーアの法則によると、コンピュータの速度は
1.5
 年ごとに
2
 倍になる速度で、指数関数的に増大することが分かりました。

より正確には、
x
 年後にはコンピュータの速度は現代の
2
x
/
1.5
 倍になります。

高橋君は適切なタイミングで計算を始めることで、
T
(
334
)
 の計算をできるだけ早く終わらせたいと思いました。 もちろん計算中にコンピュータを変えることはできないので、計算を終えるまでの時間は
(
計
算
を
始
め
る
ま
で
の
時
間
)
+
(
計
算
を
始
め
た
時
点
の
コ
ン
ピ
ュ
ー
タ
で
T
(
334
)
を
計
算
す
る
の
に
か
か
る
時
間
)
 であらわされます。

計算が終わるまでの最短の時間を求めてください。*/