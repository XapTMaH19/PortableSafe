#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InterfaceMouse.h"
#include "Body.h"
#include "Lamp.h"


using sf::Vector2i;
using sf::Vector2u;
using std::vector;
using sf::RenderWindow;
using sf::RectangleShape;
using sf::WindowHandle;
using sf::Mouse;

class PortableSafe : public InterfaceMouse
{
public:

	PortableSafe(RenderWindow& win, Vector2f sizes, Vector2f position);

	// �� ���������
	PortableSafe(RenderWindow& win);

	// ��������� �������� �� ������� � ������� ����
	const bool isArea(const Vector2f& position) const ;

	// ���������
	void Draw();

	// ����� ���� �� ����
	void LeftClicPressed() override;

	// ��������� ����� ���� � ����
	void LeftClicReleased() override;

	// �������� ����� �� ����� ���� �� ����
	bool getDragOn() override;

	// ��������� ������ ������ � ������
	void MoveWithMouse() override;
	
private:
	
	RenderWindow& win;

	Body body;
};