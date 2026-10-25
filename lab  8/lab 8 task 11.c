#include <stdio.h>
int square(int x){
	return x*x;
}
int negate (int x){
	return -x;
}
int even (int x){
	return x % 2 ==0;
}
 int positive(int x) {
    return x > 0;
}
void applyToArray(int *arr, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = fn(arr[i]);
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (pred(arr[i])) {
            count++;
        }
    }

    return count;
}

void printGeneric(void *data, char type, int n) {
    if (type == 'i') {
        int *p = (int *)data;

        for (int i = 0; i < n; i++) {
            printf("%d ", p[i]);
        }
    }
    else if (type == 'f') {
        float *p = (float *)data;

        for (int i = 0; i < n; i++) {
            printf("%.2f ", p[i]);
        }
    }
    else if (type == 'c') {
        char *p = (char *)data;

        for (int i = 0; i < n; i++) {
            printf("%c ", p[i]);
        }
    }
    else {
        printf("Invalid type '%c' for printGeneric", type);
    }

    printf("\n");
}

int main() {
    int arr[] = {3, -2, 8, -5, 6};
    float values[] = {1.50f, 2.25f};
    int n;

    do {
        printf("Enter n (1-50): ");
        scanf("%d", &n);

        if (n < 1 || n > 50) {
            printf("Invalid size\n");
        }
    } while (n < 1 || n > 50);

    if (n > 5) {
        printf("Only 5 array elements are available.\n");
        return 0;
    }

    printf("Original: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);

    printf("After negate: ");
    printGeneric(arr, 'i', n);

    printf("Positive values after negate: %d\n",
           countIf(arr, n, positive));

    printf("Even values after negate: %d\n",
           countIf(arr, n, even));

    printf("Float print (type f): ");
    printGeneric(values, 'f', 2);

    printGeneric(arr, 'x', n);

    return 0;
}








































