//vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
in vec2 texcoord; // This must be exactly like this, i.e. lowercase
in vec4 position;

uniform vec4 liveColor;
uniform vec4 deadColor;

out vec2 vertexTexCoord;

void main()
{
    vertexTexCoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
}
