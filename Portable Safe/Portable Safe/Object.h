#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;

class Object {

	// Проверить является ли позиция в области объекта
	virtual bool isArea(const Vector2f& position) const = 0;

	// Найти локальную точку в области объекта
	virtual Vector2f getAreaLocalePosition(const Vector2f& position) const = 0;
};