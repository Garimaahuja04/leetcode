
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long long num = 0;

        // Step 1: Skip leading whitespaces
        while(i < n && s[i] == ' ')
        {
            i++;
        }

        // Step 2: Check sign
        if(i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+')
        {
            sign = 1;
            i++;
        }

        // Step 3: Convert digits into integer
        while(i < n && s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');

            // Step 4: Handle overflow
            if(sign * num > INT_MAX)
                return INT_MAX;

            if(sign * num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
