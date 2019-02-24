#include "Hero.h"
#include "ui/CocosGUI.h"


Hero::Hero(Scene * scene, String name)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	hero = Node::create();
	scene->addChild(hero, 0, name.getCString());
	heroSprite = Sprite::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige.png");
	heroSprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	hero->addChild(heroSprite, 0, "sprite");

	// теперь давайте анимируем спрайт

	animFrames.reserve(2);

	animFrames.pushBack(SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige_walk1.png", Rect(0, 0, 55, 73)));
	animFrames.pushBack(SpriteFrame::create("qq/Extra_animations_and_enemies/Alien_sprites/alienBeige_walk2.png", Rect(0, 0, 55, 73)));
}

Hero::~Hero()
{
}

void Hero::animation_move_to_up(Ref * sender, ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN: {
		Animation* animation;
		Animate* animate;
		// создает анимацию из кадров
		
		animation = Animation::createWithSpriteFrames(this->animFrames, 0.1f);
		animate = Animate::create(animation);
		// Двигает спрайт на 50 пикселей вверх за 2 секунды.
		auto moveByUp = MoveBy::create(0.2, Vec2(0, 50)); //вверх
		
		

		auto spawn = Spawn::create(moveByUp);

		hero->getChildByName("sprite")->runAction(spawn);
		//Hero->setPosition(Point(700,500));
		hero->getChildByName("sprite")->runAction(Repeat::create(animate, 1));



	}
											break;

	case ui::Widget::TouchEventType::ENDED:
		//std::cout << "Button 1 clicked" << std::endl;
		break;
	default:
		break;
	}
}
