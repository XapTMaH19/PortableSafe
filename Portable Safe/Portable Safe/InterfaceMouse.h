#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;

class InterfaceMouse
{
public:
	// Левый клик на объекте
	virtual void LeftClicPressed() = 0;

	// Отпускаем левый клик на объекте
	virtual void LeftClicReleased() = 0;

	// Получить нажат ли левый клик на объект
	virtual bool getDragOn() = 0;

	// Подвинуть объект вместе с мышкой
	virtual void MoveWithMouse() = 0;

protected:
	bool dragOn;
	Vector2f beginPos;
};

