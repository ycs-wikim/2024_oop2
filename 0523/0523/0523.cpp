// 0523.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 생성자, 소멸자 함수는 반드시!!!!!!! public 권한으로 설정되어야 한다!
/// 
/// 생성자(constructor) : 인스턴스화 될때 자동으로 호출되는 함수
///     함수 선언 방법
///         1. 반환 값을 표기하지 않는다.
///         2. 함수 이름은 클래스 이름으로 고정된다.
/// 
/// 소멸자(destructor) : 인스턴스가 해제/소멸될 때, 자동으로 호출되는 함수
///     함수 선언 방법
///         1. 반환 값을 표기하지 않는다.
///         2. 함수 이름은 클래스 이름으로 고정된다.
///         3. 함수 이름 앞에 ~를 붙인다.
class asdf
{
public:
    asdf()
    {
        printf("생성자 호출\n");
    }
    ~asdf()
    {
        printf("소멸자 호출\n");
    }

};

void main()
{
    asdf a;
}

#ifdef EX__
class CTEST
{
public:
    int m_value;
    static int m_static;
    void Normal()
    {
        m_value++;
    }
    /// const 뒤에는 자료형 또는 변수 ==> 변수 또는 자료형의 상수화
    /// 멤버 함수의 상수화는 const의 위치가 가장 마지막!
    /// const 멤버 함수에서는 멤버 변수의 값을 변경할 수 없다!!!
    void Const() const
    {
        int xy = 99;
        xy += m_value;
        // const 멤버 함수 내부에서 일반 멤버 함수를 호출 불가능!
        // 일반 멤버 함수에서 멤버를 변경할 수 있기 때문.
        //Normal();
        //m_value++;    // 정적 멤버 변수는 변경할 수 없다.
        /// 함수 선언 내부에서는 모든 멤버 변수가 상수로 처리!
        //m_value = 99;
        printf("m_value: %d\n", m_value);
        printf("xy : %d\n", xy);
    }
};

int CTEST::m_static = 99;

void main()
{
    CTEST cc, c1, c2, c3;
    /// 정적 멤버 변수의 주소
    printf("STATIC: %p %p %p %p\n", &cc.m_static, &c1.m_static,
        &c2.m_static, &c3.m_static);
    cc.Normal();
    cc.Const();
    cc.m_value = 100;
    cc.Const();
}
#endif

#ifdef EEX
class Parent
{
public:
    int m_member = 80;
};

class Child : public Parent
{
    /// this : 클래스가 인스턴스화(객체화) 되었을때, 자신을 가리키는 포인터
    ///     클래스 내부의 메서드(멤버 함수)에서만 동작한다.
public:
    /// 상속 받은 부모 클래스와 동일한 멤버 이름을 가진 경우
    /// 1. 이름을 그대로 사용 : 자신의 멤버가 사용
    /// 2. ::(범위 지정 연산자) : 특정 클래스의 멤버를 지정해서 사용
    /// 3. this를 통한 사용 : 자신의 멤버임을 정확하게 알림.
    int m_member = 90;
    void getMember()
    {
        printf("%s[ %p ] : %d %d %d\n", __FUNCTION__, this,
            m_member, this->m_member, Parent::m_member);
        /// this는 별도로 값을 할당할 수 없다! 상수화 되어있음.
        /// 시작 위치를 기억하는 유일한 변수이기 때문. == 배열의 주소
        //this = NULL;
    }
};

class CTest
{
public:
    /// 정적 멤버 변수 : 인스턴스 생성과 관계 없이 메모리에 적재
    ///     CTest의 모든 인스턴스는 내부에서 접근 시 하나만! 보인다.
    ///     모든 정적 멤버 변수는 인스턴스에 하나만 존재한다.
    static int m_value;         // 반드시 외부 정의
    /// 일반 함수에서는 일반 멤버/정적 멤버 모두 사용 가능
    void Normal()
    {
        printf("m_value[ %p ] : %d\n", this, m_value);
    }
    /// 정적 멤버 함수 : 인스터스 생성과 관계 없이 메모리에 적재
    ///     클래스의 인스턴스화 여부와 관계 없이 호출 가능!
    ///     제약 : 내부에서 접근하는 멤버 변수는 반드시 정적 멤버 변수!
    static void Static()
    {
        /// 객체 자신을 가리키는 this라 할지라도 정적 멤버 함수에서는 접근/사용 불가!
        //printf("THIS : %p\n", this);
        printf("m_value : %d\n", m_value);
    }
};

/// 정적 멤버 변수의 외부 선언
int CTest::m_value = 80;


int main()
{
    /// CTest 클래스의 인스턴스가 없는 상태!
    CTest::Static();        /// 직접 호출 가능!
    CTest::m_value = 99;    /// 정적 멤버 변수 접근 가능
    CTest ct;
    ct.Normal();
    printf("\n\n");

    Child a, b, c, d;
    a.getMember();
    b.getMember();
    c.getMember();
    d.getMember();
    //this;     // this는 클래스 외부에서 사용 불가!
    printf("ADDR: %p %p %p %p\n", &a, &b, &c, &d);
    std::cout << "Hello World!\n";
}
#endif
