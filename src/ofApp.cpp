#include "ofApp.h"
#include <iostream>
#include <math.h>
#include "actor.h"
using namespace std;

float _startDeltaTime;
float _interval = 0.07f;
float velocity;
float mass;
float maxVelocity;
bool clicked = false;
ofVec2f gravity;

ofVec2f momentum;

actor *spaceship;
actor *escudo;

//--------------------------------------------------------------
void ofApp::setup()
{
  mass = 0.5;
  velocity = 100;
  maxVelocity = 200;
  momentum.set(0, 0);

  _startDeltaTime = ofGetElapsedTimef();

  spaceship = new actor(450, 350, "images/spaceship.png");
  escudo = new actor(500, 500, "images/moon.png");
  spaceship->imagem.setAnchorPercent(0.5f, 0.5f);
  escudo->getDistancia(spaceship->vetor);
}

//--------------------------------------------------------------
void ofApp::update()
{
  if (ofGetElapsedTimef() - _startDeltaTime > _interval)
  {
    ofVec2f forces;
    ofVec2f acceleration;
    ofVec2f accelSecs;
    ofVec2f vecTodirect;
    float deltaTime = ofGetLastFrameTime();

    vecTodirect = spaceship->newVec.normalize() * velocity;

    acceleration = forces / mass;
    accelSecs = (acceleration + vecTodirect) * deltaTime;

    escudo->rotation();

    //if (clicked)
    //{
    spaceship->vetor += (momentum + accelSecs / 2) * deltaTime;
    //}

    momentum += accelSecs;

    _startDeltaTime = ofGetElapsedTimef();
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofSetBackgroundColor(0, 0, 0, 255);
  ofPushMatrix();
  ofTranslate(spaceship->vetor.x, spaceship->vetor.y);
  ofRotateZ(90 + spaceship->rotationClick);
  spaceship->draw();
  ofPushMatrix();
  ofTranslate(escudo->vetor.x, escudo->vetor.y);
  escudo->draw();
  ofPopMatrix();
  ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
  spaceship->clickMouse(x, y);
  //clicked = true;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
