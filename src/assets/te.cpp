#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi solve(vi &nums, int interns, int timeTaken){
	int n=nums.size();
	vi ans(n);
	priority_queue<int, vi, greater<int>>pq;
	for(int i=0; i<min(interns, n); i++){
		pq.push(nums[i]+timeTaken);
		ans[i]=nums[i]+timeTaken;
	}
	if(interns>=n)return ans;
	for(int i=interns; i<n; i++){
		ans[i]=max(nums[i], pq.top())+timeTaken;
		pq.pop();
		pq.push(ans[i]);
	}
	return ans;
}

string canInternsDoTheTask(int tasks, int n1, int n2, int n3, int t, int d){
	vi arr(tasks, 0);
	vi v1=solve(arr, n1, t);
	vi v2=solve(v1, n2, t+2);
	vi v3=solve(v2, n3, t-2);
	int time=v3[tasks-1];
	if(time<=d){
		return "Yes "+to_string(time);
	}else{
		return "No "+to_string(time-d);
	}
}

int main(){
    string ans = canInternsDoTheTask(1, 1, 1, 1, 5, 20);
    cout<<ans;
    return 0;
}