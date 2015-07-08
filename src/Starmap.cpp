#include "../include/Starmap.hh"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Starmap::Starmap() {
  displayx = 800;
  displayy = 500;

  m_smallrad = 1.0;
  m_mediumrad = 2.0;
  m_largerad = 4.0;
  m_tslow = 1/100.0;
  m_tmedium = 1/50.0;
  m_tlarge = 1/20.0;
  m_v = 10.0;
}
Starmap::~Starmap() {;}

void Starmap::init_star() {
  m_small.setRadius(m_smallrad);
  m_medium.setRadius(m_mediumrad);
  m_large.setRadius(m_largerad);

  srand( time(NULL) );
  //Small
  for(int i=0; i<100; i++) {
    m_small.setPosition(rand()%800,rand()%500);
    small_v.push_back(m_small);
  }
  //Medium
  for(int i=0; i<50; i++) {
    m_medium.setPosition(rand()%800,rand()%500);
    medium_v.push_back(m_medium);
  }
  //Large
  for(int i=0; i<25; i++) {
    m_large.setPosition(rand()%800,rand()%500);
    large_v.push_back(m_large);
  }
}

void Starmap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  std::vector<sf::CircleShape>::const_iterator it;
  for(it=small_v.begin(); it!=small_v.end(); ++it)
    target.draw(*it);
  for(it=medium_v.begin(); it!=medium_v.end(); ++it)
    target.draw(*it);  
  for(it=large_v.begin(); it!=large_v.end(); ++it)
    target.draw(*it); 
}

void Starmap::update() {
  srand( time(NULL) );
  
  std::vector<sf::CircleShape>::iterator it;
  unsigned int small  = 0;
  unsigned int medium = 0;
  unsigned int large  = 0;
  //Move stars(small,med,large)
  //Erase when star leaves display window, 
  //then regenerate one randomly at the top of the screen
  for( it=small_v.begin(); it!=small_v.end(); ++it ) {
    it->move(0.0,m_v*m_tslow);
    if( it->getPosition().y >= 500-1 ) {
      small_v.erase(it);
      ++small;
    }
  }
  if( small>0 ) {
    for(int i=0; i<small; i++) {
      m_small.setPosition(rand()%800,0);
      small_v.push_back(m_small);
    }
  }
  for( it=medium_v.begin(); it!=medium_v.end(); ++it ) {
    it->move(0.0,m_v*m_tmedium);
    if( it->getPosition().y >= 500-1 ) {
      medium_v.erase(it);
      ++medium;
    }
  }
  if( medium>0 ) {
    for(int i=0; i<medium; i++) {
      m_medium.setPosition(rand()%800,0);
      medium_v.push_back(m_medium);
    }
  }
  for( it=large_v.begin(); it!=large_v.end(); ++it ) {
    it->move(0.0,m_v*m_tlarge);
    if( it->getPosition().y == 500-1 ) {
      large_v.erase(it);
      ++large;
    }
  }
  if( large>0 ) {
    for(int i=0; i<large; i++) {
      m_large.setPosition(rand()%800,0);
      large_v.push_back(m_large);
    }
  }
}
