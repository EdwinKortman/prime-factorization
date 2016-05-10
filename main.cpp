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
    std::vector <bool> prime(n, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    std::vector<int> primes;

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

/**
 * var int n
 *
 * Determine prime factors for n
 */
std::vector <int> prime_factorization(int n) {
    std::vector <int> prime_factors;

    for (int prime : get_primes(n)) {
        if (n <= 1) break;

        while (n % prime == 0) {
            prime_factors.push_back(prime);
            n = n / prime;
        }
    }

    return prime_factors;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "usage-error: " << argv[0] << " n" << std::endl;
        return 1;
    }

    int n = atoi(argv[1]);

    std::cout << "Prime factors for " << n << std::endl;

    for (int p : prime_factorization(n)) {
        std::cout << p << std::endl;
    }


    return 0;
}