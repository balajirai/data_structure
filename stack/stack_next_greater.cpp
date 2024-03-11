#include <bits/stdc++.h>
using namespace std;

// Next Greater element [NGE]
vector<int> nextGreaterElement(vector<int>& arr, int n){
	vector<int>ans(n);
	stack<int>st;
	st.push(-1);
	for(int i=n-1; i>=0; i--){
		int curr = arr[i];
		while(st.top() <= curr && st.top()!=-1){
			st.pop();
		}
		// ans will be st.top()
		ans[i] = st.top();
		st.push(curr);
	}
	return ans;
}

int main(){
    int n;
    cout<<"Number of Elements : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the Elements : ";
    for(int &a:arr) cin>>a;

    cout<<"Next Greater Elements : ";
    vector<int>ans = nextGreaterElement(arr, n);
    for(int &a:ans) cout<<a<<" ";
    cout<<endl;
    return 0;
}