#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "Hero.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
	
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	back_to_menu_button = ui::Button::create();
	this->addChild(back_to_menu_button);
	back_to_menu_button->setTitleText(u8"Выйти в главное меню");
	back_to_menu_button->setTitleFontSize(28);
	back_to_menu_button->setPosition(Vec2(back_to_menu_button->getSize().width / 2.0 + 15, visibleSize.height - back_to_menu_button->getSize().height - 5));
	back_to_menu_button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::back_to_menu_button_onClick, this));

    

	
	hero = new Hero("MyHero1"); // Создаем героя и сразу привязываем его к сцене или другой ноде
	this->addChild(hero);


	//1-ый батон
	move_to_up = ui::Button::create("qq/Base_pack/Items/bomb.png");
	move_to_up->setTitleText("Up");
	move_to_up->setPosition(Point(200, 300));
	
	move_to_up->addTouchEventListener(CC_CALLBACK_2(Hero::animation_move_to_up, hero));
	this->addChild(move_to_up);

	//2-ой батон
	auto button2 = ui::Button::create("qq/Base_pack/Items/bomb.png");
	button2->setTitleText("Down");
	button2->setPosition(Point(200, 100));
	
	this->addChild(button2);

	//3-ий батон
	auto button3 = ui::Button::create("qq/Base_pack/Items/bomb.png");
	button3->setTitleText("Left");
	button3->setPosition(Point(100, 200));
	
	this->addChild(button3);

	//4-ый батон
	auto button4 = ui::Button::create("qq/Base_pack/Items/bomb.png");
	button4->setTitleText("Right");
	button4->setPosition(Point(300, 200));
	
	this->addChild(button4);



	



    return true;
}

void HelloWorld::back_to_menu_button_onClick(Ref * pSender, ui::Widget::TouchEventType type)
{
	
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		break;
	case ui::Widget::TouchEventType::ENDED:
		Director::getInstance()->popScene();
		break;
	default:
		break;
	}
}
