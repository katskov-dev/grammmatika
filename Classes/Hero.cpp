#include "Hero.h"
#include "ui/CocosGUI.h"


Hero::Hero(String name)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	heroSprite = Sprite::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige.png");
	heroSprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(heroSprite, 0, "sprite");

	// теперь давайте анимируем спрайт

	animFrames.reserve(2);

	animFrames.pushBack(SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige_walk1.png", Rect(0, 0, 55, 73)));
	animFrames.pushBack(SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige_walk2.png", Rect(0, 0, 55, 73)));
}

Hero::~Hero()
{
}

void Hero::animation_move_to_up(Ref * sender, ui::Widget::TouchEventType type)//обработчик для кнопки движения вверх
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN: {
		Animation* animation;
		Animate* animate;
		// создает анимацию из кадров		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// Двигает спрайт на 50 пикселей вверх за 2 секунды.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(0, 50)); //вверх
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - действия выполняемые параллельно, цепочка заканчивается nullptr
		this->runAction(spawn); //запускаем движение для персонажа
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //запуск анимации для спрайта
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
		Animation* animation;
		Animate* animate;
		// создает анимацию из кадров		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// Двигает спрайт на 50 пикселей вверх за 2 секунды.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(0, -50)); //вверх
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - действия выполняемые параллельно, цепочка заканчивается nullptr
		this->runAction(spawn); //запускаем движение для персонажа
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //запуск анимации для спрайта
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
		Animation* animation;
		Animate* animate;
		// создает анимацию из кадров		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// Двигает спрайт на 50 пикселей вверх за 2 секунды.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(-50, 0)); //вверх
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - действия выполняемые параллельно, цепочка заканчивается nullptr
		this->runAction(spawn); //запускаем движение для персонажа
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //запуск анимации для спрайта
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
		Animation* animation;
		Animate* animate;
		// создает анимацию из кадров		
		animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		// Двигает спрайт на 50 пикселей вверх за 2 секунды.
		MoveBy* moveByUp = MoveBy::create(0.2, Vec2(50, 0)); //вверх
		Spawn* spawn = Spawn::create(moveByUp, nullptr); // Spawn - действия выполняемые параллельно, цепочка заканчивается nullptr
		this->runAction(spawn); //запускаем движение для персонажа
		this->getChildByName("sprite")->runAction(Repeat::create(animate, 1)); //запуск анимации для спрайта
		break;
	}
	case ui::Widget::TouchEventType::ENDED:
		break;
	default:
		break;
	}
}
