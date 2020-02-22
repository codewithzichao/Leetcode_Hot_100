#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
	public:
	/*
	思路：当然暴力解是能解出来的，时间复杂度为O(n^2)；时间复杂度太大了。所以换一种思路，采用哈希表，时间复杂度为O(n).
	*/
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec;
		
		unordered_map<int,int>  m;
		for(int i=0;i<nums.size();i++){
			if(m.find(target-nums[i])!=m.end()){
				vec.push_back(i);
				vec.push_back(m[target-nums[i]]);
				return vec;
			}

			m[nums[i]]=i;
		}

		return vec;
	}
};

int main(){
	int n,target;
	scanf("%d%d",&n,&target);
	vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		nums.push_back(x);
	}

	Solution so1;
	vector<int> ans=so1.twoSum(nums,target);
	printf("%d,%d\n",ans[0],ans[1]);
	return 0;
	
}