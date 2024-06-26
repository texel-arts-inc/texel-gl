#include "Entrypoints.h"
#include "GLXEntrypoints.h"

EXPORT_API XVisualInfo *
glXChooseVisual(Display *display,
                int32_t screen,
                int32_t *attribList)
{
    return nullptr;
}

EXPORT_API GLXContext
glXCreateContext(Display *display,
                 XVisualInfo *vis,
                 GLXContext shareList,
                 bool direct)
{
    return nullptr;
}

EXPORT_API void
glXDestroyContext(Display *display,
                  GLXContext ctx)
{
}

EXPORT_API bool
glXMakeCurrent(Display *display,
               GLXDrawable drawable,
			   GLXContext ctx)
{
    return false;
}

EXPORT_API void
glXCopyContext(Display *display,
               GLXContext src,
               GLXContext dst,
			   uint64_t mask)
{
}

EXPORT_API void
glXSwapBuffers(Display *display,
               GLXDrawable drawable)
{
}

EXPORT_API GLXPixmap
glXCreateGLXPixmap(Display *display,
                   XVisualInfo *visual,
				   Pixmap pixmap)
{
    return nullptr;
}

EXPORT_API void
glXDestroyGLXPixmap(Display *display,
                    GLXPixmap pixmap)
{
}

EXPORT_API bool
glXQueryExtension(Display *display,
                  int32_t *errorb,
                  int32_t *event)
{
    return false;
}

EXPORT_API bool
glXQueryVersion(Display *display,
                int32_t *maj,
                int32_t *min)
{
    return false;
}

EXPORT_API bool
glXIsDirect(Display *display,
            GLXContext ctx)
{
    return false;
}

EXPORT_API int
glXGetConfig(Display *display,
             XVisualInfo *visual,
			 int32_t attrib,
             int32_t *value)
{
    return 0;
}

EXPORT_API GLXContext
glXGetCurrentContext(void)
{
    return nullptr;
}

EXPORT_API GLXDrawable
glXGetCurrentDrawable(void)
{
    return nullptr;
}

EXPORT_API void
glXWaitGL(void)
{
}

EXPORT_API void
glXWaitX(void)
{
}

EXPORT_API void
glXUseXFont(Font font,
            int32_t first,
            int32_t count,
            int32_t list)
{
}

EXPORT_API char const *
glXQueryExtensionsString(Display *display,
                         int32_t screen)
{
    return nullptr;
}

EXPORT_API char const *
glXQueryServerString(Display *display,
                     int32_t screen,
                     int32_t name)
{
    return nullptr;
}

EXPORT_API char const *
glXGetClientString(Display *display,
                   int32_t name)
{
    return nullptr;
}

EXPORT_API Display *
glXGetCurrentDisplay(void)
{
    return nullptr;
}

EXPORT_API GLXFBConfig *
glXChooseFBConfig(GLXDisplay *display,
                  int32_t screen,
                  int32_t const *attrib_list,
                  int32_t *numElements)
{
    return nullptr;
}


EXPORT_API int32_t
glXGetFBConfigAttrib(GLXDisplay *display,
                     GLXFBConfig config,
                     int32_t attribute,
                     int32_t *value )
{
    return 0;
}

EXPORT_API GLXFBConfig *
glXGetFBConfigs(GLXDisplay *display,
                int32_t screen,
                int32_t *numElements)
{
    return nullptr;
}

EXPORT_API XVisualInfo *
glXGetVisualFromFBConfig(GLXDisplay *display,
                         GLXFBConfig config)
{
    return nullptr;
}

EXPORT_API GLXWindow
glXCreateWindow(GLXDisplay *display,
                GLXFBConfig config,
                Window win,
                int32_t *attribList)
{
    return nullptr;
}

EXPORT_API void
glXDestroyWindow(GLXDisplay *display,
                 GLXWindow window)
{
}

EXPORT_API GLXPixmap
glXCreatePixmap(GLXDisplay *display,
                GLXFBConfig config,
                Pixmap pixmap,
                int32_t *attribList)
{
    return nullptr;
}

EXPORT_API void
glXDestroyPixmap(GLXDisplay *display,
                 GLXPixmap pixmap )
{
}

EXPORT_API GLXPbuffer
glXCreatePbuffer(GLXDisplay *display,
                 GLXFBConfig config,
                 int32_t const *attribList)
{
    return nullptr;
}

EXPORT_API void
glXDestroyPbuffer(GLXDisplay *display,
                  GLXPbuffer pbuf)
{
}

EXPORT_API void
glXQueryDrawable(GLXDisplay *dpy,
                 GLXDrawable draw,
                 int32_t attribute,
                 uint32_t *value)
{
}

EXPORT_API GLXContext
glXCreateNewContext(GLXDisplay *dpy,
                    GLXFBConfig config,
                    int32_t renderType,
                    GLXContext shareList,
                    bool direct)
{
    return nullptr;
}

EXPORT_API bool
glXMakeContextCurrent(GLXDisplay *dpy,
                      GLXDrawable draw,
                      GLXDrawable read,
                      GLXContext ctx)
{
    return false;
}

EXPORT_API GLXDrawable
glXGetCurrentReadDrawable(void)
{
    return nullptr;
}

EXPORT_API int32_t
glXQueryContext(GLXDisplay *dpy,
                GLXContext ctx,
                int32_t attribute,
                int32_t *value)
{
    return 0;
}

EXPORT_API void
glXSelectEvent(GLXDisplay *dpy,
               GLXDrawable drawable,
               uint64_t mask)
{
}

EXPORT_API void
glXGetSelectedEvent(GLXDisplay *dpy,
                    GLXDrawable drawable,
                    uint64_t *mask)
{
}

EXPORT_API void const *
glXGetProcAddress(char const *name)
{
    return nullptr;
}

EXPORT_API void const *
glXGetProcAddressARB(char const *name)
{
    return glXGetProcAddress(name);
}