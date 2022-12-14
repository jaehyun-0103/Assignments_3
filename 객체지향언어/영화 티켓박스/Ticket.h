#ifndef TICKET_H
#define TICKET_H
#include "Screen.h"
#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow; // 좌석 행
	int nCol; // 좌석 열
	char charCheck; // 예약 여부
	int nReservedID; // 예약 번호
	int nPayAmount; // 결제 금액
	int nPayMethod; // 결제 수단
public:
	Ticket() {}
	void setCheck(char check) { charCheck = check; }
	char getCheck() { return charCheck; }

	// 추가 기능 1
	void setSeat(int row, int col) { nRow = row; nCol = col; }	// 좌석 번호 저장
	void setReservedID(int reserved) { nReservedID = reserved; }// 좌석 예약 번호 저장

	// 추가 기능 2
	int getReservedID() { return nReservedID; }					// 좌석 예약 번호 읽기

	// 추가 기능 3
	void setPayAmount(int amount) { nPayAmount = amount; }
	int getPayAmount() { return nPayAmount; }
	void setPayMethod(int method) { nPayMethod = method; }
};
#endif