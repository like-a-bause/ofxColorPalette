#include "ofApp.h"

#define NUM_COLOR 9
#define RECT_SIZE 70
#define PADDING 10
//--------------------------------------------------------------
void ofApp::setup(){
    complement = ofxColorPalette(ofColor::fireBrick);
    triad = ofxColorPalette(ofColor::fireBrick);
    complementTriad = ofxColorPalette(ofColor::fireBrick);
    monochrome = ofxColorPalette(ofColor::fireBrick);
    analogue = ofxColorPalette(ofColor::fireBrick);
    random = ofxColorPalette(ofColor::fireBrick);

    
    complement.generateComplementary();
    triad.generateTriad();
    complementTriad.generateComplementaryTriad();
    monochrome.generateMonoChromatic();
    analogue.generateAnalogous();
    random.generateRandom();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofColor base = ofColor::fromHsb(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255), ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255), 200);
    
    complement.setBaseColor(base);
    triad.setBaseColor(base);
    complementTriad.setBaseColor(base);
    monochrome.setBaseColor(base);
    analogue.setBaseColor(base);
    random.setBaseColor(base);
    
    
    complement.generateComplementary();
    triad.generateTriad();
    complementTriad.generateComplementaryTriad();
    monochrome.generateMonoChromatic();
    analogue.generateAnalogous();
    random.generateRandom();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofPushMatrix();
    for (int i = 0 ; i < complement.size(); i++) {
        ofSetColor(complement[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Complement", 0, 0);
    ofPopMatrix();
    
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    ofPushMatrix();
    for (int i = 0 ; i < triad.size(); i++) {
        ofSetColor(triad[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Triad", 0, 0);
    ofPopMatrix();
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    ofPushMatrix();
    for (int i = 0 ; i < complementTriad.size(); i++) {
        ofSetColor(complementTriad[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Complement Triad", 0, 0);
    ofPopMatrix();
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    ofPushMatrix();
    for (int i = 0 ; i < monochrome.size(); i++) {
        ofSetColor(monochrome[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Monochrome", 0, 0);
    ofPopMatrix();
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    ofPushMatrix();
    for (int i = 0 ; i < analogue.size(); i++) {
        ofSetColor(analogue[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Analogue", 0, 0);
    ofPopMatrix();
    
    ofTranslate(0, RECT_SIZE + PADDING);
    
    ofPushMatrix();
    for (int i = 0 ; i < random.size(); i++) {
        ofSetColor(random[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Random", 0, 0);
    ofPopMatrix();
    
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
