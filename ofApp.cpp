#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int len = ofGetWidth() < ofGetHeight() ? ofGetWidth() : ofGetHeight();
	ofColor box_color;
	for (int i = 0; i < 500; i++) {

		box_color.setHsb(ofRandom(255), 255, 255);
		ofSetColor(box_color, 139);

		ofPoint point = ofPoint(ofRandom(0, len), ofRandom(0, len), ofRandom(0, len));
		point.y = len - (int)(point.y + ofGetFrameNum() * ofRandom(0.25, 2.5)) % len;

		ofPushMatrix();
		ofTranslate(point);
		ofRotateX(ofRandom(360) + ofGetFrameNum() * ofRandom(-1.5, 1.5));
		ofRotateY(ofRandom(360) + ofGetFrameNum() * ofRandom(-1.5, 1.5));
		ofRotateZ(ofRandom(360) + ofGetFrameNum() * ofRandom(-1.5, 1.5));
		ofDrawBox(30);
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}