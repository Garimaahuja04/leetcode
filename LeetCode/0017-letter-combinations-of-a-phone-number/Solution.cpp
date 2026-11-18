
class Solution {
public:

    void solve(string digits, int index, string &temp,
               vector<string> &ans, vector<string> &mapping)
    {
        // Base case
        if(index == digits.length())
        {
            ans.push_back(temp);
            return;
        }

        // Get letters corresponding to current digit
        string letters = mapping[digits[index] - '0'];

        // Try every possible character
        for(int i = 0; i < letters.length(); i++)
        {
            temp.push_back(letters[i]);

            solve(digits, index + 1, temp, ans, mapping);

            // Backtracking
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if(digits.empty())
            return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string temp = "";

        solve(digits, 0, temp, ans, mapping);

        return ans;
    }
};
