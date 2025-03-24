#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>


int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 480), "Snake");

    sf::RectangleShape* snake = new sf::RectangleShape[3];
    int lenSnake = 3;
    for(int i=0; i<lenSnake; i++)
    {
        snake[i].setSize(sf::Vector2f(24,24));
        snake[i].setOrigin(snake[i].getSize().x/2, snake[i].getSize().y/2);
        snake[i].setPosition(228 + (i-1)*24, 228);
    }
    snake[lenSnake-1].setFillColor(sf::Color::Green);

    sf::RectangleShape ball;
    ball.setFillColor(sf::Color::Red);


    bool isGameGoing = false;
    bool isBallInGame = false;

    sf::Keyboard::Key lastPressedKey = sf::Keyboard::Right;
    sf::Clock clock;

    int tn;
    int tc=0;
    int dt=0;

    float ball_x;
    float ball_y;

    //sf::Font font;
    //sf::Text text;
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
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x + 24, snake[lenSnake-1].getPosition().y);
                dt=0;
            }
            if(lastPressedKey == sf::Keyboard::Left && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x - 24, snake[lenSnake-1].getPosition().y);
                dt=0;
            }
            if(lastPressedKey == sf::Keyboard::Up && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x, snake[lenSnake-1].getPosition().y-24);
                dt=0;
            }
            if(lastPressedKey == sf::Keyboard::Down && dt>=0.5)
            {
                for(int i=0; i<lenSnake-1; i++)
                {
                    snake[i].setPosition(snake[i+1].getPosition().x, snake[i+1].getPosition().y);
                }
                snake[lenSnake-1].setPosition(snake[lenSnake-1].getPosition().x, snake[lenSnake-1].getPosition().y +24);
                dt=0;
            }

            //Изменение направления
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
                && ((snake[lenSnake-1].getPosition().x - 24) != snake[lenSnake-2].getPosition().x))
                lastPressedKey = sf::Keyboard::Left;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                && ((snake[lenSnake-1].getPosition().x + 24) != snake[lenSnake-2].getPosition().x))
                lastPressedKey = sf::Keyboard::Right;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                && ((snake[lenSnake-1].getPosition().y - 24) != snake[lenSnake-2].getPosition().y))
                lastPressedKey = sf::Keyboard::Up;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                && ((snake[lenSnake-1].getPosition().y + 24) != snake[lenSnake-2].getPosition().y))
                lastPressedKey = sf::Keyboard::Down;

            //Проверка на врезание в стену
            if(snake[lenSnake-1].getPosition().x > 480 || snake[lenSnake-1].getPosition().x <0 ||
                snake[lenSnake-1].getPosition().y > 480 || snake[lenSnake-1].getPosition().y <0)
                {
                    isGameGoing = false;
                }
            
            //Проверка на врезание в змею
            for(int i =0; i<lenSnake-1; i++)
            {
                if(snake[lenSnake-1].getPosition()==snake[i].getPosition() && isBallInGame)
                    isGameGoing = false;
            }

            //Удлинение
            if(!isBallInGame)
            {
                ball_x = static_cast<float>(std::rand()%20);
                ball_y = static_cast<float>(std::rand()%20);

                std::cerr << ball_x << " " << ball_y << std::endl;
                for(int i=0;i<lenSnake; i++)
                {
                    if(ball_x == snake[i].getPosition().x)
                        ball_x = std::rand()%20;
                    if(ball_y == snake[i].getPosition().y)
                        ball_y = std::rand()%20; 
                }

                ball.setSize(sf::Vector2f(24,24));
                ball.setOrigin(ball.getSize().x/2, ball.getSize().y/2);
                ball.setPosition(12 + ball_x *24, 12 + ball_y *24); //x = 12 + x0 * 24 Перевод из с/к квадратов в с/к окна
                isBallInGame = true;
            }
            else
            {
                if(snake[lenSnake-1].getPosition()==ball.getPosition())
                {
                    sf::RectangleShape* tmp = new sf::RectangleShape[lenSnake+1];
                    for(int i=lenSnake; i>0; i--)
                    {
                        tmp[i] = snake[i-1];
                    }

                    tmp[0].setSize(sf::Vector2f(24,24));
                    tmp[0].setOrigin(snake[0].getSize().x/2, snake[0].getSize().y/2);
                    tmp[0].setPosition(snake[0].getPosition().x, snake[0].getPosition().y);

                    delete[] snake;
                    
                    snake = tmp;
                    isBallInGame = false;
                    lenSnake++;
                }
            }

            window.clear();
            //std::cerr << ball.getPosition().x << " " << ball.getPosition().y << std::endl;
            window.draw(ball);
        }
        

        //std::cerr << lenSnake << std::endl;
        for(int i=0; i<lenSnake; i++)
        {
            window.draw(snake[i]);
            //std::cerr << snake[i].getPosition().x << " " << snake[i].getPosition().y << std::endl;
        }
        //std::cerr << snake[lenSnake-1].getPosition().x << " " << snake[lenSnake-1].getPosition().y << std::endl;
        window.display();
    }

    delete[] snake;

    return 0;
}
