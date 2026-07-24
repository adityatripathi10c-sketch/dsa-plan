class Solution {
private:
    long long speed(vector<int>&piles,int k){
        int total_hours=0;
        for(int pile:piles){
            total_hours+=(pile+k-1)/k;
        }
        return total_hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<right){
            int mid=left+(right-left)/2;
            if(speed(piles,mid)<=h){
                right=mid;
            }else{
                left=mid+1;
            }
        }return left;
    }
};