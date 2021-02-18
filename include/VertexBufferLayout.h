#pragma once

#include <vector>
#include "GLErrorManager.h"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfGLType(unsigned int type) {
        switch (type) {
        case GL_FLOAT:         return 4;
        case GL_UNSIGNED_INT:  return 4;
        case GL_UNSIGNED_BYTE: return 1;
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
public:
    VertexBufferLayout() :m_Stride(0) {}

    void Push(unsigned int type, unsigned int count, unsigned char normalized) {
        m_Elements.push_back({ type, count, normalized });
        m_Stride += count * VertexBufferElement::GetSizeOfGLType(type);
    }

    inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
    inline unsigned int GetStride() const { return m_Stride; }
};