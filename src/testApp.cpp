#include "testApp.h"
#include "Poco/StringTokenizer.h"

//--------------------------------------------------------------
void testApp::setup(){
    font.loadFont("verdana.ttf", 48);

    words = splitIntoWords("is it bad to be able to feel your heartbeat");
    wordIndex = 0;

    wordsPerMinute = 500.0;
    wordTimeElapsed = 0.0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    wordTimeElapsed += ofGetLastFrameTime();
    if (wordTimeElapsed > 60.0/wordsPerMinute) {
        wordIndex++;
        if (wordIndex >= words.size()) wordIndex = 0;
        wordTimeElapsed = 0.0;
    }
    string word = words[wordIndex];

    ofBackground(0);
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(255);
        font.drawString(word, -font.stringWidth(word)/2, 0);
    ofPopMatrix();

}

vector<string> testApp::splitIntoWords(const string& buffer) {
    vector<string> output;
    Poco::StringTokenizer tokenizer(buffer, " ", 1);
    Poco::StringTokenizer::Iterator iter = tokenizer.begin();
    while (iter != tokenizer.end()) {
        output.push_back(*iter);
        iter++;
    }

    return output;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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
