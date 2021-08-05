#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums(nums.size());
        for (auto i = 0; i < nums.size(); ++i) {
            strNums[i] = to_string(nums[i]);
        }
        //自定义排序
        sort(strNums.begin(), strNums.end(), compare);
        string ans;
        for (const auto& strNum : strNums) {
            ans += strNum;
        }

        if (ans.length() > 0 && ans[0] == '0') {
            return "0";
        }

        return ans;
    }

    static bool compare(const string str1, const string str2)
    {
        int length1 = str1.size();
        int length2 = str2.size();

        int length = min(length1, length2);
        auto i = 0;
        //如果出现前几个字母相同的情况
        while (i < length) {
            if (str1[i] != str2[i]) {
                return str1[i] > str2[i];
            }

            ++i;
        }

        string compare1 = str1 + str2;
        string compare2 = str2 + str1;

        return compare1 > compare2;
    }
};
