// 0613.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

#include <stack>


class CN1
{
public:
    int m_x;
private:
    int m_m;
};


class CN2 : public CN1
{
public:
    int m_y;
};



/*
class ASDF
{
public:
    int x;
    int y;
    ~ASDF()
    {
        printf("%s Called\n", __FUNCTION__);
    }
};


stack<ASDF*> g_stk;

void main()
{
    ASDF* ptr = nullptr;
    ptr = new ASDF;
    ptr->x = 1;
    g_stk.push(ptr);

    ptr = new ASDF;
    ptr->x = 2;
    g_stk.push(ptr);

    ptr = new ASDF;
    ptr->x = 3;
    g_stk.push(ptr);

    ptr = new ASDF;
    ptr->x = 4;
    g_stk.push(ptr);

    for (int i = 0; i < g_stk.size() + 1; i++)
    {
        printf("%d\n", g_stk.top()->x);
        g_stk.pop();
    }
    printf("%d\n", g_stk.top()->x);
    g_stk.pop();
}
*/

#ifdef _EX
const char* g_board[3][3] = {
    {"비김", "P2", "P1"},
    {"P1", "비김", "P2"},
    {"P2", "P1", "비김"}
};

void main()
{
    int p1, p2;

    p1 = 1;
    p2 = 0;
    printf("%s\n", g_board[p1][p2]);
}
#endif


#ifdef __EX
class CTest
{
public:
    int m_value = 10;
public:
    /// 연산자 재정의 (함수 중복 선언 가능)
    /// CTest 클래스의 인스턴스 뒤의 연산자를 재정의
    /// 앞에오는 연산자는 앞 객체에 따라 달라지기 때문에 정의할 수 없음
    /// a + b 연산의 경우 b의 자료형에 따라 호출 함수가 달라짐
    void operator +(CTest arg)
    {
        m_value = m_value + arg.m_value;
    }
    void operator +(float arg)
    {
        m_value = m_value + arg + arg;
    }
    void operator +(double arg)
    {
        m_value = m_value + arg + arg;
    }
    void operator +(int arg)
    {
        m_value = m_value + arg;
    }

    /// 특별한 연산자를 제외하면 대부분의 연산자 재정의 가능
    void operator -(int arg){}
    void operator /(int arg) {}
    void operator *(int arg) {}
    //void operator .(int arg) {}
    //void operator ->(int arg) {}
    void operator %(int arg) {}
    void operator ^(int arg) {}
    void operator |(int arg) {}
    void operator ||(int arg) {}
    void operator &(int arg) {}
    void operator &&(int arg) {}
    void operator ++(int arg) {}
    void operator --(int arg) {}
    //void operator ::(int arg) {}
    void operator =(int arg) {}

    void PrintValue()
    {
        printf("m_value: %d\n", m_value);
    }
};


int main()
{
    CTest c, k;
    /// 반환 타입이 없어도 연산은 제대로 이루어짐
    c + 1;
    c + 'A';
    c + 8.9;
    /// 객체를 피연산자로 사용 가능
    c + k;
    c + k.m_value;
    c.PrintValue();
    std::cout << "Hello World!\n";
}
#endif
