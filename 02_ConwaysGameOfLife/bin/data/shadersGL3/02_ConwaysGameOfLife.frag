// fragment shader

#version 150


// this is how we receive the texture
uniform sampler2DRect tex0;
in vec2 vertexTexCoord;
out vec4 outputColor;

uniform vec4 liveColor;
uniform vec4 deadColor;

void main()
{
    vec4 currentColor = texture(tex0, vertexTexCoord);

    int numAlive = 0;
    for (int dx=-1; dx<=1; dx++) {
        for (int dy=-1; dy<=1; dy++) {

            if (dx != 0 || dy != 0) {
                vec2 neighborCoord = vec2(vertexTexCoord.x+float(dx), vertexTexCoord.y+float(dy));
                vec4 neighborColor = texture(tex0, neighborCoord);
                if (neighborColor == liveColor) numAlive++;
            }

        }
    }

    if (numAlive <= 1 || numAlive >= 4) outputColor = deadColor;
    else if (numAlive == 2) outputColor = currentColor; // If alive, stay alive.  If dead, stay dead.
    else if (numAlive == 3) outputColor = liveColor;

}
