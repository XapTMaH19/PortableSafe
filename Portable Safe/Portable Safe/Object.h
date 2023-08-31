#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;

class Object
{

public:

	// Проверить является ли позиция в области объекта
	virtual const bool isArea(const Vector2f& position) const = 0;

	// Получить позицию объекта
	virtual const Vector2f getPosition() const = 0;

	// Получить размеры объекта
	virtual const Vector2f getSize() const = 0;

	// Получить локальную позицию на объекте
	virtual const Vector2f getLocalePosition(const Vector2f& position) const = 0;

	// Установить позицию для объекта
	virtual void setPosition(const Vector2f& position) = 0;

	// Отрисовка
	virtual void Draw() = 0;

};