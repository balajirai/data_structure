#include <bits/stdc++.h>
using namespace std;

// lower bound ----- smallest index for which arr[i] >= x
int lowerBound(vector<int> &nums, int k){
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high){
        int mid = (low + high) / 2;
        if (nums[mid] >= k){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main(){
    int n,k;
    cout<<"Enter the array length : ";
    cin>>n;
    vector<int>nums(n,0);
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<"Enter the target number : ";
    cin>>k;
    int lb_idx = lowerBound(nums,k);  // lower bound index
    cout<<"The Lower bound is : "<<((lb_idx < n) ? nums[lb_idx] : -1 )<<endl;

return 0;
}