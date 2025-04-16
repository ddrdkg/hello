#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

int main() {
    // Generate 1 million random integers
    const size_t size = 1'000'000;
    std::vector<int> data(size);

    // Seed with a real random value, if available
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1'000'000);

    for (size_t i = 0; i < size; ++i) {
        data[i] = dist(gen);
    }

    // Measure sorting time
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(data.begin(), data.end());
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate and display elapsed time
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken to sort 1 million integers: " 
              << elapsed.count() << " seconds" << std::endl;

    return 0;
}