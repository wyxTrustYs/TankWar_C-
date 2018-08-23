#pragma once
#include <windows.h>
class CMap
{
public:
	void InitMap();													//��ʼ��Χǽ
	void InitHome();												//��ʼ���ϼ�
	void ShowCursor(bool isShow);									//�رչ��
	void FullScreen();												//����̨ȫ��
	void PrintChar(int Wide, int High, char *Str, int color = 7);	//��ͼ����
	void MapDIY();													//�Զ����ͼ
	void MouseEventProc(MOUSE_EVENT_RECORD mer, int MapType);		//��껭ͼ�¼��������ͼ�Ҽ�ɾ����
	void OutputPos(int nX, int nY, int flat);						//�����ArrMap�����λ��
	void MapToFile(char name[]);									//��ͼд���ļ�
	void FileToMap(char name[]);									//���ļ��ж�ȡ��ͼ
	void NewMap();													//�½���ͼ
	void LoadMap();													//���ص�ͼ
	void EditMap();													//�༭���е�ͼ
	void ClsMap(int x, int y, int PreType);							//������ͼ�е���Ʒ

	void setMapValue(int x, int y, int value);						//���õ�ͼ�����е�ֵ
	int getMapValue(int x, int y);									//��ȡ��ͼ�����е�ֵ
private:
	static int ArrMap[30][60];
};