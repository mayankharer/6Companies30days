class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        // sum to store the sum of all element in the array
        // original is product of all elemts with indices i in given array
        long sum = 0, original = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            original += i * nums[i];
        }

        long maximum = original;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--)
        {
            original += sum - (nums[i] * n);
            maximum = max(original, maximum);
        }
        return maximum;
    }
};

// class Solution {
// public:
//     // vector<int>& rotateFunc(vector<int> & v){

//     void rotateFunc(vector<int> & v){
//         reverse(v.begin(), v.end());
//         reverse(v.begin() + 1, v.end());
//         // return v;
//     }

//     int product(vector<int>& nums){
//         int sol = 0;
//         for (int i = 1; i < nums.size(); i++)
//         {
//             sol = sol + i * (nums[i]);
//         }
//         return sol;
//     }

//     int maxRotateFunction(vector<int>& nums) {
//         if(nums.size() <= 1) return 0;
//         int max_val=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             max_val = max(max_val,product(nums));
//             rotateFunc(nums);
//         }
//         return max_val;

//     }
// };