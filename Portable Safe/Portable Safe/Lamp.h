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

	// ��������� �������� �� ������� � ������� �������
    const bool isArea(const Vector2f& position) const;

	// �������� ������� �������
	const Vector2f getPosition() const;

	// �������� ������� �������
	const Vector2f getSize() const;

	// �������� ��������� ������� �� �������
	const Vector2f getLocalePosition(const Vector2f& position) const;

	// ���������� ������� ��� �������
	void setPosition(const Vector2f& position);

	// �������� ��������
	void On();

	// ��������� ��������
	void Off();

	// ���������
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