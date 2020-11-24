#include <stdio.h>

void swap_by_value(char a, char b) {
	int temp = a;
	a = b;
	b = temp;
    printf("parameter sizeof: %d\n", sizeof(a)); // 값 복사한 변수 크기
}

void swap_by_address(char* a, char* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
    printf("parameter sizeof: %d\n", sizeof(a)); // 포인터 변수 크기
}

void swap_by_reference(char &a, char &b) {
	int temp = a;
	a = b;
	b = temp;
    printf("parameter sizeof: %d\n", sizeof(a)); // 원본 변수 크기
}	

int main() {
	char a, b;
    
    printf("===== call by value =====\n");
    // 일반 변수에 변수 값 복사
    // - 장점 : 복사로 처리하기에 원본 값 보존
    // - 단점 : 복사하기에 메모리 사용량
    a='a', b='b';
	swap_by_value(a, b);
	printf("after: %c, %c\n\n", a, b);

    printf("===== call by address =====\n");
    // 포인터 변수에 원본 주소 복사
	// - 장점 : 없다?
    // - 단점 : 1. 포인터 변수에 주소 값 복사하여 사용하기에 메모리 사용량
    //        2. 원본 값 변형 리스크
    a='a', b='b';
	swap_by_address(&a, &b);
	printf("after: %c, %c\n\n", a, b);

    printf("===== call by reference =====\n");
    // 레퍼런스 변수로 원본의 별명 만들어 직접 참조
    // - 장점 : 복사 하지 않고 값을 직접 참조하여 빠름
    // - 단점 : 원본 값 변형 리스크
    a='a', b='b';
	swap_by_reference(a, b);
	printf("after: %c, %c\n\n", a, b);

    return 0;
}