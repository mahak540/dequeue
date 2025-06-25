vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int>minque,maxque;
        int s=0,e=0;
        int resstart=0,resend=0;
        int n=arr.size();
        while(e<n)
        {
            while(!minque.empty() && arr[minque.back()]>arr[e])
            minque.pop_back();
            while(!maxque.empty() && arr[maxque.back()]<arr[e])
            maxque.pop_back();
            
            minque.push_back(e);
            maxque.push_back(e);
            
            while(arr[maxque.front()]-arr[minque.front()] > x){
                if(s==minque.front())
                minque.pop_front();
                if(s==maxque.front())
                maxque.pop_front();
                
                s+=1;
            }
            if(e-s > resend-resstart)
            {
                resstart=s;
                resend=e;
            }
            e+=1;
        }
        vector<int>res;
        for(int i=resstart;i<=resend;i++){
        res.push_back(arr[i]);
        }
        
        return res;
    }
