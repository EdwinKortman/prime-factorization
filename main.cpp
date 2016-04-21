#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

/**
 * Sieve of Eratosthenes
 * Source: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
int sieve(int n)
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


    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            std::cout << p << std::endl;
        }
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

    cout << "Prime numbers smaller than or equal to " << n << endl;
    sieve(n);


    return 0;
}