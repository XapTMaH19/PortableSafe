#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;

class InterfaceMouse
{
public:
	// ����� ���� �� �������
	virtual void LeftClicPressed() = 0;

	// ��������� ����� ���� �� �������
	virtual void LeftClicReleased() = 0;

	// �������� ����� �� ����� ���� �� ������
	virtual bool getDragOn() = 0;

	// ��������� ������ ������ � ������
	virtual void MoveWithMouse() = 0;

protected:
	bool dragOn;
	Vector2f beginPos;
};

