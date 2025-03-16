#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(750,750), "lab_8");

    sf::CircleShape circle(100.f);
    circle.setPosition(sf::Vector2f(375.f,375.f));
    circle.setFillColor(sf::Color::Red);

    sf::RectangleShape square(sf::Vector2f(100.f,100.f));
    square.setPosition(sf::Vector2f(100.f,100.f));
    square.setFillColor(sf::Color::Green);
    

    sf::RectangleShape line(sf::Vector2f(200.f,5.f));
    line.setPosition(sf::Vector2f(100.f,450.f));
    line.setRotation(45.f);
    line.setOrigin(line.getSize().x/2, line.getSize().y/2);

    bool color_changed = false;
    float speed = 10;
    sf::Clock clock;
    float t_n;
    float t_c = 0.f;
    float dt;
    float w = 10;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            circle.setFillColor(sf::Color::Green);
            color_changed = true;
        }
        else if(color_changed)
            circle.setFillColor(sf::Color::Red);
        
        
        t_n = t_c;
        t_c= clock.getElapsedTime().asSeconds();
        dt = t_c - t_n;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            square.setPosition(sf::Vector2f(square.getPosition().x - speed * dt, square.getPosition().y));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            square.setPosition(sf::Vector2f(square.getPosition().x + speed * dt, square.getPosition().y));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            square.setPosition(sf::Vector2f(square.getPosition().x, square.getPosition().y - speed * dt));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            square.setPosition(sf::Vector2f(square.getPosition().x, square.getPosition().y + speed * dt));

        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            line.setRotation(line.getRotation() - w * dt);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            line.setRotation(line.getRotation() + w * dt);

        
        
        window.clear();
        window.draw(circle);
        window.draw(square);
        window.draw(line);
        window.display();
    }

    return 0;
}
