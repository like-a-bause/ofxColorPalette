#include "ofApp.h"

#define NUM_COLOR 9
#define RECT_SIZE 70
#define PADDING 10
//--------------------------------------------------------------
void ofApp::setup(){
    mode = ofxColorPalette::BRIGHTNESS;
    brightness = 200;
    saturation = 200;

}

//--------------------------------------------------------------
void ofApp::update(){
    switch (mode) {
        case ofxColorPalette::BRIGHTNESS:
            brightness = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255);
            break;
        case ofxColorPalette::SATURATION:
            saturation = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255);
            break;
        default:
            break;
    };
    
    ofColor base = ofColor::fromHsb(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255), saturation, brightness);
    
    complement.setBaseColor(base);
    complementBrightness.setBaseColor(base);
    triad.setBaseColor(base);
    complementTriad.setBaseColor(base);
    monochrome.setBaseColor(base);
    monochromeBrightness.setBaseColor(base);
    analogue.setBaseColor(base);
    random.setBaseColor(base);
    
    
    complement.generateComplementary();
    complementBrightness.generateComplementary(ofxColorPalette::BRIGHTNESS);
    triad.generateTriad();
    complementTriad.generateComplementaryTriad();
    monochrome.generateMonoChromatic();
    monochromeBrightness.generateMonoChromatic(ofxColorPalette::BRIGHTNESS);
    analogue.generateAnalogous();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    
    //--begin
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
    // ----
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
    // ----
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
    ofDrawBitmapString("Complement (Saturation)", 0, 0);
    ofPopMatrix();
    ofTranslate(0, RECT_SIZE + PADDING);
    // ----
    ofPushMatrix();
    for (int i = 0 ; i < complementBrightness.size(); i++) {
        ofSetColor(complementBrightness[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Complement (Brightness)", 0, 0);
    ofPopMatrix();
    ofTranslate(0, RECT_SIZE + PADDING);
    // ----
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
    ofDrawBitmapString("Monochrome (Saturation)", 0, 0);
    ofPopMatrix();
    ofTranslate(0, RECT_SIZE + PADDING);
    // ----
    ofPushMatrix();
    for (int i = 0 ; i < monochromeBrightness.size(); i++) {
        ofSetColor(monochromeBrightness[i]);
        ofRect(0, 0, RECT_SIZE, RECT_SIZE);
        ofTranslate(RECT_SIZE, 0);
    }
    ofPopMatrix();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, RECT_SIZE /2);
    ofSetColor(0);
    ofDrawBitmapString("Monochrome (Brightness)", 0, 0);
    ofPopMatrix();
    ofTranslate(0, RECT_SIZE + PADDING);
    // ----
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
    // ----
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
    ofDrawBitmapString("Random (Click to regenerate)", 0, 0);
    ofPopMatrix();
    
    ofTranslate(10, RECT_SIZE+PADDING);
    string info = "Press key for (s)aturation or (b)rightness \n";
    info += "x-Axis (hue):" + ofToString(complement[0].getHue()) + "\n";
    string modeString;
    float modeValue;
    if(mode == ofxColorPalette::SATURATION){
        modeString = " (saturation)";
        modeValue = saturation;
    }else {
        modeString = " (brightness)";
        modeValue = brightness;
    }
    info += "y-Axis " + modeString + ofToString(modeValue) +  "\n";
    ofDrawBitmapString(info,0,0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        mode = ofxColorPalette::SATURATION;
    }else if (key == 'b'){
        mode = ofxColorPalette::BRIGHTNESS;
    }

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
    random.generateRandom();

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
