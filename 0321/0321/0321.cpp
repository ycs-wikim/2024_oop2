// 전처리기 include : 파일을 그대로 가져와 소스에 붙여준다.
// iostream 파일의 내용이 본 소스에 붙여진다.
#include <iostream>
using namespace std;    // 이름공간 std(standard)

// 전처리기 define : 상수를 정의한다.
// 변수 : r-value, l-value 모두 가능
// 상수 : r-value만 가능
// l-value = r-value
// #define A B  ==> 앞으로 A는 B로 사용
#define PI 3.14

void ps()
{
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __FUNCTION__ << endl;

#ifdef _M_X64
    cout << "64bit\n";
#else
    cout << "32bit\n";
#endif


}


int main()
{
    int x = 3;
    x = 3 + x * x + PI;
    //PI = x;
    //PI = 3;

    ps();
    cout << "H" << "e" << "llo " << x << " World!\n";
}
