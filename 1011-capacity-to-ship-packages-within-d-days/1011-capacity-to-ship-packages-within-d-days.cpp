class Solution {
private:
    int daysneeded(vector<int>& weights,int capacity){
        int days=1;
        int currentload=0;
        for(int w:weights){
            if(currentload + w>capacity){
                days++;
                currentload=w;
            }else{
                currentload+=w;
            }
        }return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=0;
        for(int weight:weights){
            right+=weight;
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(daysneeded(weights,mid)<=days){
                right=mid;
            }else{
                left=mid+1;
            }
        }return left;
    }
};