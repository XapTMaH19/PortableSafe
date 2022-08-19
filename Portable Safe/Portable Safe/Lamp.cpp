#include "Lamp.h"

Lamp::Lamp(RenderWindow& window, float radius, Vector2f position) : window(window) 
{
	circle.setRadius(radius);
	circle.setOutlineThickness(radius / 10);
	circle.setOrigin(radius, radius);
	circle.setPosition(position);
}

void Lamp::setColor(Color colorBackground, Color colorBorder)
{
	circle.setFillColor(colorBackground);
	circle.setOutlineColor(colorBorder);
}

void Lamp::setPosition(const Vector2f& position)
{
	circle.setPosition(position);
}

void Lamp::Draw()
{
	window.draw(circle);
}

Vector2f Lamp::getPosition() const
{
	return circle.getPosition();
}
