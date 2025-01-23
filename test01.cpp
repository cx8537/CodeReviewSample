//test

void anotherFunction(int a, int b) {}
/**
* (개요)
* 함수의 기능과 역할을 간결하게 설명.
* 사용 시 주의사항 등 작성
* 
*/
void someFunction(void) {
	//비형식 주석
	//필요 시 다른 함수를 호출하는 이유 기술
	anotherFunction(/*필요시 인수 설명*/ 1, 2);
}

/**
* (개요)
* (요약)
*
* 기본 기능에 대한 설명(상세)
* play(), seek() 호출 전에 반드시 prepare() 함수로 영상을 로드해야 함.
* 그렇지 않을 경우 VideoNotReadyException 발생 
*/
class VideoPlayer
{};
