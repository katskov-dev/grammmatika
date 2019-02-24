#include "MainMenuScene.h"
#include "ui/CocosGUI.h"
cocos2d::Scene * MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	const int MENU_ITEM_FONT_SIZE = 56;
	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();

	play_label = Label::createWithTTF(u8"Играть", "fonts/arial.ttf", MENU_ITEM_FONT_SIZE); //Создание надписи (Label)
	menu_play_label = MenuItemLabel::create(play_label, CC_CALLBACK_1(MainMenuScene::menu_play_onClick, this)); //Создание "элемента меню" из надписи

	options_label = Label::createWithTTF(u8"Настройки", "fonts/arial.ttf", MENU_ITEM_FONT_SIZE);
	menu_options_label = MenuItemLabel::create(options_label);

	exit_label = Label::createWithTTF(u8"Выход", "fonts/arial.ttf", MENU_ITEM_FONT_SIZE);
	menu_exit_label = MenuItemLabel::create(exit_label, CC_CALLBACK_1(MainMenuScene::menu_exit_onClick, this));
	
	
	menu = Menu::create(menu_play_label, menu_options_label, menu_exit_label, nullptr); //Создание меню из "элемнтов меню"
	menu->alignItemsVerticallyWithPadding(30); // Вертикальное выравнивание элементов с отступом в 30 пикселей
	//menu->alignItemsHorizontallyWithPadding(15);
	this->addChild(menu, 1);
	
	
	
	



	return true;
}

void MainMenuScene::menu_exit_onClick(Ref * sender)
{
	auto director = Director::getInstance(); 
	director->end(); //Завершение работы директора и всего чем он управлял
}

void MainMenuScene::menu_play_onClick(Ref * sender)
{
	auto director = Director::getInstance();
	director->pushScene(this);
	auto game = HelloWorld::create();
	director->replaceScene(game);

}


