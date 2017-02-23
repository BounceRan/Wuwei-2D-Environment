#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void colorChangeFunction(int x, int y);
    void soundPlayerFunction();
    
    ofArduino myArd;
    ofTrueTypeFont font;
    
    bool ISetupArduino;
    
    bool startTimer;
    
    ofNode baseNode;
    ofNode childNode;
    ofNode grandChildNode;
    ofNode ggrandChildNode;
    ofNode gggrandChildNode;
    ofNode gggrandChildNode6;
    ofNode gggrandChildNode7;
    ofNode gggrandChildNode8;
    
    ofPolyline line;
    ofEasyCam cam;
    
    bool LineState;
    int LineSize;
    
    int coloRange1=1000;
    int colorRange2=0;
    float colorCh1=0;
    float colorCh2=0;
    float colorCh3=0;
    float colorLine=0;
    
    
    bool colorState=false;
    bool PrecolorState=true;
    
    float percent;
    
    
    ofSoundPlayer bgsound;
    ofSoundPlayer fxsound;
    int vbsound=1000;
    float vsound=0;
    
    
private:
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void updateArduino();
    
    string pirState;
    int pirNumber;
    
    int millisecond;
    int cTime;
    int timer;
    int motionEndTime;
    void pirTimer();
    
    
    
    
    
    
    
};
