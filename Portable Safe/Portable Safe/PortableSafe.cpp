#include "PortableSafe.h"

PortableSafe::PortableSafe(RenderWindow& win, Vector2f sizes, Vector2f position) :
	win(win),
	body(win, sizes, position, 8)
{
	
}

PortableSafe::PortableSafe(RenderWindow& win) :
	win(win),
	body(win, { 300.f, 550.f }, {0.f, 0.f}, 8)
{
	// Установка сейфа по центру экрана
	Vector2u szWin = win.getSize();
	body.setPosition({szWin.x / 2u - body.getSize().x / 2, szWin.y / 2u - body.getSize().y / 2 });
}

const bool PortableSafe::isArea(const Vector2f& position) const
{
	return body.isArea(position);
}

void PortableSafe::Draw()
{
	body.Draw();
}

void PortableSafe::LeftClicPressed()
{
	dragOn = true;
	beginPos = body.getLocalePosition(win.mapPixelToCoords(Mouse::getPosition(win)));
}

void PortableSafe::LeftClicReleased()
{
	dragOn = false;
}

bool PortableSafe::getDragOn()
{
	return dragOn;
}

void PortableSafe::MoveWithMouse()
{
	body.setPosition(win.mapPixelToCoords(Mouse::getPosition(win)) - beginPos);
}
