/*********************************************************************
* Date : 2015.09.30
* Name : ���̽�ƽ (��Ƽ��ġ)
* Email : kyechan99@naver.com
* Description : http://blog.naver.com/kyechan99/220492857669
* ���� �ҽ� �Դϴ�. �� ���� �ҽ� �����ϸ� �������ּ���.
***********************************************************************/
#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	spr = Sprite::create("cid_icon4.png");
	spr->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(spr);


	// ���̽�ƽ
	joystick = Joystick::create();	// ���̽�ƽ ����
	joystick->setMainChar(spr);		// ���̽�ƽ���� ������ ��������Ʈ ����
	joystick->setSpeed(0.1f);		// ���̽�ƽ���� ������ ���ǵ� ����
	joystick->setLimitScreen(true);	// ��������Ʈ �������� ȭ�鿡 ���Ѱ������� true, �ƴ϶�� false �Ǵ� �Ƚᵵ ��
	this->addChild(joystick);



	// ��ġ
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ALL_AT_ONCE);


	schedule(schedule_selector(HelloWorld::Update), 0.0f);

	return true;
}

void HelloWorld::Update(float dt)
{
	joystick->update();
}

void HelloWorld::onTouchesBegan(const std::vector<Touch*> &touches, Event* unused_event)
{
	for (auto it : touches)
	{
		joystick->onTouchBegan(it, unused_event);
	}

}

void HelloWorld::onTouchesMoved(const std::vector<Touch*> &touches, Event* unused_event)
{
	for (auto it : touches)
	{
		joystick->onTouchMoved(it, unused_event);
	}

}

void HelloWorld::onTouchesEnded(const std::vector<Touch*> &touches, Event* unused_event)
{
	for (auto it : touches)
	{
		joystick->onTouchEnded(it, unused_event);
	}

}
