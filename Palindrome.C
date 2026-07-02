#include <stdio.h>

int isPalindrome(int *arr, int size);

int main() {
    int arr[100], size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if (isPalindrome(arr, size)) {
        printf("The array is a palindrome.\n");
    } else {
        printf("The array is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(int *arr, int size) {
    int i;

    for (i = 0; i < size / 2; i++) {
        if (*(arr + i) != *(arr + size - 1 - i)) {
            return 0;   // Not a palindrome
        }
    }

    return 1;   // Palindrome
}


 

 

