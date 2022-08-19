#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>

using sf::Color;
using sf::CircleShape;
using sf::Vector2f;
using sf::RenderWindow;

class Lamp
{

public:

	// Конструктор лампочки 
	Lamp(RenderWindow& window, float radius, Vector2f position);

	// Установить цвет лампочки
	void setColor(Color colorBackground, Color colorBorder);

	// Перенести лампочку на выбранную позицию
	void setPosition(const Vector2f& position);

	// Отрисовать лампочку
	void Draw();

	// Получить позицию лампочки
	Vector2f getPosition() const;

private:

	CircleShape circle;
	RenderWindow& window;

};