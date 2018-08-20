#pragma once
#include <wtypes.h>

class CDrawObject
{
public:
	CDrawObject();
	~CDrawObject();

	bool DrawPatterning(int PosX, int PosY, int Type);
private:
	void WriteChar(int Wide, int High, char* pszChar, WORD wArr);
};

