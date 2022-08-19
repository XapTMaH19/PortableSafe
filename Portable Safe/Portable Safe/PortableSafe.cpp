#include "PortableSafe.h"

PortableSafe::PortableSafe(RenderWindow& window, Vector2f sizes, Vector2f position, bool padlock) :
	window(window),
	sizes(sizes),
	lampPadlock(Lamp(window, sizes.x / 14, { position.x + sizes.x / 2.f, position.y + sizes.y * 0.9f })),
	clearRectangle(sizes),
	backgroundRectangle(sizes)
{
	// Установка локальной точкм
	backgroundRectangle.setOrigin({ 0, 0 });
	clearRectangle.setOrigin({ 0, 0 });
	// Установка границ background и clearRectangle
	backgroundRectangle.setOutlineThickness((sizes.x + sizes.y) / 100.f);
	backgroundRectangle.setOutlineColor(Palette::black);
	clearRectangle.setOutlineThickness((sizes.x + sizes.y) / 100.f);
	clearRectangle.setOutlineColor(Palette::white);
	// Установка начальное позиции clearRectangle
	clearRectangle.setPosition({ position.x + backgroundRectangle.getOutlineThickness(), position.y + backgroundRectangle.getOutlineThickness() });
	// Установка координат сейфа
	setCoord(position);
	// Установка цвета background
	backgroundRectangle.setFillColor(Palette::nickel);
	// Установка цвета clearRectangle
	clearRectangle.setFillColor(Palette::white);
	// Установка цвета lampPadlock
	if (padlock)
	{
		lampPadlock.setColor(Palette::lawnGreen, Palette::black);
	}
	else
	{
		lampPadlock.setColor(Palette::red, Palette::black);
	}
	// Отрисовка сейфа
	Update();
}

PortableSafe::PortableSafe(RenderWindow& window, Vector2f sizes, Vector2f position, vector<int> password) : PortableSafe(window, sizes, position, padlock)
{
	this->password = password;
}

bool PortableSafe::isArea(const Vector2f& position) const
{
	
	if ((position.x >= this->left) && (position.y >= this->top) && (position.x <= this->right) && (position.y <= this->bottom))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Vector2f PortableSafe::getAreaLocalePosition(const Vector2f& position) const
{
	return {position.x - left, position.y - top};
}

void PortableSafe::Update()
{
	window.draw(clearRectangle);
	window.display();
	window.draw(backgroundRectangle);
	lampPadlock.Draw();	
	window.display();	
}

void PortableSafe::setCoord(const Vector2f& position)
{
	this->left = position.x;
	this->top = position.y;
	this->right = position.x + sizes.x + 2 * backgroundRectangle.getOutlineThickness();
	this->bottom = position.y + sizes.y + 2 * backgroundRectangle.getOutlineThickness();
	backgroundRectangle.setPosition({position.x + backgroundRectangle.getOutlineThickness(), position.y + backgroundRectangle.getOutlineThickness() });
	lampPadlock.setPosition({ position.x + backgroundRectangle.getOutlineThickness() + sizes.x / 2.f, position.y + backgroundRectangle.getOutlineThickness() + sizes.y * 0.9f });
}

void PortableSafe::setPosition(const Vector2f& position)
{
	if ((position.x != left) && (position.y != top))
	{
		setCoord(position);
		Update();
		clearRectangle.setPosition({ position.x + backgroundRectangle.getOutlineThickness(), position.y + backgroundRectangle.getOutlineThickness() });
	}
}

Vector2f PortableSafe::getPosition()
{
	return { left, top };
}

Vector2f PortableSafe::getSize()
{
	return {right - left, bottom - top};
}
