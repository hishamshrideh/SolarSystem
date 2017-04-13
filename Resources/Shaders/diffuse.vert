#version 150 core

in vec3 vertexPosition;
in vec2 vertexTexCoord;

out vec3 position;
out vec2 texCoord;

uniform mat4 modelView;
uniform mat4 mvp;

uniform float texCoordScale;

void main()
{
    texCoord = vertexTexCoord * texCoordScale;
    position = vec3(modelView * vec4(vertexPosition, 1.0));
    gl_Position = mvp * vec4(vertexPosition, 1.0);
}
