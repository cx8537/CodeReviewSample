#include <iostream>

/**
* 매개변수 keyword에 대한 설명을 문자열로 반환받음
*/

std::string getDescription(std::string& strParam) {
	return "desc";
}


void doA() {}
void doB() {}
void doC() {}
bool checkData() { return true;  }

/**
* flag가 세트되면 doA()를 호출하고 그렇지 않으면 doB()를 호출한 후
* checkData() 함수 반환값이 true면 doC()도 호출한다.
*/

std::string getDescription(std::string& strParam, bool flag) {
	if (flag) {
		doA();
	}
	else {
		doB();
		if (checkData())
			doC();
	}
	return "desc";
}


/**
* (개요)
* 이 함수는 userProfile() 함수에서 사용되고 있음.
*/

std::string getDescription(std::string strParam) {
	return "desc";
}


