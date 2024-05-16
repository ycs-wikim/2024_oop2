// 0516.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;



/// 클래스 선언 : 예약어 클래스이름{ 멤버 변수; ... 멤버 함수; ... };
class CFamily       /// C++에서 클래스 == 구조체
{
    int m_x;    /// C++에서 권한 설정이 없으면 private
/// 권한 : 클래스 선언 내부에서 유효
/// 1. public : 누구나 사용 가능
/// 2. protected : 상속 관계가 있는 경우 사용 가능
/// 3. private : 내 클래스에서만! 사용 가능
protected:
    char* m_FamilyName;     /// 멤버 변수 : 정보, 자료 구조

public:
    int m_public = 9;
    /// 멤버 함수 : 메서드, 알고리즘
    void SetFamilyName(char* arg)
    {
        m_FamilyName = arg;
        //m_FamilyName[0] = 'A'; 
    }
};

const char* m_Name;

/// CFamily 클래스를 CName 클래스가 상속 받음
/// 상속 시에 적용되는 권한은 전체 권한에 그대로 붙여진다.
/// 붙여질 때, 더 강력한 권한은 살아남는다.
class CName : public CFamily
{
private:
    const char* m_Name;

public:
    /// 멤버 함수(메서드)의 원형
    void SetName(const char* arg);
    /// 멤버 함수의 (클래스)내부 구현
    void ShowName()
    {
        //cout << " " << m_public << endl;
        cout << m_FamilyName << " " << m_Name << endl;
    }
};

void SetName(const char* arg)
{
    printf("%s called\n", __FUNCTION__);
}

/// CName 클래스의 멤버 함수 외부 구현
/// 함수의반환형 클래스이름::멤버함수이름(인수)
/// 멤버가 변수라면 값을 입력, 함수라면 구현!
void CName::SetName(const char* arg)
//void CName::SetName(const char* arg)
{
    m_Name = arg;
    //m_Name[0] = 'A';
}

#include "Ctest.h"

int main()
{
    Ctest test;
    test.Public();

    SetName("asfdsadf");
    CName name;     // 인스턴스 == 객체
                // 인스턴스 기준 => public 멤버만 보임
    name.SetFamilyName((char*)"Hong");      // 1
    name.SetName("Gil Dong");               // 2
    name.ShowName();
    std::cout << "Hello World!\n";
}
