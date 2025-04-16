#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // Include for potential future use like shuffling or sorting

int main() {
    const size_t count = 100;
    std::vector<int> numbers(count);

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    // Define the range [1, 99]
    std::uniform_int_distribution<int> dist(1, 99);

    // Generate the numbers
    for (size_t i = 0; i < count; ++i) {
        numbers[i] = dist(gen);
    }

    // Optional: Print the generated numbers
    std::cout << "Generated 100 random numbers between 1 and 99:" << std::endl;
    for (size_t i = 0; i < count; ++i) {
        std::cout << numbers[i] << ( (i == count - 1) ? "" : ", ");
        if ((i + 1) % 10 == 0) { // Newline every 10 numbers for readability
             std::cout << std::endl;
        }
    }
     std::cout << std::endl;


    return 0;
}