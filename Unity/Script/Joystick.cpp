/*********************************************************************
* Date : 2015.09.30
* Name : ���̽�ƽ (��Ƽ��ġ)
* Email : kyechan99@naver.com
* Description : http://blog.naver.com/kyechan99/220492857669
* ���� �ҽ� �Դϴ�. �� ���� �ҽ� �����ϸ� �������ּ���.
***********************************************************************/
#include "Joystick.h"

// ������ ���
bool isTouchCircle(Point pos, Point center, float radius)
{
	float dx = (pos.x - center.x);
	float dy = (pos.y - center.y);
	return (radius >= sqrt((dx*dx) + (dy*dy)));
}

bool Joystick::init()
{
	if (!Layer::init())
		return false;


	//Size visibleSize = Director::getInstance()->getVisibleSize();
	winSize = Director::getInstance()->getWinSize();


	// ��ġ�ϰ� �ִ� �� ����
	isTouch = false;

	// ������ ���ǵ� (�����Ϸ��� setSpeed()�Լ� ���)
	m_speed = 0.1f;

	// ������ ����� �̵��� ���� �Ұ������� ���� ����
	isLimmitWinSize = false;

	// ���̽�ƽ - ��� ������
	centerPos = Vec2(125, 125);


	// ���̽�ƽ - ���� �Ǿ� �ִ� ����
	joystick_limit = Sprite::create("joystick_limit_circle.png");
	joystick_limit->setPosition(centerPos);
	this->addChild(joystick_limit);


	// ���̽�ƽ - ������ ����
	joystick_control = Sprite::create("joystick_control_circle.png");
	joystick_control->setPosition(centerPos);
	this->addChild(joystick_control);


	// ���̽�ƽ - ��Ʈ�ѷ��� ������
	controlerPos = centerPos;

	return true;
}

// ���̽�ƽ ��ġ, ���ΰ� ��ġ, ����Ʈ ����
void Joystick::update()
{
	// ���̽�ƽ - ������ ���� ��� ������Ʈ ����
	joystick_control->setPosition(controlerPos);

	// ��ġ �����϶��� ������
	if (isTouch)
	{
		// ������ �Ÿ� ���ϱ�
		float moveX = controlerPos.x - centerPos.x;
		float moveY = controlerPos.y - centerPos.y;

		Vec2 charPos = mainChar->getPosition();


		if (checkLimit())
		{
			if (0 < charPos.x + moveX * m_speed && charPos.x + moveX * m_speed < winSize.width)
			{
				charPos.x += moveX * m_speed;
			}
			if (0 < charPos.y + moveY * m_speed && charPos.y + moveY * m_speed < winSize.height)
			{
				charPos.y += moveY * m_speed;
			}
			mainChar->setPosition(charPos);
		}
		else
		{
			charPos.x += moveX * m_speed;
			charPos.y += moveY * m_speed;
			mainChar->setPosition(charPos);
		}
	}
}

// ���̽�ƽ - ���ǵ� ����
void Joystick::setSpeed(float speed)
{
	m_speed = speed;
}

// ���̽�ƽ - ���ΰ� ����
void Joystick::setMainChar(Sprite* mainChar)
{
	this->mainChar = mainChar;
}

// ��������Ʈ ȭ�� �̵� ���� �ޱ�
void Joystick::setLimitScreen(bool check)
{
	isLimmitWinSize = check;
}

// ������ ����� �̵��� ���� �Ұ������� ���� ����
bool Joystick::checkLimit()
{
	return isLimmitWinSize;
}


bool Joystick::onTouchBegan(Touch* touch, Event* unused_event)
{
	// ���̽�ƽ - ����Ʈ �����ȿ��� ������ �Ͽ��ٸ�
	if (isTouchCircle(touch->getLocation(), centerPos, joystick_limit->getContentSize().width / 2))
	{
		isTouch = true;

		controlerPos = touch->getLocation();

		return isTouch;
	}
	return isTouch;
}

void Joystick::onTouchMoved(Touch* touch, Event* unused_event)
{
	if (isTouch)
	{
		// ��ġ�� ����Ʈ ������ �Ѿ��� �ÿ� ��Ʈ�ѷ��� ���κп� �����ְ� �ϱ� ����
		if (!(isTouchCircle(touch->getLocation(), centerPos, joystick_limit->getContentSize().width / 2)))
		{
			Point touchPos = touch->getLocation();	// ��ġ ��ġ��
			float limitSize = joystick_limit->getContentSize().width / 2;	// ���� ������ ������

			float dX = touchPos.x - centerPos.x;
			float dY = touchPos.y - centerPos.y;

			float distance = sqrt(dX*dX + dY*dY);	// �밢�� ���� ���ϱ�
			float angle = atan2(dY, dX);			// ���� ���ϱ�

			if (distance > limitSize){
				dX = cos(angle) * limitSize;
				dY = sin(angle) * limitSize;
			}


			if (distance > joystick_control->getContentSize().width / 2)
			{
				touchPos.x = centerPos.x + dX;
				touchPos.y = centerPos.y + dY;
			}

			controlerPos = Vec2(touchPos);

		}
		else
		{
			controlerPos = touch->getLocation();
		}

	}
}

void Joystick::onTouchEnded(Touch* touch, Event* unused_event)
{
	if (isTouch)
	{
		// ��ġ�� ������ ���̽�ƽ�� ���� ��ġ�� ���ư�
		controlerPos = centerPos;
	}
	isTouch = false;
}
