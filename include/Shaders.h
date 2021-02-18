#include <string>

struct BasicShader {
    static const std::string Vertex;
    static const std::string Fragment;
};

const std::string BasicShader::Vertex =
"#version 440 core\n"
"\n"
"layout(location = 0) in vec4 position;\n"
"layout(location = 1) in vec2 texCoord;\n"
"\n"
"out vec2 v_TexCoord;\n"
"\n"
"uniform mat4 u_MVP;\n"
"\n"
"void main() {\n"
"    gl_Position = u_MVP * position;\n"
"    v_TexCoord = texCoord;\n"
"};\n";

const std::string BasicShader::Fragment =
"#version 440 core\n"
"\n"
"layout(location = 0) out vec4 color;\n"
"\n"
"in vec2 v_TexCoord;\n"
"\n"
"uniform sampler2D u_Texture;\n"
"\n"
"void main() {\n"
"    vec4 texColor = texture(u_Texture, v_TexCoord);\n"
"    color = texColor;\n"
"};";