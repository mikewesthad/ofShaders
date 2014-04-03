#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);

    int w = ofGetWidth();
    int h = ofGetHeight();

    shader.load("shadersGL3/02_ConwaysGameOfLife");

    // Parameters for setting up the game
    //  liveColor is the color of a living pixel in the game
    //  deadColor is the color of a dead pixel in the game
    //  percentAlive determines how many live pixels there will be in first round (aka the seed)
    // TODO: Explain the rules of the game
    liveColor = ofColor(0, 255, 255);
    deadColor = ofColor(0, 0, 0);
    float percentAlive = 0.5;

    // Randomly generate a starting round for the game
    //  TODO: What ofPixels and ofTexture are and how they are being used here
    ofPixels pixels;
    pixels.allocate(w, h, OF_PIXELS_RGB);
    for (int x=0; x<ofGetWidth(); x++) {
        for (int y=0; y<ofGetHeight(); y++) {
            float rand = ofRandom(1.0);
            if (rand > percentAlive) pixels.setColor(x, y, deadColor);
            else pixels.setColor(x, y, liveColor);
        }
    }
    texture.loadData(pixels);

    // We need something to draw the game on, so let's create a rectangle
    //  TODO: Explain why you need this for the texture
    rectMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    rectMesh.addVertex(ofVec2f(0, 0));
    rectMesh.addVertex(ofVec2f(w, 0));
    rectMesh.addVertex(ofVec2f(w, h));
    rectMesh.addVertex(ofVec2f(0, h));
    ofIndexType indicies[6] = {0, 1, 2, 2, 3, 0};
    rectMesh.addIndices(indicies, 6);
    rectMesh.addTexCoord(ofVec2f(0, 0));
    rectMesh.addTexCoord(ofVec2f(w, 0));
    rectMesh.addTexCoord(ofVec2f(w, h));
    rectMesh.addTexCoord(ofVec2f(0, h));
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    // Run one round of the conway game
    //  TODO: Explain binding, uniforms
    texture.bind();
        shader.begin();
            shader.setUniform4f("liveColor", liveColor.r/255.0, liveColor.g/255.0, liveColor.b/255.0, liveColor.a/255.0);
            shader.setUniform4f("deadColor", deadColor.r/255.0, deadColor.g/255.0, deadColor.b/255.0, deadColor.a/255.0);
            rectMesh.draw();
        shader.end();
    texture.unbind();

    // Save the current round so that it can be fed back into the shader on the next round
    //  Hacky work around to avoid the vertical flipping that happens with loadScreenData(...)
    //  This code won't work right: texture.loadScreenData(0, 0, texture.getWidth(), texture.getHeight());
    ofImage tmpImg;
    tmpImg.grabScreen(0, 0, texture.getWidth(), texture.getHeight());
    texture = tmpImg.getTextureReference();

    // Draw the framerate
    ofDrawBitmapString("FPS: "+ofToString(ofGetFrameRate()), 0, 10);
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
