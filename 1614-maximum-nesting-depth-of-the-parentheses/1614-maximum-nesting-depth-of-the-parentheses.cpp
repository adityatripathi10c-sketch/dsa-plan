class Solution {
public:
    int maxDepth(string s) {
        int current=0;
        int maxdepth=0;
        for(char c:s){
            if(c=='('){
                current++;
                maxdepth=max(maxdepth,current);
            }else if(c==')'){
                current--;
            }
        }return maxdepth;
    }
};