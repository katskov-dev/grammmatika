/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "Hero.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
//движения
Vector<SpriteFrame*> animFrames;

// создает анимацию из кадров


bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
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
	

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    

	
	hero = new Hero(this, "MyHero1"); // Создаем героя и сразу привязываем его к сцене или другой ноде


	//1-ый батон
	move_to_up = ui::Button::create("qq/Base_pack/Items/bomb.png");
	move_to_up->setTitleText("Up");
	move_to_up->setPosition(Point(200, 300));
	
	move_to_up->addTouchEventListener(CC_CALLBACK_2(Hero::animation_move_to_up, hero));
	//button1->addTouchEventListener(CC_CALLBACK_2(Hero::animation_move_to_up, this));
	/*move_to_up->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type)
	{
		this->my_hero->animation_move_to_up(sender, type);
	});*/
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


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
	Director::getInstance()->popScene();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


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
