#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

bool contains(vector<int> &arr, int e);

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs == nullptr || rhs == nullptr)
        return;
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows <= 0 || num_cols <= 0 )
        return nullptr;
    int** array_2d = new int*[num_rows];
    for (int i = 0; i < num_rows; ++i) {
        array_2d[i] = new int[num_cols]{init_value};
        fill(array_2d[i], array_2d[i]+num_cols, init_value);
    }
    return array_2d;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (arr_2d_source == nullptr || arr_2d_target == nullptr || num_cols <= 0 || num_rows <= 0)
        return false;
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    vector<int> result;

    for (int i = arr.size()-1; i >= 0; --i) {
        result.push_back(arr.at(i));
    }

    arr = result;
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin == nullptr || arr_end == nullptr)
        return;

    if (arr_begin >= arr_end)
        return;

    int *temp_arr_begin = arr_begin;
    int *temp_arr_end = arr_end;

    vector<int> reversedArray = {};

    while (arr_begin != arr_end+1){
        reversedArray.push_back(*arr_end);
        --arr_end;
    }

    bool flag = true;
    for (int i = 0; flag ; i++){
        if (temp_arr_begin == temp_arr_end)
            flag = false;

        *temp_arr_begin = reversedArray[i];
        temp_arr_begin++;
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr == nullptr || size <= 0)
        return nullptr;

    int* max_ptr = arr;
    int max_value = arr[0];

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= max_value) {
            max_value = arr[i];
            max_ptr = &arr[i];
        }
    }

    return max_ptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> result = {};

    for (int e: arr){
        if (e % 2 > 0)
            result.push_back(e);
    }

    return result;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> common_elements_vector = {};

    for (int i = 0; i < arr_a.size(); ++i) {
        for (int j = i; j < arr_b.size(); ++j) {
            if (arr_a[i] == arr_b[j] && !contains(common_elements_vector, arr_a[i]))
                common_elements_vector.push_back(arr_a[i]);
        }
    }
    std::sort(common_elements_vector.begin(), common_elements_vector.end()); // тесты почему-то не проходят, если число в массиве не отсортированы
    return common_elements_vector;
}

bool contains(vector<int> &arr, int e){
    for (int elem: arr) {
        if (elem ==  e)
            return true;
    }
    return false;
}