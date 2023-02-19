//
#include "RoutePlanner.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"

//Draw a dot at a certain point.

class ImageProcessor
{
public:
    bitmap_image image;
    
    double lightyearsPerPixel;

    //Color templates
    rgb_t white;
    rgb_t gray;
    rgb_t black;

    //Constructors
    ImageProcessor();
    ImageProcessor(int pixel_width, int pixel_height);
    ImageProcessor(bitmap_image& image);
    ImageProcessor(ImageProcessor& copy);

    void getColorTemplates();
    
    void getLightyearsPerPixel();

    //Paints Horizontal and Vertical gridlines, alligning at the origin.
    void plotSquareGrid(rgb_t color);

    //Paints radial gridlines, eminating from the origin.
    void plotRadialGrid(size_t color);

    //Marks every star location as a colored point on the image.
    void plotStarLocations(Star stars[], int numStars, int radius, rgb_t color);

    //Colors everything within radius r of the given point.
    void drawCircleAtPoint(int x, int y, int radius, rgb_t color);
};

