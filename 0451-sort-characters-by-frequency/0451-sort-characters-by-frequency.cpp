class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        vector<vector<char>> buckets(s.length()+1);
        for(auto pair:freq){
            char c=pair.first;
            int count = pair.second;
            buckets[count].push_back(c);
        }
        string result="";
        for(int i=s.length();i>0;i--){
            for(char c:buckets[i]){
                result.append(i,c);
            }
        }
    return result;
    }
};