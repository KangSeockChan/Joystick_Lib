/*********************************************************************
* Date : 2015.09.30
* Name : ���̽�ƽ (��Ƽ��ġ)
* Email : kyechan99@naver.com
* Description : http://blog.naver.com/kyechan99/220492857669
* ���� �ҽ� �Դϴ�. �� ���� �ҽ� �����ϸ� �������ּ���.
***********************************************************************/
#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Joystick : public Layer
{
private:
	Sprite* joystick_limit;		// ���̽�ƽ - ���ѵ� ���� ���� 
	Sprite* joystick_control;	// ���̽�ƽ - ������ ��Ʈ�ѷ� ����
	Sprite* mainChar;			// ���̽�ƽ - ��Ʈ���� ��������Ʈ

private:
	Vec2 controlerPos;			// ���̽�ƽ - ��Ʈ�ѷ��� ��ġ �� ����
	Vec2 centerPos;				// ���̽�ƽ - ��� �������� ��ġ �� ����

private:
	bool isTouch;				// �ùٸ� ��ġ���� ��ġ�Ͽ����� ����
	float m_speed;				// ������ �ӵ�
	bool isLimmitWinSize;		// ������� ������ �ɰ����� ����
	Size winSize;

public:
	Joystick(){};
	~Joystick(){};

	virtual bool init();

	// ���̽�ƽ ��ġ, ���ΰ� ��ġ, ����Ʈ ����
	void update();

	// ���̽�ƽ - ���ΰ� ����
	void setMainChar(Sprite* mainChar);

	// ���̽�ƽ - ���ǵ� ����
	void setSpeed(float speed);

	// ��������Ʈ ȭ�� �̵� ���� �ޱ�
	void setLimitScreen(bool check);

	// ������ ����� �̵��� ���� �Ұ������� ���� ����
	bool checkLimit();

	// ��ġ
	bool onTouchBegan(Touch* touch, Event* unused_event);
	void onTouchMoved(Touch* touch, Event* unused_event);
	void onTouchEnded(Touch* touch, Event* unused_event);

	CREATE_FUNC(Joystick);
};
