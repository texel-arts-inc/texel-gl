#pragma once

#include <string>
#include "WGL.h"

namespace TexelWGL {
    int32_t
    choosePixelFormatWithDescriptor(WGL::DeviceContext deviceContext,
                                    WGL::PixelFormatDescriptor *pixelFormatDescriptor);

    int32_t
    choosePixelFormat(WGL::DeviceContext deviceContext,
                      int32_t const *attribIList,
                      float const *attribFList,
                      uint32_t numMaxFormats,
                      int32_t *formats,
                      uint32_t *numFormats);

    int32_t
    copyContext(WGL::ResourceContext source,
                WGL::ResourceContext destination,
                uint32_t groups);

    WGL::ResourceContext
    createContext(WGL::DeviceContext deviceContext);

    WGL::ResourceContext
    createLayerContext(WGL::DeviceContext deviceContext,
                       int32_t layer);

    int32_t
    deleteContext(WGL::ResourceContext resourceContext);

    int32_t
    describePixelFormat(WGL::DeviceContext deviceContext,
                        int32_t pixelFormat,
                        uint32_t numBytes,
                        WGL::PixelFormatDescriptor *pixelFormatDescriptor);

    WGL::ResourceContext
    getCurrentContext(void);

    WGL::DeviceContext
    getCurrentDeviceContext(void);

    WGL::DeviceContext
    getCurrentReadDeviceContext(void);

    char const *
    getExtensionsString(WGL::DeviceContext deviceContext);

    int32_t
    getPixelFormat(WGL::DeviceContext hdc);

    int32_t
    getPixelFormatAttribfv(WGL::DeviceContext hdc,
                           int32_t pixelFormat,
                           int32_t layerPlane,
                           uint32_t numAttributes,
                           int32_t const *attributes,
                           float *values);

    int32_t
    getPixelFormatAttribiv(WGL::DeviceContext deviceContext,
                           int32_t pixelFormat,
                           int32_t layerPlane,
                           uint32_t numAttributes,
                           int32_t const *attributes,
                           int32_t *values);

    void const *
    getProcedureAddress(char const *name);

    int32_t
    makeCurrentContext(WGL::DeviceContext deviceContext,
                       WGL::ResourceContext resourceContext);

    int32_t
    setPixelFormat(WGL::DeviceContext deviceContext,
                   int32_t pixelFormat,
                   WGL::PixelFormatDescriptor *pixelFormatDescriptor);

    int32_t
    shareLists(WGL::ResourceContext source,
               WGL::ResourceContext destination);

    int32_t
    swapBuffers(WGL::DeviceContext deviceContext);

    int32_t
    swapLayerBuffers(WGL::DeviceContext deviceContext,
                     int32_t layer);
} // namepsace texelWGL