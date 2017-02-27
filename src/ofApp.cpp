#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    pirState="pir State:";
    font.load("arial.ttf",20);
    pirNumber=0;
    
    myArd.connect("/dev/cu.usbmodem1441", 9600);
    
    
    ofAddListener(myArd.EInitialized,this, &ofApp::setupArduino);
    ISetupArduino =false;
    
    
    startTimer = false;
    
    cTime=0;
    
    timer=0;
    motionEndTime=3;
    
        soundPlayerFunction();
    
    ofEnableDepthTest();
    //    baseNode.setPosition(0, 0, 0);
    //    childNode.setParent(baseNode);
    //    childNode.setPosition(0, 0, 200);
    //    grandChildNode.setParent(childNode);
    //    grandChildNode.setPosition(0,200,0);
    //    ggrandChildNode.setParent(grandChildNode);
    //    ggrandChildNode.setPosition(10,10,10);
    //    gggrandChildNode.setParent(ggrandChildNode);
    //    gggrandChildNode.setPosition(0, 100, 500);
    
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(200, 0, 0);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0,200,0);
    ggrandChildNode.setParent(grandChildNode);
    ggrandChildNode.setPosition(200,200,0);
    gggrandChildNode.setParent(ggrandChildNode);
    gggrandChildNode.setPosition(0, 200, 200);
    gggrandChildNode6.setParent(gggrandChildNode);
    gggrandChildNode6.setPosition(200, 200, 200);
    gggrandChildNode7.setParent(gggrandChildNode6);
    gggrandChildNode7.setPosition(200,0,200);
    
    gggrandChildNode8.setParent(gggrandChildNode7);
    gggrandChildNode8.setPosition(0, 0, 200);
    
    
    LineState ==false;
    LineSize = 1200;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateArduino();
    
    
    if(LineState==false){
        
       
        
        vsound=ofLerp(vsound, 0, .01);
    
        
        // ----------------- 3dform
        //    baseNode.pan( 90);
        //    childNode.tilt(.5);
        //        grandChildNode.pan(.5);
        //        ggrandChildNode.tilt(.5);
        //        gggrandChildNode6.tilt(.5);
        //        gggrandChildNode7.pan(90);
        
        
        
        // ----------------- flower
        //            baseNode.pan( 45);
        //            childNode.tilt(.5);
        //                grandChildNode.pan(.5);
        //                ggrandChildNode.tilt(.5);
        //                gggrandChildNode6.tilt(.5);
        //                gggrandChildNode7.pan(45);
        
        
        
        //    --------circle
        baseNode.pan( .4);
        childNode.tilt( .4);
        grandChildNode.pan(.4);
        ggrandChildNode.tilt(.4);
        gggrandChildNode6.tilt(.4);
        gggrandChildNode7.pan(.4);
        
        
        //          ------cirve
        //        baseNode.pan( .1);
        //        childNode.tilt(.2);
        //        grandChildNode.pan(.5);
        //        ggrandChildNode.tilt(.6);
        //        gggrandChildNode6.tilt(.7);
        //        gggrandChildNode7.pan(5);
        
        
        //                baseNode.pan( 3);
        //                childNode.tilt(.2);
        //                grandChildNode.pan(.5);
        //                ggrandChildNode.tilt(6);
        //                gggrandChildNode6.tilt(.8);
        //                gggrandChildNode7.pan(1);
        
        
        
        
    } else if (LineState==true){
        //ofSetColor(ofRandom(100,255), 0, ofRandom(100,255));
        
      
        vsound=ofLerp(vsound, .8, .1);
        
        baseNode.pan(ofRandom(0, 1));
        baseNode.tilt(ofRandom(0, 1));
        childNode.tilt(ofRandom(0, 2));
        gggrandChildNode7.tilt(ofRandom(0, 1));
        ggrandChildNode.pan(ofRandom(0, 2));
        
        
        childNode.setPosition(0, 0, ofRandom(100, 200));
        grandChildNode.setPosition(ofRandom(30, 80), ofRandom(0, 100), ofRandom(100,200));
        gggrandChildNode7.setPosition(ofRandom(100, 400), 201, ofRandom(0,100));
        gggrandChildNode6.setPosition(ofRandom(100, 400), ofRandom(200,400), 10);
        
        
        baseNode.setPosition(0, ofRandom(0,20), ofRandom(200,250));
        
        
        
        
        ggrandChildNode.setPosition(ofRandom(75,300), 200, ofRandom(50,100));
        
        gggrandChildNode.setPosition(ofRandom(0, 300),100,ofRandom(0,400));
        
        
        
    }
    
    
    
    line.addVertex(gggrandChildNode8.getGlobalPosition());
    if (line.size() > LineSize){
        line.getVertices().erase(
                                 line.getVertices().begin()
                                 );
    }
    
}



