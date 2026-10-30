class Solution {
public:
    static const long long MOD = 1000000007;

    pair<long long, long long> fib(long long n) {
        if (n == 0)
            return {0, 1};

        auto p = fib(n / 2);
        long long a = p.first;
        long long b = p.second;

        long long c = a * ((2 * b % MOD - a + MOD) % MOD) % MOD;
        long long d = (a * a % MOD + b * b % MOD) % MOD;

        if (n % 2 == 0)
            return {c, d};

        return {d, (c + d) % MOD};
    }

    int countGoodStrings(long long n) {
        // Answer = 2 * Fibonacci(n)
        return (2 * fib(n).first) % MOD;
    }
};