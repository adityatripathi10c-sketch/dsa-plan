class Solution {
private:
    void cleanspaces(string& s){
        int n=s.length();
        int i=0,j=0;
        while(i<n){
            while(i<n&&s[i]==' ')i++;
            if(i<n){
                if(j>0)s[j++]=' ';
                while(i<n&&s[i]!=' '){
                    s[j++]=s[i++];
                }
            }
        }s.resize(j);
    }
public:
    string reverseWords(string s) {
        cleanspaces(s);
        reverse(s.begin(),s.end());
        int start=0;
        for(int end=0;end<=s.length();end++){
            if(end==s.length()||s[end]==' '){
                reverse(s.begin()+start,s.begin()+end);
                start=end+1;
            }
        }return s;
    }
};