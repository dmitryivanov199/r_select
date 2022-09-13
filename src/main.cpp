#include <iostream>

#include "r_select.hpp"

void run_tests();

unsigned int get_random_array_number();

void fill_array(int *a, unsigned int n);

void print_array(int *a, unsigned int n);

int main() {
    run_tests();
    return 0;
}

void run_tests() {
    const unsigned int n{get_random_array_number()};
    int a[n];
    fill_array(a, n);
    print_array(a, n);
    unsigned int i;
    std::cout << "Input i" << std::endl;
    std::cout << ">";
    std::cin >> i;
    std::cout << r_select(a, n, i) << std::endl;
}

unsigned int get_random_array_number() {
    const unsigned int min{1};
    const unsigned int max{10};
    std::srand(time(0));
    return min + std::rand() % (max - min + 1);
}

void fill_array(int *a, unsigned int n) {
    const int min{-100};
    const int max{100};
    std::srand(time(0));

    for (unsigned int i{0}; i < n; i++) {
        a[i] = min + std::rand() % (max - min + 1);
    }
}

void print_array(int *a, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}
