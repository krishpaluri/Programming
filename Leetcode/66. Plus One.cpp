class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry =0;
        vector<int> ans;
        if(len-1 >= 0)
        {
            carry = (digits[len-1] + 1) > 9 ? 1 : 0;
            digits[len-1] = (digits[len-1] + 1) % 10;
        }
        for(int i=len-2;i>=0;i--)
        {
            int temp = carry;
            carry = (digits[i]+carry) > 9 ? 1 : 0;
            digits[i] = (digits[i] + temp) % 10;

        }
        if(carry)
        {
            ans.push_back(1);
        }
        for(int i=0;i<len;i++)
        {
            ans.push_back(digits[i]);
        }
        return ans;

    }
};
