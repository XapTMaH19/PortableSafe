#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Skeleton.h"
#include "Lamp.h"
#include "Palette.h"

using sf::Vector2i;
using std::vector;
using sf::RenderWindow;
using sf::RectangleShape;
using sf::WindowHandle;

class PortableSafe : public Object
{
public:
	// Создать переносной сейф в окне
	explicit PortableSafe(RenderWindow& window, Vector2f sizes = { 300.f, 550.f }, Vector2f position = {0.f, 0.f}, bool padlock = false);
	explicit PortableSafe(RenderWindow& window, Vector2f sizes, Vector2f position, vector<int> password);

	// Проверка позиции на вхождение в область сейфа
	virtual bool isArea(const Vector2f& position) const override;

	// Найти локальную точку в области сейфа
	virtual Vector2f getAreaLocalePosition(const Vector2f& position) const override;

	// Подвинуть сейф
	void setPosition(const Vector2f& position);

	// Получить позицию сейфа
	Vector2f getPosition();

	// Получить размеры сейфа
	Vector2f getSize();

private:
	bool padlock;
	float left;
	float right;
	float top;
	float bottom;
	Skeleton scelet;
	RenderWindow& window;
	Vector2f sizes;
	Lamp lampPadlock;
	RectangleShape clearRectangle;
	RectangleShape backgroundRectangle;
	vector<int> password;
	void Update();
	void setCoord(const Vector2f& position);
	
};