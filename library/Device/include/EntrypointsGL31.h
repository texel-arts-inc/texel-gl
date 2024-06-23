#pragma once

#include "Entrypoints.h"

EXPORT_API void
glGetActiveUniformBlockiv(uint32_t program,
                          uint32_t uniformBlockIndex,
                          TexelGL::GL::Enum name,
                          int32_t *params);

EXPORT_API void
glGetUniformBlockIndex(uint32_t program,
                       char const *uniformBlockName);

EXPORT_API void
glUniformBlockBinding(uint32_t program,
                      uint32_t uniformBlockIndex,
                      uint32_t uniformBlockBinding);