#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

using sf::Color;
using sf::CircleShape;
using sf::Vector2f;
using sf::RenderWindow;

class Lamp : public Object
{

public:

	explicit Lamp(RenderWindow& window, float radius, Vector2f position, Color onBackColor, Color onFrontColor, Color offBackColor, Color offFrontColor);

	// Проверить является ли позиция в области объекта
    const bool isArea(const Vector2f& position) const;

	// Получить позицию объекта
	const Vector2f getPosition() const;

	// Получить размеры объекта
	const Vector2f getSize() const;

	// Получить локальную позицию на объекте
	const Vector2f getLocalePosition(const Vector2f& position) const;

	// Установить позицию для объекта
	void setPosition(const Vector2f& position);

	// Включить лампочку
	void On();

	// Выключить лампочку
	void Off();

	// Отрисовка
	void Draw();

private:
	RenderWindow& window;

	CircleShape onCircleFront;
	CircleShape onCircleBack;
	CircleShape offCircleFront;
	CircleShape offCircleBack;

	bool condition;
	Vector2f position;
	float radius;
};