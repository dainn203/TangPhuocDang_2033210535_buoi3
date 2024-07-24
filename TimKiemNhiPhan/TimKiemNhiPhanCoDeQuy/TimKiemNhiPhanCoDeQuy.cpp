#include <stdio.h>

// Hàm tìm kiếm nhị phân đệ quy
int binarySearchRecursive(int arr[], int low, int high, int target) {
	if (low > high) {
		return -1; // Phần tử không tồn tại
	}

	int mid = low + (high - low) / 2;

	if (arr[mid] == target) {
		return mid; // Phần tử tìm thấy
	}
	if (arr[mid] < target) {
		return binarySearchRecursive(arr, mid + 1, high, target); // Tìm kiếm trong nửa bên phải
	}
	else {
		return binarySearchRecursive(arr, low, mid - 1, target); // Tìm kiếm trong nửa bên trái
	}
}

int main() {
	int arr[] = { 1, 3, 5, 7, 6, 11, 13, 15, 17, 19 }; // Mảng đã được sắp xếp
	int size = sizeof(arr) / sizeof(arr[0]);
	int target;

	printf("Nhap phan tu can tim: ");
	scanf("%d", &target);

	int result = binarySearchRecursive(arr, 0, size - 1, target);

	if (result != -1) {
		printf("Phan tu %d duoc tim thay tai chi so %d\n", target, result);
	}
	else {
		printf("Phan tu %d khong ton tai trong mang\n", target);
	}

	return 0;
}