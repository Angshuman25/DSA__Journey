class Solution {
public:
    int countPrimes(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(n <= 2) return 0;

        static bitset<5000005>isPrime;
        isPrime.set();

        int primecount = 1;

        for(int i=3; i<n; i+=2) {
            if(isPrime[i]) {
                primecount++;
                if((long long)i*i < n) {
                    for(int j=i*i; j<n; j+=2*i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
        return primecount;
    }
};