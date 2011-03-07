/**************************************************************************************/
/*                                                                                    */
/*  Visualization Library                                                             */
/*  http://www.visualizationlibrary.com                                               */
/*                                                                                    */
/*  Copyright (c) 2005-2010, Michele Bosi                                             */
/*  All rights reserved.                                                              */
/*                                                                                    */
/*  Redistribution and use in source and binary forms, with or without modification,  */
/*  are permitted provided that the following conditions are met:                     */
/*                                                                                    */
/*  - Redistributions of source code must retain the above copyright notice, this     */
/*  list of conditions and the following disclaimer.                                  */
/*                                                                                    */
/*  - Redistributions in binary form must reproduce the above copyright notice, this  */
/*  list of conditions and the following disclaimer in the documentation and/or       */
/*  other materials provided with the distribution.                                   */
/*                                                                                    */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND   */
/*  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED     */
/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE            */
/*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR  */
/*  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    */
/*  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      */
/*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON    */
/*  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT           */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS     */
/*  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                      */
/*                                                                                    */
/**************************************************************************************/

#include "BaseDemo.hpp"
#include <vlGraphics/Effect.hpp>
#include <vlGraphics/Geometry.hpp>
#include <vlGraphics/GLSL.hpp>
#include <vlGraphics/Light.hpp>

class App_TessellationShader: public BaseDemo
{
public:
  void initEvent()
  {
    BaseDemo::initEvent();

    // hemisphere base geometry
    vl::ref< vl::Geometry > geom = new vl::Geometry;

    // hemisphere base geometry vertices
    vl::ref<vl::ArrayFloat3 > verts = new vl::ArrayFloat3;
    verts->resize(12);

    verts->at(0)  = vl::fvec3(1,0,0);
    verts->at(1)  = vl::fvec3(0,1,0);
    verts->at(2)  = vl::fvec3(0,0,1);
    
    verts->at(3)  = vl::fvec3(1,0,0);
    verts->at(4)  = vl::fvec3(0,0,-1);
    verts->at(5)  = vl::fvec3(0,1,0);
    
    verts->at(6)  = vl::fvec3(0,0,-1);
    verts->at(7)  = vl::fvec3(-1,0,0);
    verts->at(8)  = vl::fvec3(0,1,0);
    
    verts->at(9)  = vl::fvec3(-1,0,0);
    verts->at(10) = vl::fvec3(0,0,1);
    verts->at(11) = vl::fvec3(0,1,0);
    
    // hemisphere base geometry vertex colors
    vl::ref<vl::ArrayFloat3 > cols = new vl::ArrayFloat3;
    cols->resize(12);

    cols->at(0)  = vl::fvec3(1,0,0);
    cols->at(1)  = vl::fvec3(1,0,0);
    cols->at(2)  = vl::fvec3(1,0,0);
    
    cols->at(3)  = vl::fvec3(0,1,0);
    cols->at(4)  = vl::fvec3(0,1,0);
    cols->at(5)  = vl::fvec3(0,1,0);
    
    cols->at(6)  = vl::fvec3(1,1,0);
    cols->at(7)  = vl::fvec3(1,1,0);
    cols->at(8)  = vl::fvec3(1,1,0);
    
    cols->at(9)  = vl::fvec3(0,0,1);
    cols->at(10) = vl::fvec3(0,0,1);
    cols->at(11) = vl::fvec3(0,0,1);
    
    // vertex array
    geom->setVertexArray( verts.get() );

    // color array
    geom->setColorArray( cols.get() );
    
    // draw call
    vl::ref< vl::DrawArrays> da = new vl::DrawArrays(vl::PT_PATCHES, 0, verts->size());
    geom->drawCalls()->push_back(da.get());
    
    // patch parameter associated to the draw call
    vl::ref<vl::PatchParameter> patch_param = new vl::PatchParameter;
    patch_param->setPatchVertices(3);
    da->setPatchParameter( patch_param.get() );

    // effect: light + depth testing
    vl::ref<vl::Effect> fx = new vl::Effect;
    fx->shader()->enable(vl::EN_DEPTH_TEST);
    fx->shader()->setRenderState( new vl::Light(0) );

    // bind all the necessary stages to the GLSLProgram
    mGLSL = fx->shader()->gocGLSLProgram();
    mGLSL->attachShader( new vl::GLSLVertexShader("glsl/smooth_triangle.vs") );
    mGLSL->attachShader( new vl::GLSLTessControlShader("glsl/smooth_triangle.tcs") );
    mGLSL->attachShader( new vl::GLSLTessEvaluationShader("glsl/smooth_triangle.tes") );
    mGLSL->attachShader( new vl::GLSLGeometryShader("glsl/smooth_triangle.gs") );
    mGLSL->gocUniform("Outer")->setUniform(10.0f);
    mGLSL->gocUniform("Inner")->setUniform(10.0f);
    mGLSL->gocUniform("Radius")->setUniform(1.0f);

    sceneManager()->tree()->addActor( geom.get(), fx.get(), NULL );
  }

  // interactively change the inner/outer tessellation levels
  void keyPressEvent(unsigned short, vl::EKey key)
  {
    float outer = 0;
    float inner = 0;
    mGLSL->gocUniform("Outer")->getUniform(&outer);
    mGLSL->gocUniform("Inner")->getUniform(&inner);

    if (key == vl::Key_Left)
      outer--;
    else
    if (key == vl::Key_Right)
      outer++;
    else
    if (key == vl::Key_Down)
      inner--;
    else
    if (key == vl::Key_Up)
      inner++;

    inner = inner < 1 ? 1 : inner;
    outer = outer < 1 ? 1 : outer;

    mGLSL->gocUniform("Outer")->setUniform(outer);
    mGLSL->gocUniform("Inner")->setUniform(inner);

    vl::Log::print( vl::Say("outer = %n, inner = %n\n") << outer << inner );
  }

protected:
  vl::GLSLProgram* mGLSL;
};

// Have fun!

BaseDemo* Create_App_TessellationShader() { return new App_TessellationShader; }
