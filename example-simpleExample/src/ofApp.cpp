#include "ofApp.h"

#define NUM_COLOR 9
#define RECT_SIZE 45
#define PADDING 10
//--------------------------------------------------------------
void ofApp::setup(){
    palette = ofxColorPalette(ofColor::olive);
    shortPalette = ofxShortColorPalette(ofShortColor::royalBlue);
    floatPalette = ofxFloatColorPalette(ofFloatColor::aliceBlue);
    
    palette.generateMonoChromatic(NUM_COLOR);
    shortPalette.generateComplementary();
    floatPalette.generateAnalogous(1,0.25);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    for (int i = 0 ; i < palette.size(); i++) {
        ofSetColor(palette[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    
    ofPopMatrix();
    
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    ofPushMatrix();
    for (int i = 0 ; i < shortPalette.size(); i++) {
        ofSetColor(shortPalette[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    for (int i = 0 ; i < floatPalette.size(); i++) {
        ofSetColor(floatPalette[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
