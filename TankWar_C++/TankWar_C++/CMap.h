#pragma once
#include <windows.h>
class CMap
{
public:
	void InitMap();													//初始化围墙
	void InitHome();												//初始化老家
	void ShowCursor(bool isShow);									//关闭光标
	void FullScreen();												//控制台全屏
	void PrintChar(int Wide, int High, char *Str, int color = 7);	//画图函数
	void MapDIY();													//自定义地图
	void MouseEventProc(MOUSE_EVENT_RECORD mer, int MapType);		//鼠标画图事件（左键画图右键删除）
	void OutputPos(int nX, int nY, int flat);						//输出到ArrMap数组的位置
	void MapToFile(char name[]);									//地图写入文件
	void FileToMap(char name[]);									//从文件中读取地图
	void NewMap();													//新建地图
	void LoadMap();													//加载地图
	void EditMap();													//编辑现有地图
	void ClsMap(int x, int y, int PreType);							//擦除地图中的物品

	void setMapValue(int x, int y, int value);						//设置地图数组中的值
	int getMapValue(int x, int y);									//获取地图数组中的值
private:
	static int ArrMap[30][60];
};