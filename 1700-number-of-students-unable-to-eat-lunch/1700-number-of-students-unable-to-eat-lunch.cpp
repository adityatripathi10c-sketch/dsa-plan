class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero=count(students.begin(),students.end(),0);
        int one=count(students.begin(),students.end(),1);
        for(int sandwitch:sandwiches){
            if(sandwitch==0){
                if(zero>0){
                    zero--;
                }
                else{
                    break;
                }
            }
            else if(sandwitch==1){
                if(one>0){
                    one--;
                }
                else{
                    break;
                }
            }
            
        }
        return zero+one;
    }
};