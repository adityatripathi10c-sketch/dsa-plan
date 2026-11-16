class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int MOD=1e9+7;
        vector<int>left(n),right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            int pse=st.empty()?-1:st.top();
            left[i]=i-pse;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            int nse=st.empty()?n:st.top();
            right[i]=nse-i;
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long crib=(1LL*arr[i]*right[i]*left[i])%MOD;
            ans=(ans+crib)%MOD;
        }
        return ans;
    }
};