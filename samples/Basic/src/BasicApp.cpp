#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Capture.h"

#include "CinderOpenCV.h"
#include "ciFaceTrackerThreaded.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicApp : public App {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    ciFaceTrackerThreaded   tracker;
    CaptureRef              cam;
    gl::TextureRef          tex;
};

void BasicApp::setup()
{
    tracker.setup();
    
    cam = Capture::create( getWindowWidth(), getWindowHeight() );
    cam->start();
}

void BasicApp::mouseDown( MouseEvent event )
{
}

void BasicApp::update()
{
    if (cam->checkNewFrame()) {
        Surface8uRef surface = cam->getSurface();
        if (surface)
        {
            tex = gl::Texture::create(*surface);
            tracker.update( toOcv(*surface) );
        }
    }
}

void BasicApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    gl::color( Color::white() );
    
    if (tex) gl::draw( tex );
    tracker.draw();
}

CINDER_APP( BasicApp, RendererGl )
