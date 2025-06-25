int getScore(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        vector<int>dp(n,INT_MIN);
        
        dp[n-1]=arr[n-1];
        deque<int>dq;
        dq.push_back(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!dq.empty() && dq.front() > i+k)
            {
                dq.pop_front();
            }
            dp[i]=arr[i]+dp[dq.front()];
            while(!dq.empty() && dp[i]>=dp[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[0];
    }
