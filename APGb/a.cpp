#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int sum(vector<int> scores) {
    // ここにプログラムを追記
    int ans =0;
    for (int i=0;i<scores.size();i++){
        ans += scores[i];
    }
    return ans;

}

// 3人の合計点からプレゼントの予算を計算して出力する関数
// 引数 sum_a: A君のテストの合計点
// 引数 sum_b: B君のテストの合計点
// 引数 sum_c: C君のテストの合計点
// 返り値: なし
void output(int sum_a, int sum_b, int sum_c) {
    // ここにプログラムを追記
    int ans =sum_a*sum_b*sum_c;
    cout<<ans<<endl;
}

// -------------------
// ここから先は変更しない
// -------------------

// N個の入力を受け取って配列に入れて返す関数
// 引数 N: 入力を受け取る個数
// 返り値: 受け取ったN個の入力の配列
vector<int> input(int N) {
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    return vec;
}

int main() {
    // 科目の数Nを受け取る
    int N;
    cin >> N;

    // それぞれのテストの点数を受け取る
    vector<int> A, B, C;
    A = input(N);
    B = input(N);
    C = input(N);

    // プレゼントの予算を出力
    output(sum(A), sum(B), sum(C));
}