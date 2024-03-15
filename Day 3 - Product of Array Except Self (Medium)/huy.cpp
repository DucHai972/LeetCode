// quite clumsy, not optimized than the "Prefix suffix product array " solution of Hieu :D
class Solution {
public:
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<int> prods(int x) {
        vector<int> v(10, 0);
        for (int i = 0; i < 10; i++) {
            int r = primes[i];
            v[i] = 0;
            while (r <= x && x % r == 0) {
                r *= primes[i];
                v[i]++;
            }
        }
        return v;
    }
    int pow(int a, int p) {
        if (p == 0)
            return 1;
        if (p == 1)
            return a;
        int t = pow(a, p >> 1);
        if (p % 2)
            return t * t * a;
        return t * t;
    }
    int fact[100007][11] = {0};
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt0 = 0, cntn = 0;
        int p[11] = {0};
        for (int i = 0; i < nums.size(); i++) {
            vector<int> v;
            if (nums[i] < 0)
                v = prods(-nums[i]), cntn++;
            else
                v = prods(nums[i]);
            for (int j = 0; j < 10; j++)
                p[j] += v[j], fact[i][j] += v[j];
            cnt0 += (nums[i] == 0);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> v = prods(nums[i]);
            long long t = 1;
            if (cnt0 - (nums[i] == 0) > 0) {
                res.push_back(0);
                continue;
            }
            if ((cntn - (nums[i] < 0)) % 2)
                t = -1;
            for (int j = 0; j < 10; j++)
                t *= pow(primes[j], p[j] - fact[i][j]);
            res.push_back(t);
        }
        return res;
    }
};
