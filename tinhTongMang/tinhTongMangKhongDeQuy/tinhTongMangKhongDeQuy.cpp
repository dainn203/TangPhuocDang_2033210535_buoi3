#include <stdio.h>
#include <stdlib.h>

// Hàm tính tổng không đệ quy bằng phương pháp chia để trị
int divideAndConquerSum(int arr[], int n) {
	int sum = 0;

	// Chia mảng thành hai phần bằng nhau và tính tổng từng phần
	for (int size = 1; size < n; size *= 2) {
		for (int left = 0; left < n; left += 2 * size) {
			int mid = left + size - 1;
			int right = left + 2 * size - 1;
			if (mid >= n) mid = n - 1;
			if (right >= n) right = n - 1;

			// Tính tổng cho đoạn từ left đến right
			for (int i = left; i <= right; i++) {
				sum += arr[i];
			}
		}
	}

	return sum;
}

int main() {
	int n;
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);

	// Cấp phát động mảng
	int *arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Khong du bo nho de cap phat mang\n");
		return 1;
	}

	printf("Nhap cac phan tu trong mang:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int result = divideAndConquerSum(arr, n);
	printf("Tong cua mang la: %d\n", result);

	// Giải phóng bộ nhớ
	free(arr);

	return 0;
}
