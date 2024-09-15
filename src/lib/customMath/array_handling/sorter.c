#include "../utilities/math_utils.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief Bubble sorting algorithm implementation
/// @param array integer 1D array
/// @param size integer size of the input array
void int_bubble_sort(int array[], int size) {
    unsigned int swap_flag = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap_flag = 1;
                int_var_swap(&array[j+1], &array[j]);
            }
        }
        if (swap_flag != 1) {
            break;
        }
    }
}


void merge(int array [], int start_index, int mid_index, int end_index) {
    int n1 = mid_index - start_index + 1;
    int n2 = end_index - mid_index;

    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) {
        left[i] = array[start_index + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = array[mid_index + 1 + j];
    }
    
    int i = 0, j = 0, k = start_index;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i < n1) {
        array[k++] = left[i++];
    }
    while (j < n2) {
        array[k++] = right[j++];
    }

    free(left);
    free(right);
}

void int_merge_sort(int array[], int size) {
    int block_size;
    int start_index;
    
    for (block_size = 1; block_size < size; block_size *= 2) {
        for (start_index = 0; start_index < size - block_size; start_index += 2 * block_size) {
            int mid_index = start_index + block_size - 1;
            int end_index = ((start_index + (2 * block_size - 1)) < size) ? ((start_index + (2 * block_size) - 1)) : (size - 1);
            merge(array, start_index, mid_index, end_index);
        }
    }
}
