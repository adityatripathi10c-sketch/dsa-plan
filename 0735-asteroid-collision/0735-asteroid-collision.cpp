class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(int curr:asteroids){
            bool destroy=false;
            while(!st.empty()&&st.back()>0&&curr<0){
                if(abs(curr)>st.back()){
                    st.pop_back();
                }else if(abs(curr)==st.back()){
                    st.pop_back();
                    destroy=true;
                    break;
                }
                else{
                    destroy=true;
                    break;
                }
            }
            if(!destroy){
                st.push_back(curr);
            }
        }
        return st;        
    }
};