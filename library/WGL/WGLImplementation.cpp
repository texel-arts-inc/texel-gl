#include "Entrypoints.h"
#include "WGLEntrypoints.h"

EXPORT_API int32_t
wglChoosePixelFormat(WGL::DeviceContext deviceContext,
                        WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return TexelWGL::choosePixelFormatWithDescriptor(deviceContext,
                                                     pixelFormatDescriptor);
}

EXPORT_API int32_t
wglCopyContext(WGL::ResourceContext source,
               WGL::ResourceContext destination,
               uint32_t groups)
{
    return TexelWGL::copyContext(source,
                                 destination,
                                 groups);
}

EXPORT_API WGL::ResourceContext
wglCreateContext(WGL::DeviceContext deviceContext)
{
    return TexelWGL::createContext(deviceContext);
}

EXPORT_API WGL::ResourceContext
wglCreateLayerContext(WGL::DeviceContext deviceContext,
                      int32_t layer)
{
    return TexelWGL::createLayerContext(deviceContext,
                                        layer);
}

EXPORT_API int32_t
wglDeleteContext(WGL::ResourceContext resourceContext)
{
    return TexelWGL::deleteContext(resourceContext);
}

EXPORT_API int32_t
wglDescribePixelFormat(WGL::DeviceContext deviceContext,
                       int32_t pixelFormat,
                       uint32_t numBytes,
                       WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return TexelWGL::describePixelFormat(deviceContext,
                                         pixelFormat,
                                         numBytes,
                                         pixelFormatDescriptor);
}

EXPORT_API WGL::ResourceContext
wglGetCurrentContext(void)
{
    return TexelWGL::getCurrentContext();
}

EXPORT_API WGL::DeviceContext
wglGetCurrentDC(void)
{
    return TexelWGL::getCurrentDeviceContext();
}

EXPORT_API WGL::DeviceContext
wglGetCurrentReadDC(void)
{
    return TexelWGL::getCurrentReadDeviceContext();
}

EXPORT_API int32_t
wglGetPixelFormat(WGL::DeviceContext deviceContext)
{
    return TexelWGL::getPixelFormat(deviceContext);
}

EXPORT_API void const *
wglGetProcAddress(char const *name)
{
    return TexelWGL::getProcedureAddress(name);
}

EXPORT_API char const *
wglGetExtensionsString(WGL::DeviceContext deviceContext)
{
    return TexelWGL::getExtensionsString(deviceContext);
}

EXPORT_API int32_t
wglMakeCurrent(WGL::DeviceContext deviceContext,
               WGL::ResourceContext resourceContext)
{
    return TexelWGL::makeCurrentContext(deviceContext,
                                        resourceContext);
}

EXPORT_API int32_t
wglSetPixelFormat(WGL::DeviceContext deviceContext,
                  int32_t pixelFormat,
                  WGL::PixelFormatDescriptor *pixelFormatDescriptor)
{
    return TexelWGL::setPixelFormat(deviceContext,
                                    pixelFormat,
                                    pixelFormatDescriptor);
}

EXPORT_API int32_t
wglShareLists(WGL::ResourceContext source,
              WGL::ResourceContext destination)
{
    return TexelWGL::shareLists(source,
                                destination);
}

EXPORT_API int32_t
wglSwapBuffers(WGL::DeviceContext deviceContext)
{
    return TexelWGL::swapBuffers(deviceContext);
}

EXPORT_API int32_t
wglSwapLayerBuffers(WGL::DeviceContext deviceContext,
                    int32_t layer)
{
    return TexelWGL::swapLayerBuffers(deviceContext,
                                      layer);
}