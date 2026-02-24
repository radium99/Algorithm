#include <iostream>

// 실패 오류 값.
#define FAIL -1

// 재귀적 이진 탐색.
// array: 자료를 가지는 배열.
// target: 찾으려는 값.
// start: 검색 시작 인덱스.
// end: 검색 끝 인덱스.
int RecursiveBinarySearch(
	int* array,
	int target,
	int start,
	int end)
{
	// 종료 조건. (재귀함수는 항상 종료조건 먼저 구현.)
	if (start > end)
	{
		return -1;
	}
	
	// 중간 인덱스.
	int mid = (start + end) / 2;

	// 검색 성공 여부 확인.
	if (array[mid] == target)
	{
		return mid;
	}

	// 왼쪽 부분 배열 검색. (못 찾았을 경우)
	else if (array[mid] > target)
	{
		return RecursiveBinarySearch(
			array,
			target,
			start,
			mid -1
		);
	}

	// 오른쪽 부분 배열 검색. (못 찾았을 경우)
	return RecursiveBinarySearch(
		array,
		target,
		mid + 1,
		end
	);
}

// 반복적 이진 탐색 함수.
int InterativeBinarySearch(
	int* array,
	int target,
	int start,
	int end)
{
	// 조건부 무한 루프.
	while (start <= end)
	{
		// 중간 인덱스 구하기.
		int mid = (start + end) / 2;
		
		// 찾았는지 확인.
		if (array[mid] == target)
		{
			return mid;
		}

		// 왼쪽 검색.
		if (array[mid] > target)
		{
			end = mid - 1;
		}
		// 오른쪽 검색.
		else if (array[mid] < target)
		{
			start = mid + 1;
		}

	}
	
	// 못 찾은 경우 -1 반환.
	return FAIL;
}


int main()
{
	// 배열.
	int array[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	// 찾을 수.
	int target = 15;
	// 배열 길이(end 인덱스 구하기 위함.)
	int length = sizeof(array) / sizeof(array[0]);
	// 이진 탐색.(재귀적 검색.)
	//int index = RecursiveBinarySearch(
	//	array, target, 0, length - 1 // 마지막 인덱스는 배열.size() -1이므로.
	//);

	// 이진탐색(반복적)
	int index = InterativeBinarySearch(
		array, target, 0, length - 1
	);

	if (index != FAIL)
	{
		std::cout << "값: " << target
			<< "을 인덱스 " << index << " 에서 찾음\n";
	}
	else
	{
		std::cout << "값: " << target << "을 찾지 못함\n";
	}

	std::cin.get();
}