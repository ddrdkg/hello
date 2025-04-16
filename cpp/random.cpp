#include <iostream>
#include <vector>
#include <random>
#include <fstream> // Include for file operations
#include <algorithm>

int main() {
    const size_t count = 999999;
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

    // Open the output file
    std::ofstream outFile("randomnumber.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error opening file randomnumber.txt for writing." << std::endl;
        return 1; // Indicate error
    }

    // Write the generated numbers to the file
    std::cout << "Writing 100 random numbers between 1 and 99 to randomnumber.txt..." << std::endl;
    for (size_t i = 0; i < count; ++i) {
        outFile << numbers[i] << std::endl;
    }

    outFile.close(); // Close the file (good practice, though RAII handles it)

    std::cout << "Finished writing to randomnumber.txt." << std::endl;

    return 0;
}