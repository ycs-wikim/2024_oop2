// 0502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 함수의 호출 방식
/// 1. call by value : 인수 값이 복사되어 별도 변수에 보관
/// 2. call by address : 인수 값이 포인터인 경우
/// 3. call by reference : 인수 값이 참조 변수인 경우

/// ( int a = x, int b = y )
int call_by_value(int a, int b)
{
    int ret = a + b;
    a = 777;    // 복사본의 값을 수정해도 원본에 영향이 X
    b = 888;
    return ret;
}

// ( int* p1 = &x, int* p2 = &y )
int call_by_address(int* p1, int* p2)
{
    int ret = *p1 + *p2;
    *p1 = 7;
    *p2 = 8;
    return ret;
}

// ( int& a = x, int& b = y )
int call_by_reference(int& a, int& b)
{
    int ret = a + b;
    a = 7777;
    b = 8888;
    return ret;
}

int const_func(const int* p1, const int* p2)
{
    int ret = *p1 + *p2;
    int* ptr1 = (int*)p1;
    int* ptr2 = (int*)p2;
    *ptr1 = 111;
    *ptr2 = 222;
    return ret;
}



int main()
{
    int x = 77, y = 88;

    printf("x[ %d ] y[ %d ]\n", x, y);
    printf("call by value : %d\n", call_by_value(x, y));
    printf("x[ %d ] y[ %d ]\n", x, y);
    printf("call by address : %d\n", call_by_address(&x, &y));
    printf("x[ %d ] y[ %d ]\n", x, y);
    printf("call by reference : %d\n", call_by_reference(x, y));
    printf("x[ %d ] y[ %d ]\n", x, y);
    printf("call by const : %d\n", const_func(&x, &y));
    printf("x[ %d ] y[ %d ]\n", x, y);
}


#ifdef EX_2
/// 함수 : 기능을 사용자 정의로 만든 것.
/// 함수 작성 법
/// [1] 함수의 반환 자료형 : 함수 종료시에 알려주는 자료형
/// [2] 함수의 이름 : 중복되지 않는, 의미를 갖는 이름
/// [3] 함수의 인수 : 기능 처리를 위해 필요한 부가 정보
/// [4] 함수의 기능 : 어떠한 처리를 수행하는가
/// [5] 함수의 반환 값 : 함수 종료시 알려주는 값
/// 작성 예)
/// [1] [2]( [3] )
/// {
///     [4]
///     ......
///     [5]
/// }
/// 
/// 실제 예 : 두 int 값을 정보로 주면, 더해서 int로 반환하는 기능
/// [1] int
/// [2] Add
/// [3] int su1, int su2
/// [4] su1 + su2
/// [5] return su1 + su2; or return ret;

// 함수의 원형(프로토타입)
//  - 컴파일러에게 이러한 함수가 있으니 참고하라.
// 함수의 몸체( {, } ) 전의 내용을 가져와서 ) 뒤에 ; 붙여서 사용
//int Add(int su1, int su2);
// 원형을 작성할때는 변수 이름이 없어도 문제 없다.
int Add(int, int);

int main()
{
    if (0)
        return -12;
    Add(3, 8);      // 결과 값을 받지 않아도 문제 없음
    printf("%d\n", Add(33, 88));
    return 0;
}
/*
int Add(int su1, int su2)
{
    /// 여러 개 반환이 가능하지만, 마지막 1개만 반환
    return su1 + su2, 89, 90, 3;

    /// return의 의미 : 함수의 동작을 더이상 수행하고 말고 종료
    /// ==> 스택에서 해당 함수의 스택 프레임을 제거
}
*/
#endif


#ifdef EX_
typedef struct asdf
{
    int x;
    int y;
    int z;
} ASDF, * PASDF;

int main()
{
    ASDF a = { 33, 44, 55 };
    PASDF p = &a;           // 구조체 포인터
    void* vp = p;           // void 포인터
    int* ip = (int*)vp;     // int형 포인터
    printf("%d %d %d\n", ip[0], ip[1], ip[2]);

    std::cout << "Hello World!\n";
}
#endif