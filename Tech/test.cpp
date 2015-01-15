#include <cstdio>
#include <cstring>

class IClient
{
public:
	virtual void Test() = 0;
};

class CEncoder : public IClient
{
public:
	CEncoder(const void* pData = NULL, int nLen = 0)
	{
		if(pData != NULL)
		{
			memcpy(m_buffer, pData, nLen);
		}
	}
	virtual void Execute(IClient* p)
	{
		if(*(int*)m_buffer == 1)
		{
			p->Test();
		}
	}
	virtual void Test()
	{
		*(int*)m_buffer = 1;
	}

	virtual int GetLength() const{ return 4; }
	virtual const void* GetBuffer() const { return m_buffer; }

private:
	char m_buffer[100];
};


class CServer : public IClient
{
public:
	virtual void Process(const void* data, int nLength)
	{
		CEncoder decode(data, nLength);
		decode.Execute(this);
	}
	virtual void Test()
	{
		printf("Hello, world!\n");
	}
};


int main(void)
{
	CEncoder encode;
	encode.Test();
	const void* data = encode.GetBuffer();
	int nLength = encode.GetLength();

	CServer server;
	server.Process(data, nLength);
	
	return 0;	
}
