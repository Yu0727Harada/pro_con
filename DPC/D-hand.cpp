#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<long long>DP(30,0);
    DP[0] =1;
    DP[1] =1;
     for (int i = 2; i < 30; ++i) {
        for(int j=0;j<i;j++){
            DP[i] += DP[i - (j + 1)] * DP[j];
        }
    }

    cout<<DP[N/2]<<endl;

}