#ifndef ACCOUNT_H
#define ACCOUNT_H

using std::string;

#define AUTHENTIFICATION_FAIL -1	// 계정 인증 실패
#define AUTHENTIFICATION_SUCCESS 1	// 계정 인증 성공
#define BASE_ACCOUNT_ID 100			// 계좌번호는 100번 부터 1000 사이 랜덤으로 부여

class Account {
private:
	int nID = -1;			// 계좌 번호 (초기 값 = -1)
	int nBalance = 0;		// 잔고 (초기 값 = 0)
	string strAccountName;	// 고객 명
	string strPassword;		// 계좌 비밀번호
private:
	inline bool authenticate(int id, string passwd);	// 인증 성공 : true(1), 인증 실패 : false(0)
public:
	Account();
	void create(int id, int money, string name, string password); // 계좌 개설
	void close();										// return 값 : nBalance (잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
	int check(int id, string password);					// 계좌 해지
	int getAcctID() { return nID; }						// 계좌 번호 읽어오기
	int deposit(int id, string password, int money);	// return 값 : nBalance (최종잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
	int widraw(int id, string password, int money);		// return 값 : nBalance (최종잔고) or 인증 실패(AUTHENTIFICATION_FAIL)

	// 추가 기능
	int deposit(int id, int money);
	int getBalance() { return nBalance; }				// return 값 : nBalance (최종잔고)
	string getAccountName() { return strAccountName; }	// return 값 : strAccountName (고객명)
};

#endif