// Common.h
// By Zju.Gaps.Aegisys[0GiNr] ÷‹À≥
// 2012-10-11
//

#ifndef __COMMON_H__
#define __COMMON_H__

struct NET_ADDRESS
{
	long ipv4;
	long port;
};

struct TOKEN
{
	long d[4];
};

// client calls
class IClientHandler
{
public:
	virtual int Test(int param) = 0;
	virtual int Connect(const char* userName, const char* password) = 0;
	virtual int EditFinancePassword(const TOKEN* token, const char* username, const char* password, const char* newPassowrd) = 0;
	virtual int EditPassword(const TOKEN* token, const char* userName, const char* password, const char* newPassword) = 0;
	virtual int QueryUserStocks(const TOKEN* token, const char* userName, const char* pszFilter) = 0;
	virtual int QueryStock(const TOKEN* token, int stockCode) = 0;
	virtual int QueryFinance(const TOKEN* token, const char* userName) = 0;
	virtual int Trade(const TOKEN* token, int buyOrSell, const char* userName, int codeStock, int count, double price) = 0;
	virtual int CancelTrade(const TOKEN* token, int tradeCode) = 0;
};


struct STOCK_BASIC
{
	int code;
	int count;
};

struct STOCK_INFO
{
	int code;
	double price;
	double highbuyprice;
	double lowsellprice;
	double openprice;
	struct
	{
		double highprice;
		double lowprice;
	}day, week, month;
	char info[4000];
};

// server calls
class IServerHandler
{
public:
	virtual int ReplyTest(int param) = 0;
	virtual int ReplyConnect(const char* userName, const TOKEN* token) = 0;
	virtual int ReplyEditFinancePassword(const char* userName, int status) = 0;
	virtual int ReplyEditPassword(const char* userName, int status) = 0;
	virtual int ReplyQueryUserStocks(const char* userName, STOCK_BASIC* info, int count) = 0;
	virtual int ReplyQueryStock(const char* userName, int stock, STOCK_INFO* info) = 0;
	virtual int ReplyQueryFinance(const char* userName, double total, double available) = 0;
	virtual int ReplyTrade(int tradeCode, int codeStock, int status);
	virtual int ReplyCancelTrade(int tradeCode, int codeStock, int status);
};



#endif // __COMMON_H__
