#include "ofxColorPalette.h"

template<typename PixelType>
ofxColorPalette_<PixelType>::ofxColorPalette_(): _baseColor(ofColor_<PixelType>::limit(),ofColor_<PixelType>::limit(),ofColor_<PixelType>::limit()){}

template<typename PixelType>
ofxColorPalette_<PixelType>::ofxColorPalette_(ofColor_<PixelType> baseColor) : _baseColor(baseColor)
{
}

template<typename PixelType>
ofxColorPalette_<PixelType>::~ofxColorPalette_(){}


// ### Generators
template<typename PixelType>
void inline ofxColorPalette_<PixelType>::initGen(){
    _palette.clear();
    _palette.push_back(_baseColor);
}

// # Random
template<typename PixelType>
void ofxColorPalette_<PixelType>::generateRandom(int numColors)
{
    initGen();
    for(int i = 0; i < numColors -1; i++)
    {
        _palette.push_back(ofColor_<PixelType>(ofRandom(_baseColor.limit()),ofRandom(_baseColor.limit()),ofRandom(_baseColor.limit())));
    }
}

// # Monochromatic
template<typename PixelType>
void ofxColorPalette_<PixelType>::generateMonoChromatic(int numColors)
{
    initGen();
    
    //The base Color is the brightest of the generated
    PixelType b = _baseColor.getBrightness();
    float steps = b / numColors;
    for (int i = 1; i < numColors; i++) {
        _palette.push_back(ofColor_<PixelType>::fromHsb(_baseColor.getHue(),_baseColor.getSaturation(), b - i*steps));
    }
}

template<typename PixelType>
const ofColor_<PixelType> & ofxColorPalette_<PixelType>::operator [] (int n) const{
	return _palette[n];
}

template<typename PixelType>
ofColor_<PixelType> & ofxColorPalette_<PixelType>::operator [] (int n){
	return _palette[n];
}

template class ofxColorPalette_<char>;
template class ofxColorPalette_<unsigned char>;
template class ofxColorPalette_<short>;
template class ofxColorPalette_<unsigned short>;
template class ofxColorPalette_<int>;
template class ofxColorPalette_<unsigned int>;
template class ofxColorPalette_<long>;
template class ofxColorPalette_<unsigned long>;
template class ofxColorPalette_<float>;
template class ofxColorPalette_<double>;