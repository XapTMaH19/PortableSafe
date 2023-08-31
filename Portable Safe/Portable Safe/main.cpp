#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PortableSafe.h"
#include "Palette.h"
#include "Lamp.h"
#include "Body.h"

using sf::RenderWindow;
using sf::Event;
using sf::ContextSettings;
using sf::Mouse;
using sf::Keyboard;
using sf::RenderTarget;

int main()
{
    
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(sf::VideoMode(1200, 700), "Portable safe", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.clear(Palette::white);


    /*RECT rc, rw;
    int captionHeight;
    GetClientRect(window.getSystemHandle(), &rc);
    GetWindowRect(window.getSystemHandle(), &rw);
    MapWindowPoints(window.getSystemHandle(), HWND_DESKTOP, (POINT*)&rc, 2);
    captionHeight = rc.top - rw.top;*/

    Vector2f beginPos;
    bool drag = false;
    Event event;
    PortableSafe ps = PortableSafe(window);
    //PortableSafe pf = PortableSafe(window, {150.f, 300.f});
    //Vector2f localPosition; int mouseXold; int mouseYold;
    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
            {
                window.close();
                break;
            }
            case Event::MouseButtonPressed:
            {
                if ((event.key.code == Mouse::Left) && (ps.isArea(window.mapPixelToCoords(Mouse::getPosition(window)))))
                {
                    ps.LeftClicPressed();
                }
                break;
            }
            case Event::MouseButtonReleased:
            {
                if ((event.key.code == Mouse::Left) && (ps.isArea(window.mapPixelToCoords(Mouse::getPosition(window)))))
                {
                    ps.LeftClicReleased();
                }
                break;
            }
            }            
        }
  
        if (ps.getDragOn())
        {
            ps.MoveWithMouse();
        }
        window.clear(Palette::white);
        ps.Draw();
        window.display();
    }
    return 0;
}