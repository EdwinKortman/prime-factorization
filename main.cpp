#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

/**
 * Sieve of Eratosthenes
 * Source: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
vector<int> sieve(int n)
{
    // Create array where all values are true
    bool prime[n + 1];
    std::memset(prime, 1, sizeof prime);


    // Start: 2
    // If: prime candidate squared is smaller than or equal to n
    // Then: p + 1
    for (int p = 2; p * p <= n; p++) {
        // If p in array prime is true
        if (prime[p]) {
            // Update all multiples of p in array and set to false
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

int division(int p, int n) {
    if (n % p == 0) {
        return n / p;
    }
    return 0;
}


std::vector <int> prime_defactorization(int n) {
    std::vector <int> primes;
    primes = sieve(n);

    std::vector <int> primes_defactored;

    while (true) {
        if (n <= 1) {
            return primes_defactored;
        }

        std::vector <int> prime_candidates;

        for (int p = 0; p < primes.size(); p++) {
            if (primes[p] > n) break;

            if (division(primes[p], n) != 0) {
                prime_candidates.push_back(primes[p]);
            }
        }

        int prime;
        prime = *std::max_element(std::begin(prime_candidates), std::end(prime_candidates));

        primes_defactored.push_back(prime);
        n = n / prime;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "usage-error: " << argv[0] << " n" << std::endl;
        return 1;
    }


    // Convert to int
    int n = atoi(argv[1]);

//    cout << "Prime numbers smaller than or equal to " << n << endl;
//    std::vector<int> primes;
//    primes = sieve(n);
//
//    for (int i = 0; i < primes.size(); i++) {
//        std::cout << primes[i] << std::endl;
//    }

    cout << "Prime factors for " << n << endl;
    std::vector<int> primes_defactors;
    primes_defactors = prime_defactorization(n);

    for (int i = 0; i < primes_defactors.size(); i++) {
        std::cout << primes_defactors[i] << std::endl;
    }


    return 0;
}