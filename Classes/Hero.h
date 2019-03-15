#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class Hero: public Node // ��� ����� ���� ������� �����
{
public:
	Hero(String name); 
	~Hero();

	void animation_move_to_up(Ref * sender, ui::Widget::TouchEventType type); //���������� ��� ������ �������� �����
	void animation_move_to_down(Ref * sender, ui::Widget::TouchEventType type); //���������� ��� ������ �������� �����
	void animation_move_to_left(Ref * sender, ui::Widget::TouchEventType type); //���������� ��� ������ �������� �����
	void animation_move_to_right(Ref * sender, ui::Widget::TouchEventType type); //���������� ��� ������ �������� ������
	void animation_end();

	Vector<SpriteFrame*> animFrames;
	Sprite* heroSprite;
	SpriteFrame* normal_frame;
	Animation* animation;
	Animate* animate;
};

 