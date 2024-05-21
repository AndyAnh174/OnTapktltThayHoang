#include <iostream>

int* findLongestIncreasingSubsequence(int arr[], int n) {
    int* longest_length = new int[n]; // Lưu độ dài của dãy con tăng dần dài nhất kết thúc tại arr[i]
    int* previous_index = new int[n]; // Lưu chỉ số của phần tử trước đó trong dãy con tăng dần dài nhất kết thúc tại arr[i]

    // Khởi tạo
    for (int i = 0; i < n; i++) {
        longest_length[i] = 1;
        previous_index[i] = -1;
    }

    // Duyệt qua từng phần tử trong dãy số
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j] + 1 && longest_length[i] < longest_length[j] + 1) {
                longest_length[i] = longest_length[j] + 1;
                previous_index[i] = j;
            }
        }
    }

    // Tìm độ dài lớn nhất của dãy con tăng dần
    int max_length = 1;
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (longest_length[i] > max_length) {
            max_length = longest_length[i];
            max_index = i;
        }
    }

    // Tạo dãy con tăng dần từ các chỉ số đã tìm được
    int* longest_subsequence = new int[max_length];
    int current_index = max_index;
    for (int i = max_length - 1; i >= 0; i--) {
        longest_subsequence[i] = arr[current_index];
        current_index = previous_index[current_index];
    }

    delete[] longest_length;
    delete[] previous_index;

    return longest_subsequence;
}

int main() {
    int arr[] = {5, 6, 1, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* longest_subsequence = findLongestIncreasingSubsequence(arr, n);
    
    // In ra dãy con tăng dần dài nhất
    std::cout << "Dãy con tăng dần liên tiếp theo số: ";
    for (int i = 0; i < n; i++) {
        if (longest_subsequence[i] != 0) {
            std::cout << longest_subsequence[i] << " ";
        }
    }
    std::cout << std::endl;
    
    delete[] longest_subsequence;

    return 0;
}
