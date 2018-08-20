#pragma once

/*
	对象类里面有
	画出对象（纯虚函数）
	清空对象（纯虚函数）
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