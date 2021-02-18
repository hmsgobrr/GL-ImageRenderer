#include "VertexArray.h"

#include "GLErrorManager.h"

VertexArray::VertexArray() { glGenVertexArrays(1, &m_RendererID); }
VertexArray::~VertexArray() { glDeleteVertexArrays(1, &m_RendererID); }

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), reinterpret_cast<const void*>((const intptr_t)offset));
        offset += element.count * VertexBufferElement::GetSizeOfGLType(element.type);
    }
}

void VertexArray::Bind() const { glBindVertexArray(m_RendererID); }
void VertexArray::UnBind() const { glBindVertexArray(0); }