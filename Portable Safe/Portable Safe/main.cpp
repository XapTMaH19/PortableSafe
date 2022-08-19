#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PortableSafe.h"
#include "Palette.h"
#include "Lamp.h"
#include "windows.h"

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
    //window.setFramerateLimit(60);
    window.clear(Palette::white);


    /*RECT rc, rw;
    int captionHeight;
    GetClientRect(window.getSystemHandle(), &rc);
    GetWindowRect(window.getSystemHandle(), &rw);
    MapWindowPoints(window.getSystemHandle(), HWND_DESKTOP, (POINT*)&rc, 2);
    captionHeight = rc.top - rw.top;*/

    Event event;
    PortableSafe pf = PortableSafe(window, {150.f, 300.f});
    Vector2f localPosition; int mouseXold; int mouseYold;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (window.hasFocus())
            {
                if (pf.isArea(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    
                    while ((event.type == Event::MouseButtonPressed) && (event.key.code == Mouse::Right))
                    {
                        localPosition = pf.getAreaLocalePosition(window.mapPixelToCoords(Mouse::getPosition(window)));
                        mouseXold = event.mouseButton.x;
                        mouseYold = event.mouseButton.y;
                        //if (pf.getPosition().x >= 0)
                        {
                            while (event.type == Event::MouseButtonPressed)
                            {
                                window.pollEvent(event);
                            }
                            while ((event.type != Event::MouseButtonReleased) && (event.type == Event::MouseMoved))
                            {
                                if ((event.mouseButton.x != mouseXold) || (event.mouseButton.y != mouseYold))
                                {
                                    pf.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)) - localPosition);
                                    mouseXold = event.mouseButton.x;
                                    mouseYold = event.mouseButton.y;
                                }
                                else
                                {
                                    std::cout << "0" << std::endl;
                                }
                                window.pollEvent(event);
                            }
                        }
                        window.pollEvent(event);
                    }
                }
            }

            //window.pollEvent(event);
            //if (event.type == Event::MouseMoved) //(event.type != Event::MouseButtonReleased)&&
            //{
            //    Sleep(200);
            //    std::cout << "1" << std::endl;
            //}
            //else
            //{
            //    Sleep(200);
            //    std::cout << "0" << std::endl;
            //}
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }        
    }
    return 0;
}