//---------------------------------------------------------------
void ofApp::setupArduino(const int & version){
    
    //remove listner
    ofRemoveListener(myArd.EInitialized, this, &ofApp::setupArduino);
    
    ISetupArduino = true;
    
    // print firware name and version to console
    ofLogNotice() << myArd.getFirmwareName();
    ofLogNotice() << "firmata v" << myArd.getMajorFirmwareVersion() << "." << myArd.getMinorFirmwareVersion();
    
    
    
    myArd.sendDigitalPinMode(3, ARD_INPUT);
    myArd.sendDigitalPinMode(13, ARD_OUTPUT);
    
    // Listen for changes on the digital and analog pins
    ofAddListener(myArd.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    myArd.update();
    
    
}
//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int & pinNum) {
    // do something with the digital input. simply going to print the pin number and
    // value to the screen each time it changes
    pirState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(myArd.getDigital(pinNum));
    
    pirNumber=ofToInt(ofToString(myArd.getDigital(pinNum)));
}




void ofApp::colorChangeFunction(int x, int y){
    
    
    
    
    
    
    if(colorState!=PrecolorState){
        colorCh1++;
    } else {
        colorCh1--;
    }
    if (colorCh1>=x){
        colorState=PrecolorState;
    }
    if (colorCh1<=0){
        colorState=false;
    }
    
    //Dark line
//    colorCh2=ofMap(colorCh1, 0, x, 20, 180);
//    colorCh3=ofMap(colorCh1, 0, x, 180, 20);
//    colorLine=ofMap(colorCh1,0,x,140,50);
    //Light and Dark Line
    colorCh2=ofMap(colorCh1, 0, x, 5, 140);
    colorCh3=ofMap(colorCh1, 0, x, 140, 5);
    colorLine=ofMap(colorCh1,0,x,200,110);
    
}



void ofApp::soundPlayerFunction(){
    bgsound.load("bgSound.mp3");
    bgsound.setLoop(true);
    bgsound.play();
    bgsound.setVolume(.5);
    fxsound.load("fxSound.mp3");
    fxsound.setLoop(true);
    fxsound.play();
}




