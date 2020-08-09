#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,W;
    cin>>N>>W;

    vector<vector <long long> > dp (N+1,vector<long long>(W+1,0));

    for (int i =0;i<N;i++){
        int w,v;
        cin>>w>>v;
        for (long long weight=0;weight <W+1;weight++){
            if (weight-w >=0){
                dp[i+1][weight] = max(dp[i+1][weight],dp[i][weight-w]+v);

            }

            dp[i+1][weight] = max(dp[i+1][weight],dp[i][weight]);


        }
    }

    std::vector<long long>::iterator a=max_element(dp.at(N).begin(),dp.at(N).end());
    size_t a_index = std::distance(dp.at(N).begin(),a);
    cout<<dp[N][a_index]<<endl;

}