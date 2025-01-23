#include <iostream>

/**
* �α׿� ����� �ý��ۿ��� ������ ������ �����ϱ� ���� ����ü
* payload �����ʹ� ���� ��뷮�� ���� �����Ǵ� ������
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
		//�������� info.payload ������ ���� �� ũ�� ��ȯ
		return info.payloadSize;
	}
};


int sendUserInfoToServer(USER_INFO &info)
{
	//MySocket sock("192.168.10.100"); // << Review: ���ʿ��� �ּ� ó���Դϴ�.
	MySocket sock("192.168.10.200");
	if (sock.connect()) {
		return sock.send(info);
	}
	return 0;
}



/*�ּ� ����*/
void loadUserInfo(void) {
	std::string strMessage; // << Review: ������� �ʴ� �����Դϴ�. �޸� ���� ���� ������.

	//���� ���α� ����
	if (!getGameLog()) { // << Review: getGameLog() �Լ��� bool ���� ��ȯ�Ѵٴ� ����� ��Ȯ���� �ʽ��ϴ�. ���� �̸��� ����� ���� �ּ���.
		logForUserLogin("ERROR: Failed to get game log.");
		return;
	}

	//����� ������ ������� �α��� payload ������ ����
	USER_INFO userInfo = { 0 };
	//buildLoginPayload(userInfo); // << Review: ���ʿ��� �ּ� ó���� �� ���Գ׿�.
	buildLoginPayload(userInfo);
	if (userInfo.payloadSize > 0) {
		//����� ������ ������ ����
		sendUserInfoToServer(userInfo);
	}
	else {
		logForUserLogin("ERROR: Failed to build user info");
	}

	logForUserLogin("Login process complete."); // << Review: �� ��ġ�� �� �̷� �α׸� �־���? ����� ������ ������ �����ϴ� ��ġ�� �Ű� �ּ���.
}

