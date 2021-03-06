#include <iostream>
#include <vector>

using namespace std;

int LongestInterval(vector<int> nums){
    int ans = 0;
    int n = nums.size();
    vector<int> res(n, 0);
    res[n-1] = n-1;
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            res[i] = res[i+1];
            ans = max(ans, res[i] - i);
        }else{
            for(int j = res[i+1]; j > i; j--){
                if(nums[j] > nums[i]){
                    res[i] = j;
                    ans = max(ans, res[i] - i);
                    break;
                }
            }
        }
    }
    return ans;
}

int maxji2(vector<int> nums) {
	int n = nums.size();
	vector<int> leftMin(n, nums[0]);
	vector<int> rightMax(n, nums[n-1]);
	int res = 0;
	for(int i = 1; i < n; i++) {
		leftMin[i] = min(leftMin[i-1], nums[i]);
	}
	for(int j = n - 2; j >= 0; j--) {
		rightMax[j] = max(rightMax[j+1], nums[j]]);
	}
	int i = 0; int j = 0;
	while(i < n && j < n) {
		if(rightMax[j] > leftMin[i]) {
			res = max(res, j - i);
			j++;
		} else
			i++;
	}
	return res;
}

int main()
{
    vector<int> nums = {3,5,4,2,1,7};
    cout << LongestInterval(nums) << endl;
    nums = {8,2,2,1,7};
    cout << LongestInterval(nums) << endl;
    return 0;
}
