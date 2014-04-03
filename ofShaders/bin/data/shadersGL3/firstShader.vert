// vertex shader

// This statement tells the compiler/linker what version of the (Graphics Language Shading Language) GLSL
// you will be using.  openFrameworks uses openGL 3.2, which uses GLSL 1.5 (version 150)
// For which GLSL version corresponds to which openGL version, see http://en.wikipedia.org/wiki/OpenGL_Shading_Language
#version 150

// This a uniform variable:
//  Uniforms are global variables that all vertices share
//  They cannont be cannot be changed within a particular rendering call
//      Once you start your shader starts working on some vertices, this is a constant
//      Note: you *can* change the value of a uniform before rendering starts
//  modelViewProjectionMatrix is a uniform that is supplied to the vertex shader by openFrameworks
//      It contains the 4D matrix that we use to take a position in world space and project it onto the camera's screen
//      It is the combination of three separate matrices:
//          Model - maps from an object's local coordinate space into world space, so that all objects share a common origin
//          View - maps from world space to camera space, i.e. the camera is now our (0,0,0) point
//          Projection - projects through the camera's lens and "onto" the camera's 2D screen.
uniform mat4 modelViewProjectionMatrix;

// This is a vertex attribute:
//  Vertex attributes per-vertex, meaning that each vertex has it's own version of the attribute
//  The in keyword specifies that this variable is being fed in from a previous stage in the graphics pipeline
//      Here, that means that openFrameworks is passing a variable called position to each vertex
in vec4 position;

out vec4 color;

void main(){
    gl_Position = modelViewProjectionMatrix * position;
}
