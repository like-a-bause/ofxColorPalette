#include "ofMain.h"

#include "ofxColorPalette.h"

template<typename PixelType>
ofxColorPalette_<PixelType>::ofxColorPalette_(): _baseColor(ofColor_<PixelType>::limit(),ofColor_<PixelType>::limit(),ofColor_<PixelType>::limit()){}

template<typename PixelType>
ofxColorPalette_<PixelType>::ofxColorPalette_(ofColor_<PixelType> baseColor) : _baseColor(baseColor)
{
}

template<typename PixelType>
ofxColorPalette_<PixelType>::~ofxColorPalette_(){}

template<typename PixelType>
void ofxColorPalette_<PixelType>::setBaseColor(ofColor_<PixelType> col)
{
    _baseColor = col;
}


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

// # Complementary
template<typename PixelType>
void ofxColorPalette_<PixelType>::generateComplementary(int numColors, ColorChannel channel)
{
    initGen();
        //hack only even numbers allowed, otherwise the code will bloat out.
    if (numColors % 2 == 1) {
        numColors -= 1;
    }
    float value;
    switch (channel) {
        case SATURATION:
            value = _baseColor.getSaturation();
            break;
        case BRIGHTNESS:
            value = _baseColor.getBrightness();
            break;
        default:
            break;
    }
    // base is again brightest for now, second enum to define the "direction" {toBlack to White}?
    int numLeft = numColors/2;
    float stepSize = (2 * value) / numColors;
    for (int i = 1; i < numLeft; i++) {
        value -= stepSize;
        switch (channel) {
            case SATURATION:
                 _palette.push_back(ofColor_<PixelType>::fromHsb(_baseColor.getHue(),value,_baseColor.getBrightness()));
                break;
            case BRIGHTNESS:
                _palette.push_back(ofColor_<PixelType>::fromHsb(_baseColor.getHue(),_baseColor.getSaturation(),value));
                break;
            default:
                break;
        }
       
    }
    
    ofColor_<PixelType> complement = _baseColor.invert();
    for (int i = 1; i < numColors - numLeft; i++) {
        switch (channel) {
            case SATURATION:
                _palette.push_back(ofColor_<PixelType>::fromHsb(complement.getHue(),value,complement.getBrightness()));
                break;
            case BRIGHTNESS:
                _palette.push_back(ofColor_<PixelType>::fromHsb(complement.getHue(),complement.getSaturation(),value));
                break;
            default:
                break;
        }
        value += stepSize;
        
    }
    _palette.push_back(complement);
    
}

// # Triad
template<typename PixelType>
void ofxColorPalette_<PixelType>::generateTriad()
{
    initGen();
    float hue = _baseColor.getHue();
    float stepSize = ofColor_<PixelType>::limit()/3;
    _palette.push_back(ofColor_<PixelType>::fromHsb(normalizeValue(hue + stepSize),_baseColor.getSaturation(),_baseColor.getBrightness()));
    _palette.push_back(ofColor_<PixelType>::fromHsb(normalizeValue(hue +  2 * stepSize),_baseColor.getSaturation(),_baseColor.getBrightness()));
}

// # Complementary Triad
template<typename PixelType>
void ofxColorPalette_<PixelType>::generateComplementaryTriad(float spread)
{
    initGen();
    ofColor_<PixelType> complement = _baseColor.invert();
    float hue = complement.getHue();
    spread = spread * ofColor_<PixelType>::limit();
    _palette.push_back(ofColor_<PixelType>::fromHsb(normalizeValue(hue - spread),complement.getSaturation(),complement.getBrightness()));
    _palette.push_back(ofColor_<PixelType>::fromHsb(normalizeValue(hue + spread),complement.getSaturation(),complement.getBrightness()));
}

// # Analogous
template<typename PixelType>
void ofxColorPalette_<PixelType>::generateAnalogous(int numColors, float spread)
{
    //TODO Maybe the base Color should be in the middle here.
    
    initGen();
    float hue = _baseColor.getHue(); //between 0 and limit()
    float stepSize = spread / numColors;// distribute the colors accross range
    stepSize = stepSize * ofColor_<PixelType>::limit(); // scale to PixelType
    numColors -=1;
    
    int numLeft = numColors / 2;
    //fill in left colors
    float newHue;
    for (int i = 1; i <= numLeft ; i++) {
        newHue = normalizeValue(hue - i * stepSize);
        _palette.push_back(ofColor_<PixelType>::fromHsb(newHue,_baseColor.getSaturation(),_baseColor.getBrightness()));
    }
    //fill in right colors
    for (int i = 1; i <= numColors- numLeft; i++) {
        newHue = normalizeValue(hue + i * stepSize);
        _palette.push_back(ofColor_<PixelType>::fromHsb(newHue,_baseColor.getSaturation(),_baseColor.getBrightness()));
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
template<typename PixelType>
int ofxColorPalette_<PixelType>::size()
{
    return _palette.size();
}

template<typename PixelType>
float ofxColorPalette_<PixelType>::normalizeValue(float val)
{
    float limit = ofColor_<PixelType>::limit();
    if(val > limit)
    {
        return val - limit;
    } else if(val < 0)
    {
        return limit + val;
    } else
    {
        return val;
    }
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