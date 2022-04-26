#include <iostream>

int stepproblem(int n){
    int dp[] = {1, 2}, sum = 0;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return dp[0];
    }
    if(n == 2){
        return dp[1];
    }
	
    for(int i = 2; i < n; i++){
        sum = dp[0] +dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
		//std::cout << sum << std::endl;
    }
    return sum;
}





int main(){
    int n;
    std::cin >> n;
	std::cout << stepproblem(n) << std::endl;
	//std::cin >> n;
	return 0;
}