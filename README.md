## 前言

本repo主要记录了**leetcode上的Hot100题**， 采用C++实现。并且每一道题均有完整的实现，包括：**Solution部分、以及main部分**。 以两数之和这道题为例，具体如下：

> ```c++
> #include<stdio.h>
> #include<string.h>
> #include<string>
> #include<vector>
> #include<algorithm>
> #include<unordered_map>
> using namespace std;
> 
> class Solution{
> 	public:
> 	/*
> 	思路：当然暴力解是能解出来的，时间复杂度为O(n^2)；时间复杂度太大了。所以换一种思路，采用哈希表，时间复杂度为O(n).
> 	*/
> 	vector<int> twoSum(vector<int>& nums, int target) {
> 		vector<int> vec;
> 		
> 		unordered_map<int,int>  m;
> 		for(int i=0;i<nums.size();i++){
> 			if(m.find(target-nums[i])!=m.end()){
> 				vec.push_back(i);
> 				vec.push_back(m[target-nums[i]]);
> 				return vec;
> 			}
> 
> 			m[nums[i]]=i;
> 		}
> 
> 		return vec;
> 	}
> };
> 
> int main(){
> 	int n,target;
> 	scanf("%d%d",&n,&target);
> 	vector<int> nums;
> 	for(int i=0;i<n;i++){
> 		int x;
> 		scanf("%d",&x);
> 		nums.push_back(x);
> 	}
> 
> 	Solution so1;
> 	vector<int> ans=so1.twoSum(nums,target);
> 	printf("%d,%d\n",ans[0],ans[1]);
> 	return 0;
> 	
> }
> ```



## Hot100题目列表

|                         **Problems**                         |                       **My_Solution**                        | **Language** |
| :----------------------------------------------------------: | :----------------------------------------------------------: | :----------: |
|   [1.两数之和](https://leetcode-cn.com/problems/two-sum/)    | [1.两数之和.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/1.两数之和.cpp) |     C++      |
| [2.两数相加](https://leetcode-cn.com/problems/add-two-numbers/) | [2.两数相加.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/2.两数相加.cpp) |     C++      |
| [3.无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) | [3.无重复字符的最长子串.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/3.无重复字符的最长子串.cpp) |     C++      |
|    [15.三数之和](https://leetcode-cn.com/problems/3sum/)     | [15.三数之和.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/15.三数之和.cpp) |     C++      |
| [20.有效的括号](https://leetcode-cn.com/problems/valid-parentheses/) | [20.有效的括号.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/20.有效的括号.cpp) |     C++      |
| [21.合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) | [21.合并两个有序链表.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/21.合并两个有序链表.cpp) |     C++      |
| [53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) | [53.最大子序和.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/53.最大子序和.cpp) |     C++      |
| [70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) | [70.爬楼梯.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/70.爬楼梯.cpp) |     C++      |
| [76.最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) | [76.最小覆盖子串.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/76.最小覆盖子串.cpp) |     C++      |
| [438.找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) | [438.找到字符串中所有字母异位词.cpp](https://github.com/codewithzichao/Leetcode_Hot_100/blob/master/code/438.找到字符串中所有字母异位词.cpp) |     C++      |
|                                                              |                                                              |              |

持续更新中......

