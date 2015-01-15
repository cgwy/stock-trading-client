// CmdEncoder.h
// By Zju.Gaps.Aegisys[0GiNr] ÷‹À≥
// 2012-10-12
//

#ifndef __CMDENCODER_H__
#define __CMDENCODER_H__

#include "..\Common\Common.h"


#ifndef __CMDENCODER_DLL__
#define CMD_ENCODER __declspec(dllimport)
#else
#define CMD_ENCODER __declspec(dllexport)
#endif // __CMD_ENCODER_DLL__

class ICmdEncoder : public IClientHandler, public IServerHandler
{
public:
	CMD_ENCODER static ICmdEncoder* CreateInstance(void* pData, int nLength);
	CMD_ENCODER static void ReleaseInstance(ICmdEncoder* p);
	
	virtual void ExecuteClient(IClientHandler* pClient);
	virtual void ExecuteServer(IServerHandler* pServer);

	virtual const void* GetBuffer() const = 0;
	virtual int GetLength() const = 0;

};


#endif // __CMDENCODER_H__