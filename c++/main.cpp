#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class gravitySource{

    sf::Vector2f pos;
    float strength;
    sf::CircleShape s;

public:

    gravitySource(float posX, float posY, float strength) {
        pos.x = posX;
        pos.y = posY;
        this->strength = strength;

        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
        s.setRadius(10);
    }

    void render(sf::RenderWindow& wind) {
        wind.draw(s);
    }

    sf::Vector2f getPos() {
        return pos;
    }

    float getStrength() {
        return strength;
    }
};

class particle {

    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape s;

public:

    particle(float posX, float posY, float velX, float velY) {
        pos.x = posX;
        pos.y = posY;

        vel.x = velX;
        vel.y = velY;

        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
        s.setRadius(5);
    }

    void render(sf::RenderWindow& wind) {
        s.setPosition(pos);
        wind.draw(s);
    }

    void setColor(sf::Color col) {
        s.setFillColor(col);
    }

    void updatePhysics(gravitySource &s) {
        float distanceX = s.getPos().x - pos.x;
        float distanceY = s.getPos().y - pos.y;
        
        float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

        float inverseDistance = 1.f / distance;

        float normalizedX = inverseDistance * distanceX;
        float normalizedY = inverseDistance * distanceY;

        float inverseSquare = inverseDistance * inverseDistance;

        float accelerationX = normalizedX * s.getStrength() * inverseSquare;
        float accelerationY = normalizedY * s.getStrength() * inverseSquare;

        vel.x += accelerationX;
        vel.y += accelerationY;

        pos.x += vel.x;
        pos.y += vel.y;

        //setColor(sf::Color(distance * vel.y, 0, distance * vel.x));
    }

};

sf::Color mapValToColour(float value) {
    if (value < 0.0f) value = 0;
    if (value > 1.0f) value = 1;

    int r = 0, g = 0, b = 0;

    if (value < 0.5f) {
        b = 255 * (1.0f - 2 * value);
        g = 255 * 2 * value;
    }
    else {
        g = 255 * (2.0f - 2 * value);
        r = 255 * (2 * value - 1);
    }

    return sf::Color(r, g, b);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "My Program");
    window.setFramerateLimit(60);

    std::vector<gravitySource> sources;

    sources.push_back(gravitySource(500, 700, 7000));
    sources.push_back(gravitySource(1200, 700, 7000));
    sources.push_back(gravitySource(750, 200, 7000));

    int numParticles = 10000;

    std::vector<particle> particles;

    for (int i = 0; i < numParticles; i++) {
        particles.push_back(particle(400, 400, 1, 0.2 + (0.3 / numParticles) * i));

        //change color
        float val = (float)i / (float)numParticles;

        sf::Color col = mapValToColour(val);

        particles[i].setColor(col);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }


        window.clear();

        for (int i = 0; i < sources.size(); i++) {
            for (int j = 0; j < particles.size(); j++) {
                particles[j].updatePhysics(sources[i]);
            }
        }

        for (int i = 0; i < sources.size(); i++) {
            sources[i].render(window);
        }

        for (int j = 0; j < particles.size(); j++) {
            particles[j].render(window);
        }


        window.display();
    }



    return 0;
}