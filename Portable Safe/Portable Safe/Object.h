#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;

class Object
{

public:

	// ��������� �������� �� ������� � ������� �������
	virtual const bool isArea(const Vector2f& position) const = 0;

	// �������� ������� �������
	virtual const Vector2f getPosition() const = 0;

	// �������� ������� �������
	virtual const Vector2f getSize() const = 0;

	// �������� ��������� ������� �� �������
	virtual const Vector2f getLocalePosition(const Vector2f& position) const = 0;

	// ���������� ������� ��� �������
	virtual void setPosition(const Vector2f& position) = 0;

	// ���������
	virtual void Draw() = 0;

};