
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    vector<int>ans(3,0);
    for (int i = 0; i < 3; ++i) {

        ans[i] = i+1;
    }

    int A;
    int B;
    cin>>A;
    cin>>B;

    for (int j = 0; j < 3; ++j) {
        if(ans[j] != A && ans[j] != B){
            cout<<ans[j]<<endl;
        }
    }

}
