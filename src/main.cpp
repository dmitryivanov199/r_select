#include <iostream>

#include "r_select.hpp"

bool run_tests();

unsigned int get_random_array_number();

void fill_array(int *a, unsigned int n);

void copy_array(int *dst, const int *src, unsigned int n);

int compare_numbers(const void *a, const void *b);

unsigned int get_random_i(unsigned int n);

void print_array(int *a, unsigned int n);

int main() {
    if (run_tests()) {
        std::cout << "All tests passed successfully!" << std::endl;
    }
    else {
        std::cout << "Something went wrong..." << std::endl;
    }

    return 0;
}

bool run_tests() {
    const unsigned int tests_number{50000};

    for (unsigned int current_test{0}; current_test < tests_number; current_test++) {
        const unsigned int n{get_random_array_number()};
        int source_a[n];
        fill_array(source_a, n);

        int std_sorted_a[n];
        copy_array(std_sorted_a, source_a, n);
        std::qsort(std_sorted_a, n, sizeof(int), compare_numbers);

        unsigned int i{get_random_i(n)};
        int result{r_select(source_a, n, i)};

        if (i > n) {
            i = n;
        }

        if (std_sorted_a[i - 1] != result) {
            std::cout << "n = " << n << std::endl;
            std::cout << "i = " << i << std::endl;

            std::cout << "Source array:" << std::endl;
            print_array(source_a, n);

            std::cout << "Sorted array:" << std::endl;
            print_array(std_sorted_a, n);

            std::cout << "got result = " << result << std::endl;
            std::cout << "correct result = " << std_sorted_a[i - 1] << std::endl;

            return false;
        }
    }

    return true;
}

unsigned int get_random_array_number() {
    const unsigned int min{1};
    const unsigned int max{1000};
    std::srand(time(0));
    return min + std::rand() % (max - min + 1);
}

void fill_array(int *a, unsigned int n) {
    const int min{-100};
    const int max{100};

    for (unsigned int i{0}; i < n; i++) {
        std::srand(time(0));
        a[i] = min + std::rand() % (max - min + 1);
    }
}

void copy_array(int *dst, const int *src, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        dst[i] = src[i];
    }
}

int compare_numbers(const void *a, const void *b) {
    const int arg1{*static_cast<const int*>(a)};
    const int arg2{*static_cast<const int*>(b)};
    return arg1 > arg2;
}

unsigned int get_random_i(unsigned int n) {
    const unsigned int min{1};
    const unsigned int max{1000};
    std::srand(time(0));
    return min + std::rand() % (max - min + 1);
}

void print_array(int *a, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}
