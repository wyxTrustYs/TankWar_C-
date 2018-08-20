#pragma once
#include "CBase.h"
#include "CMapObject.h"


/*  
	̹����������
	����������
	̹�˵�λ��
	̹�˵�Ѫ��
	̹�˵ķ���
	̹�˵ķ���
	̹�˵���Ӫ
	̹���Ƿ�����
	����������
	��ȡ̹�˵�λ��

*/

class CTankObject:virtual public CBaseObject
{
public:
	CTankObject();
	~CTankObject();
	//��̹��
	bool DrawObject();
	//��̹��
	bool ClsObject();

	//�������ͻ�ȡ̹�˵ĳ����أ����ض�Ӧ��̹�ˣ�����������
	CTankObject getTankBirthPlace(int nType);
	//�ƶ�̹��
	bool MoveTank(int Dir);
	//̹����ײ
	bool TankCollision(CTankObject TankObject);
	//���õ�ͼ���󣨴�����ÿһ��̹�˶����ж���¼��ͼ�ĵ�ַ��
	void setMapObject(CMapObject* pMapObject);
	//���ص�ͼ����
	CMapObject *getMapObj();
	//����̹����״
	void setTankShape();
	bool getTankIsDead();
	int getAlignment();
	int getTankPosX();
	int getTankPosY();
	int getTankDir();
	int getTankType();
	int getTankBlood();
	int getTankScores();
	int getPreType();

private:
	int IsDead;		//̹���Ƿ�����
	int Alignment;	//������Ӫ
	int PosX;		//̹��X����
	int PosY;		//̹��Y����
	int Dir;		//̹�˵�ǰ����
	int Type ;		//̹������
	int Blood;		//̹��Ѫ��
	int Score;		//̹��ɱ�з���
	int PreType;		//̹��֮ǰ�߹��ĵ���
	CMapObject* pMapObject;
	const int TankShape[4][3][3] = {
		{
			{ 0,1,0 },
			{ 1,1,1 },
			{ 1,0,1 },
		},
		{
			{ 1,0,1 },
			{ 1,1,1 },
			{ 0,1,0 },
		},
		{
			{ 0,1,1 },
			{ 1,1,0 },
			{ 0,1,1 },
		},
		{
			{ 1,1,0 },
			{ 0,1,1 },
			{ 1,1,0 },
		},
	};
};

