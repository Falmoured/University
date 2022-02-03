#include <SFML/Graphics.hpp>    
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Roflan");

    // круг
    sf::CircleShape shape(100);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOrigin(-600,0);

    int shape_x{ 0 }, shape_y{ 0 };

    // треугольник
    sf::CircleShape triangle(100,3);
    triangle.setFillColor(sf::Color::Magenta);
    triangle.setOrigin(-600,-225);

    int triangle_x{ 0 }, triangle_y{ 0 };

    // прямоугольник
    sf::RectangleShape rectangle(sf::Vector2f(200, 100));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOrigin(-600, -400);

    int rectangle_x{ 0 }, rectangle_y{ 0 };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        // Перемещение

        if (shape_x != -600)
            shape_x--;
        shape.setPosition(shape_x, shape_y);

        if (triangle_x != -600)
            triangle_x--;
        triangle.setPosition(triangle_x, triangle_y);

        if (rectangle_x != -600)
            rectangle_x--;
        rectangle.setPosition(rectangle_x, rectangle_y);

        //

        window.draw(shape);
        window.draw(triangle);
        window.draw(rectangle);

        window.display();

        std::this_thread::sleep_for(1ns);
    }

    return 0;
}