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
	void animation_move_to_down(Ref * sender, ui::Widget::TouchEventType type); //обработчик для кнопки движения вверх
	void animation_move_to_left(Ref * sender, ui::Widget::TouchEventType type); //обработчик для кнопки движения влево
	void animation_move_to_right(Ref * sender, ui::Widget::TouchEventType type); //обработчик для кнопки движения вправо

	Vector<SpriteFrame*> animFrames;
	Sprite* heroSprite;
};

 