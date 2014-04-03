#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    shader.load("shadersGL3/01_ColorMap"); // Load the shader
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

    shader.begin(); // This starts the shader, so anything we draw gets passed to the shader

        // We need to draw something to give the shader vertices to work with
        // A simple rectangle that covers the screen will fullfill our needs for this shader
        ofRect(0, 0, ofGetWidth(), ofGetHeight());

    shader.end(); // End the shader
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
