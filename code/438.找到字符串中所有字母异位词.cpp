#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include <set>
#include<unordered_map>
using namespace std;

class Solution{
	public:
	/*
	滑动窗口思想。https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/
	*/
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		if(s.size()==0) return ans;

		unordered_map<char,int> m_p;
		unordered_map<char,int> window;
		int left=0,right=0;

		int match=0;

		for(int i=0;i<p.size();i++) m_p[p[i]]++;

		while(right<s.size()){
			char c1=s[right];
			if(m_p.count(c1)){
				window[c1]++;
				if(window[c1]==m_p[c1]){
					match++;
				}
			}
			right++;

			while(match==m_p.size()){
				char c2=s[left];
				if(right-left==p.size()){
					ans.push_back(left);
				}
				if(m_p.count(c2)){
					window[c2]--;
					if(window[c2]<m_p[c2]){
						match--;
					}
				}
				left++;
			}
		}

		return ans;
	}
};

int main(){
	string s,p;
	cin>>s>>p;
	Solution so1;

	vector<int> ans=so1.findAnagrams(s,p);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}