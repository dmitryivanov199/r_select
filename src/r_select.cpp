#include <iostream>

#include "r_select.hpp"

static void copy_array(int *dst, const int *src, unsigned int n);

static int make_r_select(int *a, unsigned int l, unsigned int r, unsigned int i);

static bool is_base_case(unsigned int l, unsigned int r);

static unsigned int choose_pivot_index(unsigned int l, unsigned int r);

static void swap_elements(int &a, int &b);

static unsigned int make_partition(int *a, unsigned int l, unsigned int r);

//-----------------------------------------------------------------------------------------

int r_select(const int *a, unsigned int n, unsigned int i) {
    int a_for_sorting[n];
    copy_array(a_for_sorting, a, n);

    if (i > n) {
        i = n;
    }

    return make_r_select(a_for_sorting, 0, n - 1, i - 1);
}

//-----------------------------------------------------------------------------------------

void copy_array(int *dst, const int *src, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        dst[i] = src[i];
    }
}

int make_r_select(int *a, unsigned int l, unsigned int r, unsigned int i) {
    if (is_base_case(l, r)) {
        return a[l + 1];
    }

    unsigned int pivot_index{choose_pivot_index(l, r)};
    swap_elements(a[l], a[pivot_index]);
    unsigned int j{make_partition(a, l, r)};
    unsigned int k{j - l + 1};

    if (i == k) {
        return a[j + 1];
    }
    else if (i < k) {
        return make_r_select(a, l, j - 1, i);
    }
    else {
        return make_r_select(a, j + 1, r, i - k);
    }
}

bool is_base_case(unsigned int l, unsigned int r) {
    return l == r;
}

unsigned int choose_pivot_index(unsigned int l, unsigned int r) {
    std::srand(time(0));
    return l + std::rand() % (r - l + 1);
}

void swap_elements(int &a, int &b) {
    int temp{a};
    a = b;
    b = temp;
}

unsigned int make_partition(int *a, unsigned int l, unsigned int r) {
    int p{a[l]};
    unsigned int i{l + 1};

    for (unsigned int j{l + 1}; j <= r; j++) {
        if (a[j] < p) {
            swap_elements(a[i], a[j]);
            i++;
        }
    }

    swap_elements(a[l], a[i - 1]);
    return i - 1;
}
