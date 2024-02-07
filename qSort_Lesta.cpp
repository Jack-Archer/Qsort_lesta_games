#include <iostream>



void qSort(int *arr, int left_border, int right_border) {
    int pivot{arr[left_border]};
    int reset_left = left_border;
    int reset_right = right_border;

    while(left_border < right_border) {
        while((arr[right_border] >= pivot) && (left_border < right_border)) {
            --right_border;
        }
        if(left_border != right_border) {
            std::swap(arr[left_border], arr[right_border]);
            ++left_border;
        }
        while((arr[left_border] <= pivot) && (left_border < right_border)){
            ++left_border;
        }
        if(left_border != right_border) {
           std::swap(arr[left_border], arr[right_border]);
           --right_border;
        }
    }
    pivot = left_border;
    left_border = reset_left;
    right_border = reset_right;

    if(left_border < right_border) {
        qSort(arr, left_border, pivot - 1);
    }
    if(left_border < right_border) {
        qSort(arr, pivot + 1, right_border);
    }
}



int main() {

    int arr[]{9, 4, 7, 9, 13, 5, 8, 77, 21, 1, 6, 10, 9, 5,6,8,15,18,14,15,16};
    int s{sizeof(arr) / sizeof(*arr)};
    std::cout << s << std::endl;

    qSort(arr, 0, s - 1);

    for(int i = 0; i < s; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

return 0;
}
