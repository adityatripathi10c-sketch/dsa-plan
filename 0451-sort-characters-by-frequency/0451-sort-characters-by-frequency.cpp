class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        for(char c:s){
            map[c]++;
        }
        vector<pair<char,int>>vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(),[](const pair<char,int>&a,const pair<char,int>&b){
            return a.second>b.second;
        });
        string result="";
        for(const auto& p:vec){
            result+=string(p.second,p.first);
        }
        return result;
    }
};