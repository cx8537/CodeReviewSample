#include <iostream>

/**
* @14, @15, @18
* 이건 왜 만든 함수입니까?
*
* @33, @55
* 수정 후 남은 의미 없는 주석 지워주세요.
*
* @45
* 의미없는 string 객체 생성 구문이 있습니다
*
* @62~
* 해당 else문에서 return을 진행하지 않으면 함수가 끝까지 실행되어 논리상 의미가 맞지 않게 됩니다.
* return문 추가해주세요.
*/

/**
* 로그온 사용자 시스템에서 수집한 정보를 저장하기 위한 구조체
* payload 데이터는 게임 사용량에 따라 누적되는 데이터
*/
typedef struct USER_INFO {
	char id[256];
	int payloadSize;
	unsigned char payload[4096];
	int crc;
} USER_INFO;

bool getGameLog() { return true; }
void logForUserLogin(const char*) {}


int buildLoginPayload(USER_INFO&) { return 1; }

class MySocket {
public:
	MySocket(const char* param) {}
	int connect() { return 0; }
	int send(USER_INFO &info) {
		//소켓으로 info.payload 데이터 전송 후 크기 반환
		return info.payloadSize;
	}
};


int sendUserInfoToServer(USER_INFO &info)
{
	//MySocket sock("192.168.10.100");
	MySocket sock("192.168.10.200");
	if (sock.connect()) {
		return sock.send(info);
	}
	return 0;
}



/*주석 생략*/
void loadUserInfo(void) {
	std::string strMessage;

	//게임 사용로그 수집
	if (!getGameLog()) {
		logForUserLogin("ERROR: Failed to get game log.");
		return;
	}

	//사용자 정보를 기반으로 로그인 payload 데이터 생성
	USER_INFO userInfo = { 0 };
	//buildLoginPayload(userInfo);
	buildLoginPayload(userInfo);
	if (userInfo.payloadSize > 0) {
		//사용자 정보를 서버에 전달
		sendUserInfoToServer(userInfo);
	}
	else {
		logForUserLogin("ERROR: Failed to build user info");
	}

	logForUserLogin("Login process complete.");
}

