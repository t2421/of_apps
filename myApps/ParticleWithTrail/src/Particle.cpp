//
//  Particle.cpp
//  Particle2
//
//  Created by taigakiyotaki on 2016/10/11.
//
//

#include "Particle.hpp"

Particle::Particle(){
    location.x = ofRandom(400);
    location.y = ofRandom(400);
    g =ofRandom(255);
    r = 255;
    b =255;
}

void Particle::draw(){
    ofSetColor(r, g, b);
    
    int numDrawTrail = std::min((int)trail.size(), maxTrail);
    int numTrail = trail.size();
    
    int count = 0;
    
    for (int i = numTrail-1; i >= 1; i--) {
        if(count >= numDrawTrail) break;
        float opacity = ofMap(count,0,numDrawTrail,maxAlpha,0);
        ofSetColor(r,g,b,opacity);
        ofDrawLine(trail[i]->x, trail[i]->y, trail[i-1]->x, trail[i-1]->y);
        count++;
    }
    
}

void Particle::update(){
    velocity += accel;
    velocity *= friction;
    location += velocity;
    
    trail.push_back(new ofVec2f(location));
}

void Particle::updateAccel(ofVec2f& mouse){
	float randStrength = 2;
    ofVec2f random = ofVec2f(ofRandom(randStrength)- randStrength/2.0,ofRandom(randStrength)- randStrength / 2.0);
    ofVec2f diff = mouse-location;
    float length = diff.length();
    float strength = std::min(length*0.07,0.7);

    ofVec2f direction = diff.normalize();
    accel = direction*strength+random;
    
}
