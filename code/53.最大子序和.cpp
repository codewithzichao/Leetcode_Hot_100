#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
	/*
	动态规划。
	*/
	int maxSubArray(vector<int>& nums) {
		if(nums.size()==0) return 0;

		int ans=nums[0];
		int sum=0;

		for(int i=0;i<nums.size();i++){
			if(sum>0){
				sum+=nums[i];
			}
			else{
				sum=nums[i];
			}

			ans=max(ans,sum);
		}	

		return ans;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		nums.push_back(x);
	}

	Solution so1;
	int ans=so1.maxSubArray(nums);
	printf("%d\n",ans);

	return 0;
}