#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InterfaceMouse.h"
#include "Body.h"
#include "Lamp.h"


using sf::Vector2i;
using sf::Vector2u;
using std::vector;
using sf::RenderWindow;
using sf::RectangleShape;
using sf::WindowHandle;
using sf::Mouse;

class PortableSafe : public InterfaceMouse
{
public:

	PortableSafe(RenderWindow& win, Vector2f sizes, Vector2f position);

	// По умолчанию
	PortableSafe(RenderWindow& win);

	// Проверить является ли позиция в области тела
	const bool isArea(const Vector2f& position) const ;

	// Отрисовка
	void Draw();

	// Левый клик по телу
	void LeftClicPressed() override;

	// Отпускаем левый клик с тела
	void LeftClicReleased() override;

	// Получить нажат ли левый клик на тело
	bool getDragOn() override;

	// Подвинуть объект вместе с мышкой
	void MoveWithMouse() override;
	
private:
	
	RenderWindow& win;

	Body body;
};