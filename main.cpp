#include <iostream>  // cout
#include <array>
#include "tasks.hpp"

using namespace std;

bool swap_args_test();
bool reverse_1d_array_test();
bool reverse_1d_array_with_pointers_test();
bool find_max_element_test();
bool find_odd_numbers_test();
void allocate_2d_array_test();

int main() {
    cout << "swap_args_test: " << swap_args_test() << endl;
    cout << "reverse_1d_array_test: " << reverse_1d_array_test() << endl;
    cout << "reverse_1d_array_with_pointers_test: " << reverse_1d_array_with_pointers_test() << endl;
    cout << "find_max_element_test: " << find_max_element_test() << endl;
    cout << "find_odd_numbers_test: " << find_odd_numbers_test() << endl;
    allocate_2d_array_test();

    return 0;
}

bool swap_args_test(){
    int a = 5;
    int b = 10;
    swap_args(&a, &b);

    if (b == 5 && a == 10)
        return true;
    return false;
}

bool reverse_1d_array_test(){
    vector<int> myVector= {1,2,3,4,5};
    vector<int> expectingResult = {5,4,3,2,1};

    reverse_1d_array(myVector);

    if (myVector == expectingResult)
        return true;
    return false;
}

bool reverse_1d_array_with_pointers_test(){
    vector<int> myVector= {1,2,3,4,5};
    vector<int> expectingResult = {5,4,3,2,1};

    reverse_1d_array(&myVector[0], &myVector[myVector.size()-1]);
    if (myVector == expectingResult)
        return true;
    return false;
}

bool find_max_element_test(){
    int array[] = {1,2,3,4,5,100,50,200};

    int *result = find_max_element(array, 8);

    if (*result == 200)
        return true;
    return false;
}

bool find_odd_numbers_test() {
    vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result = find_odd_numbers(myVector);

    for (int elem: result) {
        if (elem % 2 == 0)
            return false;
    }
    return true;
}

void allocate_2d_array_test(){
    int** array_2d = allocate_2d_array(5,5,5);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << array_2d[i][j] << " ";
        }
        cout << endl;
    }
}
