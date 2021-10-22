#include <iostream>
// array library include
#include <array>

using namespace std;

void print(array<int, 5> arr);

int main(int argc, char* argv[]) {
	
	/*
	* 01. array 사용 기본 형태
	*/
	array<int, 4> arr1;

	arr1[0] = 1;
	cout << "arr1 배열의 첫 번째 원소: " << arr1[0] << endl;

	array<int, 4> arr2 = { 1, 2, 3, 4 };
	cout << "arr2의 모든 원소: ";

	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	/*
	* 02. at(index) 형식의 함수 사용
	* 
	* at(index) 형식의 함수는 인자로 전달된 index 값이 유효하지 않으면
	* out_of_range 예외(exception)을 발생시킨다.
	* 그러므로 at() 함수가 [] 연산자보다 조금 느린 편이지만,
	* at() 함수를 잘 이용하면 예외를 적절하게 처리할 수 있다.
	*/
	array<int, 4> arr3 = { 1, 2, 3, 4 };
	try {
		cout << arr3.at(3) << endl;
		cout << arr3.at(4) << endl;
	}
	catch (const out_of_range& ex) {
		cerr << ex.what() << endl;
	}

	/*
	* 03-2. 생성한 print 함수 출력
	*/
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	print(arr);

	/*
	* 05. array 객체의 begin(), end() 라는 멤버 함수 사용하기
	* begin() 함수 : 가장 첫 번째 원소의 위치 반환
	* end() 함수 : 가장 마지막 원소의 위치 반환 (정확하게는 마지막 원소 바로 다음 위치)
	* 특정 원소 위치에서 다음 원소 위치로 이동하려면,
	* 반복자에 증가연산자(++) 또는 덧셈 연산자(+) 같은 산술 연산을 수행할 수 있다.
	*/
	for (auto it = arr.begin(); it != arr.end(); it++) {
		auto element = (*it);
		cout << element << ' ';
	}
	cout << endl;

	/*
	* 06. array 객체의 원소 접근 함수
	* front() : 배열의 첫 번째 원소에 대한 참조를 반환합니다.
	* back() :	배열의 마지막 원소에 대한 참조를 반환합니다.
	* data() :	배열 객체 내부에서 실제 데이터 메모리 버퍼를 가리키는 포인터를 반환합니다.
	*			반환된 포인터를 이용하여 다양한 포인터 연산을 수행할 수 있습니다.
	*			이 기능은 포인터를 함수의 인자로 받는 예전 스타일의 함수를 사용할 때 유용합니다.
	*/
	cout << "arr.front() : " << arr.front() << endl;		// 1 출력
	cout << "arr.back() : " << arr.back() << endl;			// 5 출력
	cout << "*(arr.data() + 1) : " << *(arr.data() + 1) << endl;	// 2 출력
	cout << "*(arr.data() + 2) : " << *(arr.data() + 2) << endl;	// 3 출력
 
	return 0;
}

/*
* 03-1. array 객체를 다른 함수에 전달하는 방식
* 그냥 기본 데이터 타입을 전달하는 것과 유사하다.
*/
void print(array<int, 5> arr) {
	for (auto ele : arr) {
		cout << ele << ", ";
	}
	cout << endl;
}

/*
* 04. array 객체를 함수 템플릿으로 선언하기
* java 에서 generic 이랑 비슷하다.
*/
template <size_t N>
void print(array<int, N> arr) {
	for (auto ele : arr) {
		cout << ele << ", ";
	}
	cout << endl;
}