#include <iostream>
#include <string>
using namespace std;

int solve(const std::string &S){
    if(S.empty()){ 
        return 0;
    }

    int list[128] = {0}; 

    for(char c : S){
        list[static_cast<int>(c)]++;
    }

    int maxCount = 0;
    int maxChar = 0;
    for(int i = 0; i < 128; i++){
        if(list[i] > maxCount){
            maxCount = list[i];
            maxChar = i;
        }
    }

    return maxChar;
}

int main(){
    std::string S;
    std::cin >> S;
    int ans = solve(S);
    cout << static_cast<char>(ans) << endl;
    return 0;
}
