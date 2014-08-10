#include <limits>
#include "ofColor.h"

template<typename PixelType>
class ofxColorPalette_ {
    
public:
    ofxColorPalette_<PixelType>();
    ofxColorPalette_<PixelType>(ofColor_<PixelType> baseColor);
    ~ofxColorPalette_<PixelType>();
    
    // Sets the Base Color for the Generators
    void setBaseColor(ofColor_<PixelType>);

    //### Generators
    void inline initGen();
    void generateRandom(int numColors=4);
    void generateMonoChromatic(int numColors = 4);
    
    const ofColor_<PixelType> & operator [] (int n) const;
    ofColor_<PixelType> & operator [] (int n);
    
private:
    ofColor_<PixelType> _baseColor;
    vector<ofColor_<PixelType> > _palette;    
};

typedef ofxColorPalette_<unsigned char> ofxColorPalette;
typedef ofxColorPalette_<unsigned short> ofxShortColorPalette;
typedef ofxColorPalette_<float> ofxFloatColorPalette;