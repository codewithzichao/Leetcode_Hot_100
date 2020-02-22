#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
	int climbStairs(int n) {
		if(n<=0) return 0;
		if(n<=2) return n;

		vector<int> dp(n+1,1);
		dp[1]=1;
		dp[2]=2;

		for(int i=3;i<=n;i++){
			dp[i]=dp[i-1]+dp[i-2];
		}	

		return dp[n];
	}
};

int main(){
	int n;
	scanf("%d",&n);
	Solution so1;
	int ans=so1.climbStairs(n);

	printf("%d\n",ans);
	return 0;
}