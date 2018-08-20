#pragma once
#include "CBase.h"
#include "CTankObject.h"
#include <vector>
using namespace std;
class CBullet:virtual public CBaseObject
{
public:
	CBullet();
	~CBullet();

	bool DrawObject(); //���ӵ�
	bool DrawObject(int PosX, int PosY, int nType);
	bool ClsObject();//���ӵ�
	bool ClsObject(int PosX, int PosY, int nType);
	//�����ӵ������뱣��̹�˵���������Ҫ�����ӵ���̹�˵���ײ��
	CBullet CreatBullet(CTankObject TankObject, //���ӵ���̹��
		vector<CTankObject>& vecTankObject);

	//�ƶ��ӵ�
	bool MoveBullet(vector<CTankObject>& vecTankObject);

	//�ӵ���ײ���
	bool BulletCollision(CBaseObject& BulletObject, //�ӵ�����
		vector<CTankObject>& vecTankObject);

	//����=����(�����ӵ�ʱ��̹�˶�����ӵ�����ֵ)
	bool operator=(CTankObject TankObject);
	//����==��������ӵ���̹����ײ���ӵ�������̹�˶�������ıȽϣ�
	bool operator==(CTankObject TankObject);
	//��ȡ�ӵ�����
	bool getBulletIsDead();
	int getBulletPosX();
	int getBulletPosY();
	int getBulletDir();
	int getBulletType();
	int getBulletATK();

private:
	bool IsDead;	//�ӵ��Ƿ���
	int Alignment;	//������Ӫ
	int PosX;		//�ӵ���X����
	int PosY;		//�ӵ���Y����
	int Dir;		//�ӵ��ķ���
	int Type;		//�ӵ�������
	int ATK;		//�ӵ�������

	CMapObject* pMapObject;
};