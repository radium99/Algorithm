#include <iostream>

// 병합 함수. (어려움)
void Merge(
	int* array,
	int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength
)
{
	// 인덱스.
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// 왼쪽 오른쪽 배열 요소를 비교해 더 작은 배열의 요소를 array에 복사.
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		// 왼쪽 배열의 항목이 더 작으면 array에 설정.
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		// 오른쪽 배열의 항목이 더 작으면 array에 설정.
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		// 병합된 배열의 인덱스 증가 처리.
		++mergedIndex;
	}

	// 위의 과정에서 왼쪽 배열의 남은 요소를 최종 배열에 복사.
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	// 위의 과정에 오른쪽 배열에 남은 요소를 최종 배열에 복사.
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++rightIndex;
		++mergedIndex;
	}
}

// 병합 정렬 함수(재귀).
void MergeSort(int* array, int length)
{
	// 종료 조건(더이상 나눌 수 없는 상태).
	if (length <= 1)
	{
		return;
	}

	// 배열 나누기.
	int mid = length / 2;

	// 나눠서 저장할 배열 선언 (공간 사용).
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	// 배열 복사. memcpy 함수로 메모리 통 복사.
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, (array + mid), sizeof(int) * (length - mid));

	// 왼쪽 배열 병합 정렬 (재귀).
	MergeSort(leftArray, mid);
	
	// 오른쪽 배열 병합 정렬 (재귀).
	MergeSort(rightArray, length - mid);

	// 병합.
	Merge(array, leftArray, mid, rightArray, (length - mid));

	// 동적 메모리 해제.
	delete[] leftArray;
	delete[] rightArray;
	
}

// 배열 항목 출력 함수.
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix) {

		std::cout << array[ix];

		// 마지막 원소 전까지는 콤마 출력.
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}

int main()
{
	// 자료 집합 1.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 항목 개수 구하기
	int length = _countof(array);

	// 출력.
	// 정렬 전.
	std::cout << "정렬 전: ";
	PrintArray(array, length);
	
	// 정렬.
	MergeSort(array, length);

	// 정렬 후.
	std::cout << "정렬 후: ";
	PrintArray(array, length);

	std::cin.get();
}