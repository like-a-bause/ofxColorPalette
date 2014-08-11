#include "ofApp.h"

#define NUM_COLOR 9
#define RECT_SIZE 45
#define PADDING 10
//--------------------------------------------------------------
void ofApp::setup(){
    palette = ofxColorPalette(ofColor(200,0,0));
    shortPalette = ofxShortColorPalette(ofShortColor(20,30000,13000));
    
    palette.generateMonoChromatic(NUM_COLOR);
    shortPalette.generateMonoChromatic(NUM_COLOR);
    floatPalette.generateMonoChromatic(NUM_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    for (int i = 0 ; i < NUM_COLOR; i++) {
        ofSetColor(palette[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    
    ofPopMatrix();
    
    
    ofTranslate(0, RECT_SIZE);
    
    ofPushMatrix();
    for (int i = 0 ; i < NUM_COLOR; i++) {
        ofSetColor(shortPalette[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    for (int i = 0 ; i < NUM_COLOR; i++) {
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
