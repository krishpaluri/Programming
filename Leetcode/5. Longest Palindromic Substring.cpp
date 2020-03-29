class Solution {
public:

    string longestPalindrome(string s) {
        int maxi = 0,maxlen =0;
        int dp[10001][1001];
        if(s.size() <= 1)
            return s;
        for(int i=0;i<1001;i++)
          for(int j=0;j<1001;j++)
          {
             dp[i][j] = -1;
          }
        int len = s.size() -1;
        for(int i=len;i>=0;i--)
        {
            for(int j=i;j<s.size();j++)
            {
                if(s[i] == s[j])
                {
                    if((i+1) >= (j-1) || dp[i+1][j-1] == 1)
                    {
                        if(maxlen < (j-i+1))
                        {
                           maxi = i;
                           maxlen = (j-i+1);
                        }
                        dp[i][j] = 1;
                    }
                    else
                        dp[i][j] = 0;
                }
                else
                    dp[i][j]=0;

            }
        }
        cout<<s.size();
        return s.substr(maxi,maxlen);

    }
};


// Approach #2

class Solution {
public:
    int PalindromeLen(string &s,int i, int j)
    {
        while(i>=0 && j<s.length() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j-i-1;
    }

    string longestPalindrome(string s) {
        int maxlen =-1;
        int maxi =0, maxj =0;
        int len1=0,len2=0;
        for(int i=0;i<s.length();i++)
        {
            // check for even palindrome
            len1 = PalindromeLen(s,i,i+1);
            //odd
            len2 = PalindromeLen(s,i,i);

            len1 = len1> len2 ? len1 : len2;
            if(len1 > maxlen)
            {

                maxlen = len1;
                maxi = i - ((len1-1)/2);
                //cout<<maxi <<"   " <<maxlen<<" "<<i<<endl;
            }
        }

        return s.substr(maxi,maxlen);
    }
};
