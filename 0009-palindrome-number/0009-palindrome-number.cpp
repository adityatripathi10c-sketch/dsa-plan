class Solution {
public:
    bool isPalindrome(int x) {
        long s=0;
        if(x<0){
            return false;
        }
        else{
         long num=x;
            while(num>0){
                int temp=num%10;
                s=(s*10)+temp;
                num=num/10;
            }
            return x==s;
        }
    }
};