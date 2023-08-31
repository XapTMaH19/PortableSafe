#include "Lamp.h"

Lamp::Lamp(RenderWindow& window, float radius, Vector2f position, Color onBackColor, Color onFrontColor, Color offBackColor, Color offFrontColor) :
	window(window),
	condition(false),
	position(position),
	radius(radius)
{
	// Устанавливаем радиус лампочки
	onCircleBack.setRadius(radius);
	onCircleFront.setRadius(0.8 * radius);
	offCircleBack.setRadius(radius);
	offCircleFront.setRadius(0.8 * radius);

	// Устанавливаем относительно чего считать центр
	onCircleBack.setOrigin(radius, radius);
	onCircleFront.setOrigin(0.8 * radius, 0.8 * radius);
	offCircleBack.setOrigin(radius, radius);
	offCircleFront.setOrigin(0.8 * radius, 0.8 * radius);

	// Устанавливаем цвета лампочки
	onCircleBack.setFillColor(onBackColor);
	onCircleFront.setFillColor(onFrontColor);
	offCircleBack.setFillColor(offBackColor);
	offCircleFront.setFillColor(offFrontColor);

	// Устанавливаем позицию лампочки
	setPosition(position);
}

const bool Lamp::isArea(const Vector2f& position) const
{
	if ((position.x - this->position.x) * (position.x - this->position.x) +
	   (position.y - this->position.y) * (position.y - this->position.y) < radius * radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Lamp::setPosition(const Vector2f& position)
{
	onCircleBack.setPosition(position);
	onCircleFront.setPosition(position);
	offCircleBack.setPosition(position);
	offCircleFront.setPosition(position);
}

void Lamp::On()
{
	condition = true;
}

void Lamp::Off()
{
	condition = false;
}

void Lamp::Draw()
{
	if (condition)
	{
		window.draw(onCircleBack);
		window.draw(onCircleFront);
	}
	else
	{
		window.draw(offCircleBack);
		window.draw(offCircleFront);
	}
}

const Vector2f Lamp::getPosition() const
{
	return position;
}

const Vector2f Lamp::getSize() const
{
	return { radius, radius };
}

const Vector2f Lamp::getLocalePosition(const Vector2f& position) const
{
	return position - Vector2f(this->position.x - radius, this->position.y - radius);
}
