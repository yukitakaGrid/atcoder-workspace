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

#define rep(i,a,b) for(long long i=(a);i<(b);i++)

void solve(long long N){
    long long max = 0;
    string dbStr;
    rep(i,1,N){
        long long cb = i*i*i;
        string str = to_string(cb);
        //cout << cb << endl;
        if(cb<=N){
            //cout << i << endl;
            bool isExist = false;
            rep(j,0,str.size()){
                if(str[j]!=str[str.size()-1-j]){
                    //cout << j << endl;
                    break;
                }
                isExist = true;
            }
            if(isExist==true){
                dbStr = str;
                max = cb;
            }
        }
        else break;
    }
    cout << dbStr << endl;
    rep(j,0,dbStr.size()){
        if(dbStr[j]==dbStr[dbStr.size()-1-j]){
            cout << "dbStr[j]:" << dbStr[j] << endl;
            cout << "dbStr[dbStr.size()-1-j]" << dbStr[dbStr.size()-1-j] << endl;
            cout << j << endl;
        }
    }
}


// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long N;
    std::scanf("%lld", &N);
    solve(N);
    return 0;
}
