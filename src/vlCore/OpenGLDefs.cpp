#include <vlCore/OpenGLDefs.hpp>
#include <vlCore/String.hpp>
#include <vlCore/Log.hpp>
#include <vlCore/Say.hpp>

int vl::glcheck(const char* file, int line)
{
  unsigned int glerr = glGetError();
  if (glerr != GL_NO_ERROR)
  {
    String msg( (char*)gluErrorString(glerr) );
    Log::bug( Say("glGetError() [%s:%n]: %s\n") << file << line << msg );
  }
  return glerr;
}
//------------------------------------------------------------------------------
