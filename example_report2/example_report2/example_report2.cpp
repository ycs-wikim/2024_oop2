// example_report2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/// 헤더 파일 추가시 <, >로 묶으면 라이브러리 폴더에서 찾는다.
#include <iostream>
/// 헤더 파일 추가시 ", "로 묶으면 현재 폴더에서 찾는다.
#include "add.h"
#include "sub.h"
#include "multi.h"
#include "dive.h"
#include "mod.h"

int main()
{
    printf("add() : %d\n", add(15, 56));
    printf("sub() : %d\n", sub(115, 56));
    printf("multi() : %d\n", multi(115, 56));
    printf("dive() : %d\n", dive(115, 56));
    printf("mod() : %d\n", mod(115, 56));
}
