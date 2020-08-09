//
// Created on 2020/01/12.
//

#include <istream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    int N;
    int M;
    cin>>N>>M;

    map<int,int>q;
    map<int,bool>q2;
    for (int i = 0; i < M; ++i) {
        int p;
        cin>>p;
        string state;
        cin>>state;
        if (state=="AC"){
            q2[p] = true;
        }else if(state=="WA" && !q2[p]){
            q[p] += 1;
        }
    }
    int ansac = 0;
    int ans = 0;
    for (pair<int,bool> x :q2){
        if (x.second){
            ansac += 1;
            ans += q[x.first];
        }
    }

    cout<<ansac<<" "<<ans<<endl;
}
