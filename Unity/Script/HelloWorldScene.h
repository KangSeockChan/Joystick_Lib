/*********************************************************************
* Date : 2015.09.30
* Name : ���̽�ƽ (��Ƽ��ġ)
* Email : kyechan99@naver.com
* Description : http://blog.naver.com/kyechan99/220492857669
* ���� �ҽ� �Դϴ�. �� ���� �ҽ� �����ϸ� �������ּ���.
***********************************************************************/
#pragma once

#include "Joystick.h"
#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public Layer
{
private:
	Sprite* spr;
	Joystick* joystick;

public:
	static Scene* createScene();

	virtual bool init();

	void Update(float dt);

	void onTouchesBegan(const std::vector<Touch*> &touches, Event* unused_event);
	void onTouchesMoved(const std::vector<Touch*> &touches, Event* unused_event);
	void onTouchesEnded(const std::vector<Touch*> &touches, Event* unused_event);

	CREATE_FUNC(HelloWorld);
};