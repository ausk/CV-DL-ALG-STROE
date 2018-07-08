#include <stdio.h>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

/*
    LCS:最长公共子序列
*/

int LCS(string s1, string s2)
{
    vector<int> arr(s2.size()+1, 0);
    vector<vector<int> > dp(s1.size()+1, arr);
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("LCS of %s and %s is %d\n", s1.c_str(), s2.c_str(), dp[s1.size()][s2.size()]);
    return dp[s1.size()][s2.size()];
}



int main()
{
    string test_str1 = "ababbasbcsws";
    string test_str2 = "bascawsias";

    assert(5 == LCS(test_str1, test_str2));

    return 0;
}
