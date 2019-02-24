#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class Hero: public Node // Наш класс тоже элемент сцены
{
public:
	Hero(String name); 
	~Hero();

	void animation_move_to_up(Ref * sender, ui::Widget::TouchEventType type); //обработчик для кнопки движения вверх


	Vector<SpriteFrame*> animFrames;
	Sprite* heroSprite;
};

 