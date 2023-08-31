#include "Body.h"
#include <iostream>
#include <string>

using std::string;

Body::Body(RenderWindow& win, Vector2f sizes, Vector2f position, size_t protectionSize):
	win(win),
	sizes(sizes),
	left(position.x),
	top(position.y),
	right(position.x + sizes.x),
	bottom(position.y + sizes.y),
	protectionSize(protectionSize)
{
	// Установка размеров тела
	casing.setSize(sizes);
	overlayRect.setSize({ 0.8f * sizes.x, sizes.y - 0.55f * sizes.x });
	overlayCirc.setRadius(0.4f * sizes.x);
	lampsCirc.setRadius(0.35f * sizes.x);
	labelCirc.setRadius(0.25f * sizes.x);

	// Устанавливаем относительно чего считать центр
	casing.setOrigin({ 0.f, 0.f });
	overlayRect.setOrigin({ 0.f, 0.f });
	overlayCirc.setOrigin({ 0.f, 0.f });
	lampsCirc.setOrigin({ lampsCirc.getRadius(), lampsCirc.getRadius()});
	labelCirc.setOrigin({ labelCirc.getRadius(), labelCirc.getRadius()});

	//// Ширина Границы
	//casing.setOutlineThickness(std::min(sizes.x, sizes.y) / 100.f);
	//overlayRect.setOutlineThickness(0 / 100.f);
	//overlayCirc.setOutlineThickness(0 / 100.f);

	//// Цвет границы
	//casing.setOutlineColor(Palette::black);
	//overlayRect.setOutlineColor(Palette::onyx);
	//overlayCirc.setOutlineColor(Palette::onyx);





	// Установка цветов тела
	casing.setFillColor(Palette::nickel);
	overlayRect.setFillColor(Palette::onyx);
	overlayCirc.setFillColor(Palette::onyx);
	lampsCirc.setFillColor(Palette::darkGreenishYellowGreen);
	labelCirc.setFillColor(Palette::slateGrey);





	// Установка лампочек
	lampsCirc.setPosition({ left + 0.5f * sizes.x, top + 0.45f * sizes.x });
	labelCirc.setPosition({ left + 0.5f * sizes.x, top + 0.45f * sizes.x });
	R = (lampsCirc.getRadius() - labelCirc.getRadius()) / 2 + labelCirc.getRadius();
	X0 = lampsCirc.getPosition().x;
	Y0 = lampsCirc.getPosition().y;
	lamps.reserve(protectionSize);
	bool islamp = false;
	float angle;
	/*for (int i = 0; i < 2 * protectionSize; ++i)
	{
		angle = 2 * M_PI * i / (2 * protectionSize;
		std::cout << std::to_string(cos(angle)) + "\n";
	}*/
	for (int i = 0; i < 2 * protectionSize; ++i)
	{
		angle = 2 * M_PI * i / (2 * protectionSize);
		if (islamp)
		{
			//std::cout << "x = " + string(std::to_string(R * cos(angle) + X0)) + "   y = " + string(std::to_string(R * sin(angle) + Y0)) + "\n";
			lamps.push_back(Lamp(win, 0.4 * (lampsCirc.getRadius() - labelCirc.getRadius()), { R * cos(angle) + X0,  R * sin(angle) + Y0 }, Palette::goblin, Palette::aqua, Palette::graphiteGrey, Palette::graphiteGrey));
			islamp = false;
		}
		else
		{
			islamp = true;
		}
	}

	// Установка начальное позиции тела
	setPosition(position);

}

const Vector2f Body::getPosition() const
{
	return { left, top };
}

const Vector2f Body::getSize() const
{
	return sizes;
}

const Vector2f Body::getLocalePosition(const Vector2f& position) const
{
	return position - Vector2f(left, top);
}

const bool Body::isArea(const Vector2f& position) const
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

void Body::setPosition(const Vector2f& position)
{
	left = position.x;
	top = position.y;
	right = position.x + sizes.x;
	bottom = position.y + sizes.y;
	casing.setPosition({ left, top });
	overlayRect.setPosition({ left + 0.1f * sizes.x, top + 0.45f * sizes.x });
	overlayCirc.setPosition({ left + 0.1f * sizes.x, top + 0.05f * sizes.x });
	lampsCirc.setPosition({ left + 0.5f * sizes.x, top + 0.45f * sizes.x });
	labelCirc.setPosition({ left + 0.5f * sizes.x, top + 0.45f * sizes.x });

	X0 = lampsCirc.getPosition().x;
	Y0 = lampsCirc.getPosition().y;
	bool islamp = false;
	float angle;
	size_t ilamps = 0;
	for (int i = 0; i < 2 * protectionSize; ++i)
	{
		angle = 2 * M_PI * i / (2 * protectionSize);
		if (islamp)
		{
			lamps[ilamps].setPosition({R * cos(angle) + X0,  R * sin(angle) + Y0 });
			islamp = false;
			++ilamps;
		}
		else
		{
			islamp = true;
		}
	}
}

void Body::Draw()
{
	win.draw(casing);
	win.draw(overlayRect);
	win.draw(overlayCirc);
	win.draw(lampsCirc);
	win.draw(labelCirc);
	for (auto&& lamp : lamps)
	{
		lamp.Draw();
	}
}


