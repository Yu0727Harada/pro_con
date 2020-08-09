//
// Created on 2020/04/11.
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

using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    vector<int> ans;
    string s;
    cin>>s;
    stack<pair<int,int>>ike;
    stack<int>mount;


    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '\\'){
            mount.push(i);
        }else if(s[i] == '/'){
            if(mount.size()){
                int last_m = mount.top();
                mount.pop();
                int surface = (i - 1) - last_m + 1;
                if(ike.size()){
                    while(!(ike.empty())){
                        pair<int,int> last_lake = ike.top();
                        if(last_m < last_lake.second){
                            ike.pop();
                            surface += last_lake.first;
                        }else{
                            break;
                        }
                    }
                    ike.push({surface,last_m});
                }else{
                    ike.push({surface,last_m});
                }

            }
        }

    }
    while(!(ike.empty())){
        auto temp = ike.top();
        ike.pop();
        ans.push_back(temp.first);
    }


    auto sum = accumulate(ans.begin(),ans.end(),0);
    //0LL long long,0 int,0.0 double

    cout<<sum<<endl;
    cout<<ans.size();
    for (int j = ans.size() - 1; j >= 0; --j) {
        cout<<" "<<ans[j];
    }
    cout<<endl;
}
