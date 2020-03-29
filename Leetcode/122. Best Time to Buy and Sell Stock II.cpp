class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        if(prices.size() == 0)
            return 0;
        int prestock = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if((prices[i] - prestock) > 0)
            {
                profit += (prices[i] - prestock);
            }
            prestock = prices[i];
        }
        return profit;
    }
};
