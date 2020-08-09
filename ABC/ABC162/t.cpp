//
// Created on 2020/04/12.
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
    string ans;
    for (int i = 0; i < 4000; ++i) {
        if(i%3 == 0 ){
            ans += "R";
        }else if(i% 2 == 0){
            ans += "G";
        }else{
            ans+="B";
        }
    }

    cout<<ans<<endl;
}
//
// Created on 2020/04/12.
//

//#include <iostream> // cout, endl, cin
//
//#include <string> // string, to_string, stoi
//#include <vector> // vector
//#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
//#include <utility> // pair, make_pair
//#include <tuple> // tuple, make_tuple
//#include <cstdint> // int64_t, int*_t
//#include <cstdio> // printf
//#include <map> // map
//#include <queue> // queue, priority_queue
//#include <set> // set
//#include <stack> // stack
//#include <deque> // deque
//#include <unordered_map> // unordered_map
//#include <unordered_set> // unordered_set
//#include <bitset> // bitset
//#include <cctype> // isupper, islower, isdigit, toupper, tolower
//#include <math.h>
//#include <ios>
//#include <iomanip>
//#include <numeric>
//
//#define all(x) (x).begin(),(x).end()
//typedef long long ll;
//using namespace std;
//const long long LINF =1e18;
//const int INF = 1e9;
//
//
//int main() {
//    ll ans = 0;
//    string s;
//    int n;
//    cin>>n>>s;
//    vector<int>R(n,0);
//    vector<int>G(n,0);
//    vector<int>B(n,0);
//
//    for (int l = 0; l < n; ++l) {
//        if(s[l] == 'R'){
//            R[l] ++;
//        }else if(s[l] == 'G'){
//            G[l] ++;
//        }else if(s[l] == 'B'){
//            B[l] ++;
//        }
//    }
//
//    for (int i = 0; i + 2 < n; ++i) {
//        for (int j = i + 1; j + 1 < n; ++j) {
//            if(s[i] == s[j]) continue;
//            if(s[i] == 'R' && s[j] == 'G'){
//                auto sum = accumulate(B.begin()+j+1,B.end(),0LL);
//                if(B[2*j-i] == 1) sum--;
//                ans+= sum;
//            }else if(s[i] == 'R' && s[j] == 'G'){
//                auto sum = accumulate(B.begin()+j+1,B.end(),0LL);
//                if(B[2*j-i] == 1) sum--;
//                ans+= sum;
//            }
//            else if(s[i] == 'G' && s[j] == 'B'){
//                auto sum = accumulate(R.begin()+j+1,R.end(),0LL);
//                if(R[2*j-i] == 1) sum--;
//                ans+= sum;
//            }else if(s[i] == 'B' && s[j] == 'G'){
//                auto sum = accumulate(R.begin()+j+1,R.end(),0LL);
//                if(R[2*j-i] == 1) sum--;
//                ans+= sum;
//            }else{
//                auto sum = accumulate(G.begin()+j+1,G.end(),0LL);
//                if(G[2*j-i] == 1) sum--;
//                ans+= sum;
//            }
//
//
//        }
//
//    }
//
//
//    cout<<ans<<endl;
//    return 0;
//}
