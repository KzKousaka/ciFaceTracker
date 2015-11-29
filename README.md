# ciFaceTracker

ciFaceTracker is a port of [Kyle McDonald](https://github.com/kylemcdonald)'s ofxFaceTracker, which is based on Jason Saragih's FaceTracker library.

See [ofxFaceTracer on GitHub](https://github.com/kylemcdonald/ofxFaceTracker)

The model file paths ("face2.tracker", etc) are pulled from the package contents using:  
`path tBasePath = path( ci::app::getAssetPath("model") );`

## Topic

### Suported [Cinder v0.9.0](https://github.com/cinder/Cinder)
OpenCV is not equipped with a standard to v0.9.0.  
So you need to include the [Cinder-OpenCV3](https://github.com/cinder/Cinder-OpenCV3) in blocks.  

## Todo:
- Test Expression and ExpressionClassifier file loading and saving. Should be implemented now, haven't had time to test yet. 
