#include "Ctest.h"

/*
* 정적(static) 키워드
* C 스타일
*  - 변수 : 한번만 초기화되는 변수
*  - 함수 : 해당 함수가 포함된 소스 파일에서만 접근 가능
* 
* C++ 스타일
*  - 변수/함수 : 인스턴스(객체)화 되기 전에 메모리에 적재됨.
*/

// 일반 멤버 변수는 외부에서 정의가 불가능!
// 일반 멤버 변수/함수는 인스턴스화 이후에 사용이 가능!
//int Ctest::m_public = 9;

void Ctest::Public()
{
	printf("%s called\n", __FUNCTION__);
}

void Ctest::Protected()
{
	printf("%s called\n", __FUNCTION__);
}

void Ctest::Private()
{
	printf("%s called\n", __FUNCTION__);
}