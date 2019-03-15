#include "Hero.h"
#include "ui/CocosGUI.h"


Hero::Hero(String name)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	normal_frame = SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige.png", Rect(0, 0, 55, 73));
	//heroSprite = Sprite::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige.png");
	heroSprite = Sprite::create();
	heroSprite->setSpriteFrame(normal_frame);
	heroSprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(heroSprite, 0, "sprite");

	// ������ ������� ��������� ������

	animFrames.reserve(2);

	animFrames.pushBack(SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige_walk1.png", Rect(0, 0, 55, 73)));
	animFrames.pushBack(SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige_walk2.png", Rect(0, 0, 55, 73)));
	animFrames.pushBack(normal_frame);
}

Hero::~Hero()
{
}

void Hero::animation_move_to_up(Ref * sender, ui::Widget::TouchEventType type)//���������� ��� ������ �������� �����
{
	//heroSprite->setSpriteFrame(normal_frame);
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN: {
		
		// ������� �������� �� ������		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// ������� ������ �� 50 �������� ����� �� 2 �������.
		MoveBy* moveByUp = MoveBy::create(0.3, Vec2(0, 50)); //�����
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - �������� ����������� �����������, ������� ������������� nullptr
	
		//CallFuncN* myfunc = CallFunc::create(CC_CALLBACK_0(Hero::animation_end, this));
		auto myfunc = CallFunc::create([this]() {
			this->animation_end();
		});
		Sequence* seq = Sequence::create(spawn, myfunc, nullptr);
		this->runAction(seq); //��������� �������� ��� ���������
		this->heroSprite->runAction(Repeat::create(animate, 1)); //������ �������� ��� �������
		break;
	}
	case ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void Hero::animation_move_to_down(Ref * sender, ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN: {
		/*Animation* animation;
		Animate* animate;*/
		// ������� �������� �� ������		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// ������� ������ �� 50 �������� ����� �� 2 �������.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(0, -50)); //�����
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - �������� ����������� �����������, ������� ������������� nullptr
		this->runAction(spawn); //��������� �������� ��� ���������
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //������ �������� ��� �������
		break;
	}
	case ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void Hero::animation_move_to_left(Ref * sender, ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN: {
		/*Animation* animation;
		Animate* animate;*/
		// ������� �������� �� ������		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// ������� ������ �� 50 �������� ����� �� 2 �������.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(-50, 0)); //�����
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - �������� ����������� �����������, ������� ������������� nullptr
		this->runAction(spawn); //��������� �������� ��� ���������
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //������ �������� ��� �������
		break;
	}
	case ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void Hero::animation_move_to_right(Ref * sender, ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN: {
		/*Animation* animation;
		Animate* animate;*/
		// ������� �������� �� ������		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// ������� ������ �� 50 �������� ����� �� 2 �������.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(50, 0)); //�����
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - �������� ����������� �����������, ������� ������������� nullptr
		this->runAction(spawn); //��������� �������� ��� ���������
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //������ �������� ��� �������
		break;
	}
	case ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}

void Hero::animation_end()
{
	//heroSprite->setDisplayFrame(normal_frame);
	//Director::getInstance()->end();
}
