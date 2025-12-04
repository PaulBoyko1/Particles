#include "Engine.h"
#include <cstdlib>
#include <ctime>

Engine::Engine() {
  VideoMode comp = VideoMode::getDesktopMode();
  m_Window.create(desktop, "Click for particles!");
}
void Engine::run() {
  Clock clock;
  Time dt;
  float sec;

  cout << "Starting Particle unit tests..." << endl;
  Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
  p.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;
  while (m_Window.isOpen()) {
    dt = clock.restart();
    sec = dt.asSeconds();
    input();
    update(sec);
    draw();
  }
}
void Engine::input() {
  Event event;
  if (event.type == Event::KeyPressed) {
    if (event.key.code == Keyboard::Escape) {
      m_Window.close();
    }
  
    if (event.type == Event::MouseButtonPressed) {
      if (event.mouseButton.button == Mouse::Left) {
        for (int i = 0; i < 5; i++) {
          int rand = (rand() % 26) + 25;
          Particle p(m_Window, rand);
          m_particles.push_back(p);
        }
      }
    }
  }
}
void Engine::update(float dtAsSeconds) {
  for (/*vector<Particle>::iterator*/ auto i = m_particles.begin(); i != m_particles.end(); )
  {
      if (i->getTTL() > 0.0)
      {
          i->update(dtAsSeconds);
          ++it;
      }
      else
      {
          i = m_particles.erase(it);
      }
  }
  /*for (int i = 0; i < m_particles.size(); i = i) {
    if (m_particle[i].getTTL() > 0.0) {
      m_particle[i].update(dtAsSeconds);
      i++;
    }
    else {
      m_particles.erase(m_particles.begin() + i);
    }
  }*/
}
void Engine::draw() {
  m_Window.clear();
  for (int i = 0; i < m_particles.size(); i++)
  {
       m_Window.draw(m_particles[i]);
  }
  m_Window.display();
}
