// ifndef checks if the identifier RANDOM_UTILS_H has not been defined yet
#ifndef RANDOM_UTILS_H
// ifndef block starts here

// define the identifier RANDOM_UTILS_H to prevent double inclusion of the header file
#define RANDOM_UTILS_H

// include necessary header
#include <random>  // include random header for random number generation

/**
 * @brief Generate a random integer value between minVal and maxVal (inclusive).
 *
 * @param minVal Minimum value for random number generation.
 * @param maxVal Maximum value for random number generation.
 * @return Random integer value between minVal and maxVal.
 */
inline int getRandomValue(int minVal, int maxVal) {
    // Create a random device to obtain seed for random number generation
    std::random_device rd;

    // Create a Mersenne Twister pseudo-random number generator
    std::mt19937 gen(rd());

    // Create a uniform distribution for generating integers between minVal and maxVal
    std::uniform_int_distribution<> dis(minVal, maxVal);

    // Generate and return a random integer value between minVal and maxVal
    return dis(gen);
}

// endif closes the ifndef block
#endif // RANDOM_UTILS_H
// comment indicating the end of the ifndef block
