#include "Ctest.h"

/*
* ����(static) Ű����
* C ��Ÿ��
*  - ���� : �ѹ��� �ʱ�ȭ�Ǵ� ����
*  - �Լ� : �ش� �Լ��� ���Ե� �ҽ� ���Ͽ����� ���� ����
* 
* C++ ��Ÿ��
*  - ����/�Լ� : �ν��Ͻ�(��ü)ȭ �Ǳ� ���� �޸𸮿� �����.
*/

// �Ϲ� ��� ������ �ܺο��� ���ǰ� �Ұ���!
// �Ϲ� ��� ����/�Լ��� �ν��Ͻ�ȭ ���Ŀ� ����� ����!
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