#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake");

    sf::RectangleShape* snake = new sf::RectangleShape[3];
    int lenSnake = 3;
    for(int i=0; i<lenSnake; i++)
    {
        snake[i].setSize(sf::Vector2f(25,25));
        snake[i].setOrigin(snake[i].getSize().x/2, snake[i].getSize().y/2);
        snake[i].setPosition(250 + (i-1)*25, 250);
    }


    bool isGameGoing = false;
    sf::Keyboard::Key lastPressedKey = sf::Keyboard::Right;
    sf::Clock clock;
    int tn;
    int tc=0;
    int dt=0;

    //sf::Font font;
    sf::Text text;
    //font.loadFromFile("Arial.ttf");


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            isGameGoing = true;
        }

        tn=tc;
        tc = clock.getElapsedTime().asSeconds();
        dt+=(tc-tn);

        if(isGameGoing)
        {
            //Движение
            if(lastPressedKey == sf::Keyboard::Right && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x + 25, snake[lenSnake-1].getPosition().y);
                dt=0;
            }
            if(lastPressedKey == sf::Keyboard::Left && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x - 25, snake[lenSnake-1].getPosition().y);
                dt=0;
            }
            if(lastPressedKey == sf::Keyboard::Up && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x, snake[lenSnake-1].getPosition().y-25);
                dt=0;
            }
            if(lastPressedKey == sf::Keyboard::Down && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x, snake[lenSnake-1].getPosition().y +25);
                dt=0;
            }

            //Изменение направления
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                lastPressedKey = sf::Keyboard::Left;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                lastPressedKey = sf::Keyboard::Right;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                lastPressedKey = sf::Keyboard::Up;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                lastPressedKey = sf::Keyboard::Down;

            //Проверка на врезание в стену
            if(snake[lenSnake-1].getPosition().x > 500 || snake[lenSnake-1].getPosition().x <0 ||
                snake[lenSnake-1].getPosition().y > 500 || snake[lenSnake-1].getPosition().x <0)
                {
                    isGameGoing = false;
                }
        }


        window.clear();
        for(int i=0; i<lenSnake; i++)
        {
            window.draw(snake[i]);
        }
        window.draw(text);
        window.display();
    }

    return 0;
}
