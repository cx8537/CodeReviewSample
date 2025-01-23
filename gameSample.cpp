#include <iostream>

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
	//MySocket sock("192.168.10.100"); // << Review: 불필요한 주석 처리입니다.
	MySocket sock("192.168.10.200");
	if (sock.connect()) {
		return sock.send(info);
	}
	return 0;
}



/*주석 생략*/
void loadUserInfo(void) {
	std::string strMessage; // << Review: 사용하지 않는 변수입니다. 메모리 낭비 하지 마세요.

	//게임 사용로그 수집
	if (!getGameLog()) { // << Review: getGameLog() 함수가 bool 값을 반환한다는 사실이 명확하지 않습니다. 제발 이름을 제대로 지어 주세요.
		logForUserLogin("ERROR: Failed to get game log.");
		return;
	}

	//사용자 정보를 기반으로 로그인 payload 데이터 생성
	USER_INFO userInfo = { 0 };
	//buildLoginPayload(userInfo); // << Review: 불필요한 주석 처리가 또 나왔네요.
	buildLoginPayload(userInfo);
	if (userInfo.payloadSize > 0) {
		//사용자 정보를 서버에 전달
		sendUserInfoToServer(userInfo);
	}
	else {
		logForUserLogin("ERROR: Failed to build user info");
	}

	logForUserLogin("Login process complete."); // << Review: 이 위치에 왜 이런 로그를 넣었죠? 사용자 정보를 서버에 전달하는 위치로 옮겨 주세요.
}

