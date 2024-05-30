// 0530.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 생성자와 소멸자로 확인한 메모리의 생성/소멸 순서
/// 생성 순서 : 상속된 클래스가 먼저 생성, 상속 받은 클래스가 나중에 생성
///     ==> 상위 클래스의 정보를 사용하기 위해서!
/// 소멸 순서 : 상속 받은 클래스가 먼저 소멸, 상속된 클래스가 나중에 소멸
///     ==> 인스턴스의 생성 위치가 변경될 수 있고, 잘못 해제할 경우 메모리 오류!
/// 생성 순서와 소멸 순서는 정확하게 역순이다!

class Parent
{
public:
    int m_parent;
    Parent()
    {
        printf("Parent 생성자\n");
    }
    ~Parent()
    {
        printf("Parent 소멸자\n");
    }
};

class Child : public Parent
{
public:
    int m_child;
    const int m_attack;
    ~Child()
    {
        printf("Child 소멸자\n");
    }
    /// 후처리 영역 : 소멸자 함수의 종료 위치인 } 이후가 후처리 영역

    /// 복사 생성자
    Child(const Child& obj) : m_attack(obj.m_attack - 30)
    {
        this->m_child = obj.m_child;
        //this->m_attack = obj.m_attack - 30;
        this->m_parent = obj.m_parent * 10;
    }


    Child(int attack)
        /// 선처리 영역에 인수로 받은 값을 이용하여 상수를 초기화 가능!
        : m_attack(attack)
    {

    }

    Child()
    /// 선처리 영역 : 생성자 함수의 인수 받는 ) 뒤부터 함수 몸체가 시작되는
    ///     { 사이에 위치한 영역. 초기화가 필요한 값을 설정할 수 있다.
    /// 선처리 영역에서는 변수 값 입력 및 부모 클래스 생성자 호출
    /// 선처리 영역에 변수 값을 입력하는 방법
        : m_attack(8), Parent()
    {
        printf("Child 생성자\n");
    }
};


int main()
{
    
    int i = 10;
    int j(i);       /// 자료형 변수명(인수); == 클래스명 변수명(인수);
    printf("I/J : %p %p\n", &i, &j);
    Child a;        /// 기본 생성자 호출로 인스턴스 생성
    Child b(a);     /// 동일한 인스턴스를 이용해서 인스턴스 생성
                    /// 복사 생성자를 이용한 인스턴스 생성 방법
    printf("M[ %p ] : %p %p\n", &a, &a.m_parent, &a.m_child);
    /// 소멸자는 외부에서 강제로 호출할 수 있다!
    /// 실제로 소멸자 함수가 호출되기만! 했을 뿐, 객체가 소멸된 것은 아니다!
    /// 호출이 가능할 뿐, 프로그램 작성 시에는 절대 사용하지 말것!
    a.~Child();
    /// 생성자는 외부에서 강제로 호출할 수 없다!
    //a.Child();
    std::cout << "Hello World!\n";
}
