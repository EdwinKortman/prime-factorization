#include <iostream>
#include <vector>


/**
 * var int n
 *
 * Generate a set of primes by using a Sieve of Erathosthenes
 * Source: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
std::vector<int> get_primes(int n)
{
    bool prime[n + 1];
    std::memset(prime, 1, sizeof prime);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    std::vector<int> primes;

    for (int p = 1; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

/**
 * var int n
 * var int p
 *
 * Determine if n divided by p has a remainder
 */
int divisible(int n, int p) {
    if (n % p == 0) {
        return n / p;
    }
    return 0;
}

/**
 * var int n
 *
 * Determine prime factors for n
 */
std::vector <int> prime_factorization(int n) {
    std::vector <int> primes = get_primes(n);
    std::vector <int> prime_factors;

    while (true) {
        if (n <= 1) {
            return prime_factors;
        }

        std::vector <int> prime_candidates;

        for (int p = 0; p < primes.size(); p++) {
            if (primes[p] > n) break;

            if (divisible(n, primes[p]) != 0) {
                prime_candidates.push_back(primes[p]);
            }
        }

        int prime = *std::max_element(std::begin(prime_candidates), std::end(prime_candidates));

        prime_factors.push_back(prime);
        n = n / prime;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "usage-error: " << argv[0] << " n" << std::endl;
        return 1;
    }

    int n = atoi(argv[1]);

    std::cout << "Prime factors for " << n << std::endl;
    std::vector<int> prime_factors = prime_factorization(n);

    for (int i = 0; i < prime_factors.size(); i++) {
        std::cout << prime_factors[i] << std::endl;
    }


    return 0;
}