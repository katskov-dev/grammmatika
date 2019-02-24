#pragma once

#include "cocos2d.h" 
#include "HelloWorldScene.h"
USING_NS_CC;

class MainMenuScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);
public:
	Menu* menu;
	Label* play_label;
	Label* options_label;
	Label* exit_label;
	MenuItemLabel* menu_play_label;
	MenuItemLabel* menu_options_label;
	MenuItemLabel* menu_exit_label;

	void menu_exit_onClick(Ref* sender); // Обработка нажатия "Играть"
	void menu_play_onClick(Ref* sender); // Обработка нажатия "Выход"
};

