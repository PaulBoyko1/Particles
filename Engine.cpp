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
  }
  if (event.type == Event::MouseButtonPressed) {
    if (event.mouseButton.button == Mouse::Left) {
      for (int i = 0; i < 5; i++) {
        int rand = (rand() % 26) + 25;
        Particle p(m_Window, rand);
        p.push_back(m_particles);
    }
  }
}
void Engine::update(float dtAsSeconds) {

}
void Engine::draw() {

}
