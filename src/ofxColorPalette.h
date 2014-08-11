#include <limits>
#include "ofColor.h"

template<typename PixelType>
class ofxColorPalette_ {
    
public:
    ofxColorPalette_<PixelType>();
    ofxColorPalette_<PixelType>(ofColor_<PixelType> baseColor);
    ~ofxColorPalette_<PixelType>();
    
    // Sets the Base Color for the Generators
    void setBaseColor(ofColor_<PixelType> col);

    //### Generators
    void inline initGen();
    
    /// \brief generates random colors
    void generateRandom(int numColors=4);
    
    /// \brief generates a monochromatic color palette
    /// for now the base color is the brightest in the palette
    void generateMonoChromatic(int numColors = 4);
    
    /// \brief generates a palette with the complementary of the base color
    /// generates a palette of just 2 colors
    void generateComplementary();
    
    /// \brief generates 3 colors evenly distributed
    void generateTriad();
    
    /// \brief generates a palette with the complementary triad
    /// generates a palette of 3 colors
    /// see http://en.wikipedia.org/wiki/Color_scheme#Split-Complementary for description
    void generateComplementaryTriad(float spread = 0.2);
    
    /// \brief generates a palette of analogous colors
    /// \param numColors the number of Colors which should be generated
    /// \param spread the area (between 0-1) in which the hue is expanded
    void generateAnalogous(int numColors = 5, float spread = 0.2);
    
    //### Operator overloading
    const ofColor_<PixelType> & operator [] (int n) const;
    ofColor_<PixelType> & operator [] (int n);
    
    /// \brief returns the size of the palette
    int size();
    
private:
    ofColor_<PixelType> _baseColor;
    vector<ofColor_<PixelType> > _palette;
    
    // used to "wrap around" float values (1.27 becomes 0.27, -0.3 becomes 0.7)
    float normalizeValue(float val);
};

typedef ofxColorPalette_<unsigned char> ofxColorPalette;
typedef ofxColorPalette_<unsigned short> ofxShortColorPalette;
typedef ofxColorPalette_<float> ofxFloatColorPalette;