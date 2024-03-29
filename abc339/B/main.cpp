#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;

enum Direction{
    Up,
    Right,
    Down,
    Left
};

vector<vector<char>> solve(long long H, long long W, long long N){
    vector<vector<char>> map(H,vector<char>(W,'.'));
    int dir = Up;
    pair<int,int> pos = make_pair(0,0);
    //first:縦 second:横

    for(int i=0;i<N;i++){    
        //現在いるマスを塗り
        //回転処理
        if(map[pos.first][pos.second]=='.'){
            map[pos.first][pos.second] ='#';
            dir++;
        }
        else{
            map[pos.first][pos.second] ='.';
            dir--;
        }
        
        if(dir<Up)
            dir=Left;
        else if(dir>Left)
            dir=Up;

        //どちらに進むか？
        switch(dir){
            case Up:
                pos.first--;
                break;
            case Down:
                pos.first++;
                break;
            case Right:
                pos.second++;
                break;
            case Left:
                pos.second--;
                break;
        }

        //マスからはみ出している場合反転
        if(pos.first<0)
            pos.first=H-1;
        if(H<=pos.first)
            pos.first=0;
        if(pos.second<0)
            pos.second=W-1;
        if(W<=pos.second)
            pos.second=0;
    }

    return map;
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long H;
    std::scanf("%lld", &H);
    long long W;
    std::scanf("%lld", &W);
    long long N;
    std::scanf("%lld", &N);

    vector<vector<char>> ans(H,vector<char>(W,'.'));
    ans = solve(H, W, N);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
