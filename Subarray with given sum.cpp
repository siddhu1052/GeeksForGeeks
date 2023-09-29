class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int i=0,j=0;
        long long sum=0;
        vector<int>v;
        if(s==0){
            return {-1};
        }
        while(j<n and i<n)
        {
            
            
            if(sum+arr[j]<=s)
            {
                sum+=arr[j];
                j++;
                
                
            }
            else
            {
                sum-=arr[i];
                i++;
            }
            if(sum==s)
            { 
                v.push_back(i+1);
                v.push_back(j);
                return v;
            }
        }
        return {-1};
    }
};