// 0418.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// typedef A B : A는 B로 사용한다.
/// 구조체 선언 팁.
typedef
/// A start
struct human_information_for_useing_etc
{
    /// 사람의 이름을 나타내는 32글자
    char name[32];
    // 사람의 키 10~300
    int tall;
    // 왼쪽 시력 값
    float left_eye;
    // 오른쪽 시력 값
    float right_eye;
}
/// A end
HUMAN_INFO, *PHUMAN_INFO
/// B
;


int main()
{
    HUMAN_INFO hi;
    HUMAN_INFO* phi = &hi;
    PHUMAN_INFO pi = &hi;
    pi->left_eye;
    

    /// 구조체 : 서로 다른 자료형을 한꺼번에 여러 개 선언하여 사용하는 자료형
    /// 선언 : 예약어 구조체대표이름 { 변수1; 변수2; 변수3; ... };
    ///        struct human { char name[ 32 ]; int tall; ... };
    /// 변수 선언 : 예약어 구조체대표이름 사용할변수이름;
    ///        struct human h1;     ==> C언어 스타일
    ///        human h2;            ==> C++ 언어 스타일
    /// 변수 사용 : 구조체변수이름.멤버변수;
    ///        h1.tall
    /// 연산자  1. . : 접근자, 직접 멤버 연산자 (일반 구조체 변수)
    ///         2. -> : 간접 멤버 연산자 (구조체형 포인터)
    /// 
    struct asdf
    {
        int x;
        int y;
        int z;
    };
    struct asdf a;
    asdf b;
    a.x = 7;
    a.y = 9;
    a.z = 189;
    printf("x[ %d ] y[ %d ] z[ %d ]\n", a.x, a.y, a.z);


#ifdef EX_1
    /// 배열 : 동일한 자료형을 한꺼번에 여러 개 선언하여 사용하는 자료형
    /// 선언 : 자료형 배열이름[ 원소 개수(상수) -> N ];
    ///     배열이름은 상수! 입니다.
    ///     int a[ 3 ];
    ///     ==> 자료형은 int 형이다. 이동은 4바이트 단위
    ///     ==> 첨자의 범위는 0 ~ 2(N-1)
    ///     ==> a[1] == *a + 1 -> a의 0번째 값 + 1
    ///     ==> a[1] == *(a + 1) -> 포인터 이동후 값을 반환
    /// 
    /// 원소 개수는 N개 사용하는 인덱스 값의 범위는 0 ~ N-1
    /// 인덱스 값이 0부터 시작하는 이유는 배열이 포인터! 이기 때문
    int a[3];   // 사용 가능한 값 a[0], a[1], a[2]
    int b[3] = { 1, 2, 3 };
    int* p = b;     // * == *
    //b = p;          // 배열변수는 상수이므로 대입이 불가능!!
    *(p + 0) = 788;     // 포인터 연산
    p[1] = 999;         // 포인터를 이용한 배열 연산
    b[2] = 123;         // 배열 연산
    *(b + 1) = 988;     // 배열을 이용한 포인터 연산
    printf("%d %d %d\n", b[0], b[1], b[2]);

    int a1[2] = { 1, 2 };
    //int a2[2] = a1;   // 배열 초기화는 값을 요구하는데, a1은 주소
    std::cout << "Hello World!\n";
#endif
}
