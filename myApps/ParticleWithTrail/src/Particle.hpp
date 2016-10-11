//
//  Particle.hpp
//  Particle2
//
//  Created by taigakiyotaki on 2016/10/11.
//
//

#include "ofMain.h"

class Particle{
public:
    ofVec2f velocity;
    ofVec2f location;
    ofVec2f accel;
    float friction = 0.98;
    vector<ofVec2f> trail;
    int maxTrail = 80;
    Particle();
    void draw();
    void update();
    void updateAccel(ofVec2f& mouse);
    int r;
    int g;
    int b;
    float maxAlpha = 100;
    
};