//--------------------------------------------------------------
void ofApp::draw(){
    

    
    
    colorChangeFunction(coloRange1, colorRange2);
    cout<<"colorCh1 =" <<colorCh1<<endl;
    cout<<"colorCH2 =" <<colorCh2<<endl;
    
    
    
    
   //ofBackground(20);
    
    
    ofColor colorOne(colorCh2,.9);
    ofColor colorTwo(colorCh3);
    //ofBackgroundGradient(colorOne, colorTwo,OF_GRADIENT_CIRCULAR);
    ofBackgroundGradient(colorTwo, colorOne,OF_GRADIENT_LINEAR);
     //ofBackgroundGradient(colorOne, colorTwo,OF_GRADIENT_LINEAR);
   // ofBackgroundGradient(colorOne, colorTwo,OF_GRADIENT_BAR);

    
    //ofEnableAlphaBlending();
    ofSetColor(250, 250, 250,150);
    
    //print out arduino state-------------------------------------------
    if(!ISetupArduino) {
        font.drawString("arduino is not ready.....\n", 400, 500);
    }else{
        //font.drawString( pirState,420,500 );
    }
    
    if(pirNumber==1){
        myArd.sendDigital(13, ARD_HIGH);
    } else{
        myArd.sendDigital(13, ARD_LOW);
        
    }
    
    //pir state check
    // ofLogNotice()<<pirNumber;
    pirTimer();
    
    
    
    
    
    //-----------
    
    float spinX = sin(ofGetElapsedTimef()*.05f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    
    float spinCam=sin(ofGetElapsedTimef()*.1f);
    
    cam.begin();
    
    cam.getDistance();
    //cout<<cam.getDistance()<<endl;
    //cout<<LineSize<<endl;
    
    
    
    //uncomment these 3 lines to understand how nodes are moving
    // baseNode.draw();
    //childNode.draw();
    //grandChildNode.draw();
    
    //---------__Setting the line color----------------
    if(LineState==false){
        ofSetColor(colorLine);
       
//            for ( int i=0; i<=1000; i++){
//            vsound= ofMap(i,0,1000,.0,1.0);
//        }
        //fxsound.setVolume(0);
        
        
    } else if(LineState==true){
        
        ofSetColor(ofRandom(59,120));
        
        
        //fxsound.setVolume(.2f);
      
        
    }
    
    fxsound.setVolume(vsound);
    
        //----------------------------cam-------
    cam.setDistance(spinCam*300+2800);
    
    ofRotate(spinX*100, 1.0, 0, 1);
    ofRotate(spinY*50, 0, 1.0, 0.0);
    
    
    //draw line--------------------------------------------
    
    ofSetLineWidth(2);
    line.draw();
    
    
    //draw box-------------------------------------------------------------
    
    ofPushStyle();
     ofNoFill();
    
    ofDrawSphere(line.getPointAtPercent(1), 4);
        //float ci= ofGetMouseX();
    
    //    for(float i=0; i<=1; i=i+.005){
    //
    //        //ofDrawCone(line.getPointAtPercent(i),20, 30);
    //    //ofDrawIcoSphere(line.getPointAtPercent(i), 50);
    //       // ofDrawArrow(line.getPointAtPercent(i), line.getPointAtPercent(i+1));
    //
    //
    //
    //        //ofDrawSphere(line.getPointAtPercent(i), 30);
    //      //ofDrawBox(line.getPointAtPercent(i), 50);
    //
    //    }
    //
    //
    //    for(float i=0; i<=1; i=i+.005){
    //
    //
    //        //ofDrawCylinder(line.getPointAtPercent(i), 50, 20);
    //    }
    
    
    
    ofPopStyle();
    
    
    
    
    
    
    
    cam.end();
    
    
    //    if(pirNumber==1){
    //
    //        childNode.setPosition(0, ofRandom(0,200), ofRandom(100, 200));
    //        gggrandChildNode7.setPosition(ofRandom(100,400), 201, 100);
    //
    //        LineState=true;
    //        LineSize=1500;
    //
    //    } else if (pirNumber ==0){
    //        LineState = false;
    //        LineSize=1200;
    //
    //    }
    
    
    cout<<"node =" <<line.getPointAtLength(200).x<<endl;
    
    cout<<"node =" <<line.getPointAtLength(200)<<endl;
    
    //ofDrawBox(line.getPointAtLength(1), 30);
    
    
    // ofDrawBox(line.getBoundingBox());
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='o'){
        
        childNode.setPosition(0, ofRandom(0,200), ofRandom(100, 200));
        gggrandChildNode7.setPosition(ofRandom(100,400), 201, 100);
        
        LineState=true;
        LineSize=1200;
        
    } else if (key =='p'){
        LineState = false;
        LineSize=1200;
        
    }
    
    cout<<"Linestate =" <<LineSize<<endl;
    
    
}


void ofApp::pirTimer(){
    
    
    millisecond = ofGetElapsedTimeMillis();
    
    if(pirNumber==1){
        startTimer=true;
        timer=0;
        
    }
    
    if(startTimer==true&& millisecond-cTime>=1000){
        
        
        
        timer++;
        
        
        cTime=millisecond;
        
    }
    if(startTimer==true&&  millisecond-cTime>=100 &&timer==0){
        
        
        childNode.setPosition(0, ofRandom(0,200), ofRandom(100, 200));
        gggrandChildNode7.setPosition(ofRandom(100,400), 201, 100);
        
        LineState=true;
        LineSize=1500;
        
        
    }
    if(timer==1){
        
        
        
    }else if(timer==2){
    }
    
    
    if(pirNumber==0 &&timer>=motionEndTime){
        
        startTimer=false;
        
        LineState = false;
        LineSize=1200;
        
        if(millisecond-cTime>=100){
            
            
            cTime=millisecond;
        }
        
    }
    
    
    ofLogNotice()<<timer;
    
}









//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

