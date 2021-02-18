#pragma once

#include "glad/glad.h"

#include <stdlib.h>

#define ASSERT(x) if (!(x)) exit(-1)

void GLAPIENTRY GLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);