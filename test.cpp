#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
const int maxn = 10010;
int A[maxn], dp[maxn];
 
void MaxSequence(int n) {
    vector<int> first, last;
    dp[0] = A[0];
    first.push_back(0);
    last.push_back(0);
    for(int i = 1; i < n; i++) {
        if(dp[i - 1] > 0){
            dp[i] = dp[i - 1] + A[i];
            first.push_back(first[i - 1]);
            if(A[i] < 0) last.push_back(i - 1);
            else last.push_back(i);
        } else {
            dp[i] = A[i];
            first.push_back(i);
            last.push_back(i);
        }
    }
    int k = 0;
    for(int i = 1; i < n; i++) {
        if(dp[k] < dp[i]) k = i;
    }
    if(dp[k] > 0){
        printf("%d %d %d\n", dp[k], A[first[k]], A[last[k]]);
    } else {
        printf("0 %d %d\n", A[0], A[n - 1]);
    }
    
}
 
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) && n != 0) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        MaxSequence(n);
    }
}