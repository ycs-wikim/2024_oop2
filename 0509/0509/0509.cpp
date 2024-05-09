// 0509.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/// 함수 (이름)중복 : C++
///  : 동일한 이름을 갖는 여러 개의 함수를 만들어서 사용
///  : 동일 이름을 사용할 수 있는 이유는 자료형
///  : 매개 변수의 자료형과 인수의 개수에 따라 중복 선언 가능!

/// int_sum(), sum_int(), char_sum(), sum_char()

int sum(int x, int y)
{
    printf("int, int called\n");
    return x + y;
}

int sum(int x)
{
    printf("int called\n");
    return x + 10;
}

/*
/// 자료형이 동일하면 중복 선언이 불가능
//int sum(int ka, int kb)
/// 반환 값이 중복 선언에 영향을 주지 않는다.
//char sum(int ka, int kb)
{
    return ka + kb;
}
*/

char sum(char x, char y)
{
    printf("char char called\n");
    return x + y;
}

char sum(char x, int y)
{
    printf("char, int called\n");
    return x + y;
}

short sum(short x, short y)
{
    printf("short *2 called\n");
    return x + y;
}

void main()
{
    printf("%d\n", sum((short)3, (short)5));
    printf("%d\n", sum('3', '5'));
    printf("%d\n", sum('A', 5));
    
}

#ifdef __EXE
/// 가변인수 사용을 위해 포함해야 하는 헤더 파일
#include <stdarg.h>

/// 가변인수 적용 함수의 선언은 마지막에 ... 입력
void VFFunc(int arg1, int arg2, ...)
{
    /// 가변인수를 접근하기 위한 자료형
    va_list arg_ptr;
    /// 가변인수 접근 시작
    va_start(arg_ptr, arg2);
    /// va_arg( ) 현재 위치의 가변인수 값을 가져온다.
    double varg3 = va_arg(arg_ptr, double);
    char varg4 = va_arg(arg_ptr, char);
    char* varg5 = va_arg(arg_ptr, char*);

    /// 가변인수 접근 종료
    va_end(arg_ptr);

    cout << arg1 << endl;
    cout << arg2 << endl;
    cout << varg3 << endl;
    cout << varg4 << endl;
    cout << varg5 << endl;
}

void main()
{
    VFFunc(3, 4, 3.5);
    VFFunc(1, 2, 3.0, '4', "Five");
}
#endif

#ifdef EX__
/// 기본인자 : 함수 인수의 값을 지정하지 않으면 자동 입력되는 인자
///     ==> 함수 선언부에 자동으로 입력할 값을 대입식으로 표현
///     ==> 인자 값을 주지 않는 경우, 자동으로 대입된다.
///     ==> 인자 값을 잘 모르는 경우 사용하는 것이 좋다.
///     ==> 기본 인자에 특정 인자에만 값을 줄 수 없다.
///     ==> 기본 인자가 시작되면 뒤로는 모두 기본 인자여야 한다.
///     ==> 기본 인자는 인수의 마지막에 써야 한다.
///     ==> 함수 원형에만 기본 인수를 표시하고, 구현 위치에서는 인자 표시를 제거

/// 기본 인자가 적용된 함수의 원형
int add1(int x, int y = 80);

/// 함수 호출 방법
/// 1. add1( 70, 80 )
/// 2. add1( 70 )
int add1(int x, int y)
{
    return x + y;
}

/// 1. add2( 1, 2, 3 )
/// 2. add2( 1, 2 )
int add2(int x, int y, int z = 10)
{
    return x + y + z;
}

/// 1. add3( 1, 2, 3 )
/// 2. add3( 1, 2 )
/// 3. add3( 1 )
int add3(int x, int y = 100, int z = 10)
{
    return x + y + z;
}

int add4(int x = 1, int y = 2, int z = 3)
{
    return x + y + z;
}


int main()
{
    printf("add1 : %d %d\n", add1(30, 50), add1(56));
    printf("add2 : %d %d\n", add2(30, 50, 5), add2(56, 44));
    printf("add3 : %d %d %d\n", add3(30, 50, 5), add3(56, 44), add3(1));
    printf("add4 : %d %d\n", add4(1, 1), add4());
    std::cout << "Hello World!\n";
}
#endif