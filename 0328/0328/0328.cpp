#include <iostream>
using namespace std;

// typedef : 새로운 자료형 선언
// typedef A B; ==> A 자료형을 B로 사용
typedef int INT;
typedef int i;

#define SWAP(a, b) {a ^= b; b ^= a; a ^= b;}

int main()
{
    int ia = 8;
    int ib = 89;
    printf("a, b : %d %d\n", ia, ib);
    if(0)
//        a ^= b; b ^= a; a ^= b;
        SWAP(ia, ib);

    printf("a, b : %d %d\n", ia, ib);

    // sizeof( 변수 혹은 자료형 ) ==> 바이트 크기
    printf("sizeof : %d\n", sizeof(INT));
    
    //int int = 9;          // 불가능!
    INT a;
    i i = 0;
    i = 45657;
    printf("i: %d\n", i);

    // NULL 문자 : C언어 NULL == 0, C++ nullptr
    NULL; nullptr;
    //char t[4] = NULL;         // 불가능
    //char t1[4] = nullptr;     // 불가능

    // 문자열의 초기화
    char str[4] = "C++";
    char str1[4] = "";
    char str2[4] = { 0, };
    char str3[4] = "abc";           // | a | b | c | \0 |
    //char str4[4] = "abcd";          // | a | b | c | d |
    char str5[4] = { 'a', 'b', 'c' };
    const char* ptr = "54fytf46rt";
    char str6[] = "7tujh6tfuuyhr";

    //str = "D++";
    str[0] = 'D';
    str[1] = '-';
    str[2] = '-';

    // wide-char-type 기본 2바이트, 확장 4바이트 크기
    wchar_t wc[8] = L"ghtf6";
    std::string st;
    wstring kkk;
    st = "u76trvufryu";
    st += " htfyfyfyftf";

    cout << str << "      " << wc << endl;
    printf("WC : %ws\n", wc);
    std::cout << "Hello World!\n";

    {
        int kkkk = 9;
        printf("KKK: %d\n", kkkk);
    }
    //kkkk = 6;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
