class Solution {
private:
    int toDay(string s) {
    int m = stoi(s.substr(0, 2));
    int d = stoi(s.substr(3, 2));
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    for (int i = 0; i < m - 1; i++) {
        total += days[i];
    }
    return total + d;
}
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        int StartA=toDay(aa);
        int StartB=toDay(ab);
        int EndA=toDay(la);
        int EndB=toDay(lb);
        int a=max(StartA,StartB);
        int b=min(EndA,EndB);
        int ans=b-a+1;
        return max(0,ans);
    }
};