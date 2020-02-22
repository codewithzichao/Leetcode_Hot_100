#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
/*
滑动窗口的思想。
*/
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;

        int left=0,right=0;
        unordered_map<char,int> m;
        int maxsize=0;

        while(right<s.size()){
            char c1=s[right];
            m[c1]++;
            right++;

            while(m[c1]>1){
                char c2=s[left];
                m[c2]--;
                left++;
            }

            maxsize=max(maxsize,right-left);

        }

        return  maxsize;
    }
};

int main(){
	string s;
	cin>>s;
	Solution so1;
	int ans=so1.lengthOfLongestSubstring(s);
	printf("%d\n",ans);
	return 0;



}