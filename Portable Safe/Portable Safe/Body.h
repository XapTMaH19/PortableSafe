#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Object.h"
#include "Lamp.h"
#include "Palette.h"


using sf::RenderWindow;
using sf::RectangleShape;
using sf::CircleShape;
using std::vector;

class Body: public Object
{
public:
	
	explicit Body(RenderWindow& win, Vector2f sizes, Vector2f position, size_t protectionSize);

	// ��������� �������� �� ������� � ������� ����
	const bool isArea(const Vector2f& position) const override;

	// �������� ������� ����
	const Vector2f getPosition() const override;

	// �������� ������� ����
	const Vector2f getSize() const override;

	// �������� ��������� ������� ����
	const Vector2f getLocalePosition(const Vector2f& position) const override;

	// ���������� ������� ����
	void setPosition(const Vector2f& position) override;
	
	// ���������
	void Draw() override;

private:
	RenderWindow& win;

	float left;
	float top;
	float right;
	float bottom;
	Vector2f sizes;

	RectangleShape casing;
	RectangleShape overlayRect;
	CircleShape overlayCirc;
	CircleShape lampsCirc;
	CircleShape labelCirc;

	const size_t protectionSize;

	vector<Lamp> lamps;
	float angle;
	float R;
	float X0;
	float Y0;
};