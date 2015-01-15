// NetTransfer.h
// By Zju.Gaps.Aegisys[0GiNr] ÷‹À≥
// 2012-10-12
//

#ifndef __NETTRANSFER_H__
#define __NETTRANSFER_H__

#include "../Common/Common.h"


#ifndef __NETTRANSFER_DLL__
#define NET_TRANSFER __declspec(dllimport)
#else
#define NET_TRANSFER __declspec(dllexport)
#endif // __CMD_ENCODER_DLL__

class ITokenVerifier
{
public:
	static ITokenVerifier* CreateInstance();
	static void ReleaseInstance(ITokenVerifier* p);

	virtual bool Generate(TOKEN* token, const char* userName, const char* password, NET_ADDRESS* clientAddr, long uuid[4]);
	virtual bool Verify(const TOKEN* p, const TOKEN* q);
};


class INetTransfer
{
public:
	static INetTransfer* CreateInstance();
	static void ReleaseInstance(INetTransfer* p);

	virtual int Send(const USER_ADDRESS* addr, void* pData, int nLength, const TOKEN* token) = 0;
	virtual int Listen(USER_ADDRESS* addr, void* pData, int* pnLength, TOKEN* token) = 0;
};


#endif // __NETTRANSFER_H__