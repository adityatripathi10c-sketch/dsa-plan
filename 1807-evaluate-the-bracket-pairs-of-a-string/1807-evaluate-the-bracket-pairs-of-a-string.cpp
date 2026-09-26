#include<unordered_map>
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(const auto&pair:knowledge ){
            mp[pair[0]]=pair[1];
        }
        string result="";
        string curr_key="";
        bool in_bracket=false;
        for(char c:s){
            if(c=='('){
                in_bracket=true;
            }else if(c==')'){
                in_bracket=false;
                auto it=mp.find(curr_key);
                if(it!=mp.end()){
                    result+=it->second;
                }else{
                    result+='?';
                }
                curr_key.clear();
            }else{
                if(in_bracket){
                   curr_key+=c;
                }else{
                    result+=c;
                }
            }
        }
        return result;
    }
};