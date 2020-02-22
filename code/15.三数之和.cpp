#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
	/*
	双指针法。主要需要注意的是，要去重复！
	*/
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ans;
		if(nums.size()<3) return ans;

		sort(nums.begin(),nums.end());

		for(int i=0;i<nums.size();i++){
			int j=i+1;
			int k=nums.size()-1;
			while(j<k){
				int temp=nums[i]+nums[j]+nums[k];
				if(temp==0){
					vector<int> a;
					a.push_back(nums[i]);
					a.push_back(nums[j]);
					a.push_back(nums[k]);
					ans.push_back(a);
					while(j<k && (nums[j]==nums[j+1])) j++;//去重复
					while(j<k && (nums[k]==nums[k-1])) k--;//去重复
					j++;
					k--;
				}
				else if(temp>0) k--;
				else j++;

				while(i+1<nums.size() && nums[i]==nums[i+1] ) i++;
			}

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
	vector<vector<int> > ans=so1.threeSum(nums);
	for(int i=0;i<ans.size();i++){
		printf("%d,%d,%d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}