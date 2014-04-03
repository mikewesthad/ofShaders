// fragment shader

#version 150

// This is one of the main outputs of a fragment shader, the color of a pixel in a buffer.
//  More possible outputs listed here: http://www.opengl.org/wiki/Fragment_Shader#Outputs
// The outputs of the fragment shader are sent on for per-sample processing
//  This involves pixel operations: depth occlusion, color blending, etc.
//  Overview: http://www.opengl.org/wiki/Per-Sample_Processing
//  Nicer descriptions: http://www.glprogramming.com/red/chapter10.html#name2
out vec4 outputColor;

void main()
{
    // gl_FragCoord is a built-in openGL input variable to the fragment shader
    // It contains the screen relative coordinate for the fragment.
    //  We use gl_FragCoord.x position to control the red color value.
    //  We use gl_FragCoord.y position to control the green color value.
    //  Note that all r, g, b, a values must be between 0 and 1

    float windowWidth = 1024.0;
    float windowHeight = 768.0;

    float r = gl_FragCoord.x / windowWidth;
    float g = gl_FragCoord.y / windowHeight;
    float b = 1.0;
    float a = 1.0;
    outputColor = vec4(r, g, b, a);
}
