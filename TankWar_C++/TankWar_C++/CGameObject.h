#pragma once
#include "CMapObject.h"
#include "CTankObject.h"
#include "CBullet.h"
#include <vector>
using namespace std;
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	//��ӭ����
	bool Welcome();
	//��ʼ��̹����Ϣ
	bool InitTankInfo();
	//��ʼ��Ϸ
	bool StartGame();
	//ͨ�������ƶ�̹��
	bool MoveSelfAndALLY();
	//�з�̹���ƶ�
	bool MoveNPC();
private:
	//��ͼ����
	CMapObject MapObject;
	//̹������
	vector<CTankObject> vecTankObject;
	//�ӵ�����
	vector<CBullet> vecBulletObject;
};

