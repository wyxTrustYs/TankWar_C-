#pragma once

/*
	������������
	�������󣨴��麯����
	��ն��󣨴��麯����
*/

class CBaseObject
{
public:
	CBaseObject();
	~CBaseObject();
	virtual bool DrawObject() = 0;
	virtual bool ClsObject() = 0;
private:
};