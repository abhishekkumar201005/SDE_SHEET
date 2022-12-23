class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> res(n, -1);
            stack<int> s;

           	//in worst case we have to traverse array 2n times
            for (int i = 0; i < n * 2; i++)
            {
               	// if we reach end just change the index to 0
                // int ind = (i >= n) ? i - n : i;
                int ind=i%n;
                while (!s.empty() && nums[s.top()] < nums[ind])
                {
                    res[s.top()] = nums[ind];
                    s.pop();
                }
                s.push(ind);
            }
            return res;
        }
};