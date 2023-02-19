
#include "RoutePlanner.hpp"
#include "ImageProcessor.hpp"
    
//bitmap_image documentation:
//http://www.partow.net/programming/bitmap/index.html#simpleexample01
    
ImageProcessor::ImageProcessor()
{
    getColorTemplates();
}

ImageProcessor::ImageProcessor(int pixel_width, int pixel_height)
{
    getColorTemplates();

    //Create an all-black image.
    bitmap_image newImage(pixel_width, pixel_height);
    newImage.set_all_channels(0, 0, 0);
    image = newImage;
}

ImageProcessor::ImageProcessor(bitmap_image& newImage)
{
    getColorTemplates();
    image = newImage;
}

ImageProcessor::ImageProcessor(ImageProcessor& copy)
{
    getColorTemplates();
    image = copy.image;
}

void ImageProcessor::getColorTemplates()
{
    white = make_colour(255, 255, 255);
    gray = make_colour(128, 128, 128);
    black = make_colour(0, 0, 0);
}

//Paints Horizontal and Vertical gridlines, alligning at the origin.
void ImageProcessor::plotSquareGrid(rgb_t color)
{
    //TODO: do this
}

//Paints radial gridlines, eminating from the origin.
void ImageProcessor::plotRadialGrid(size_t color)
{
    //TODO: do this
}



//Marks every star location as a colored point on the image.
void ImageProcessor::plotStarLocations(Star stars[], int numStars, int radius, rgb_t color)
{
    //Draws circles with 3 pixel radei.
    for (int i = 0; i < numStars; i++)
    {
        drawCircleAtPoint(stars[i].gal_x, stars[i].gal_y, 3, color);
    }
}

//Colors everything within radius r of the given point.
void ImageProcessor::drawCircleAtPoint(int x, int y, int radius, rgb_t color)
{
    image_drawer draw(image);
    draw.pen_width(2);
    draw.pen_color(color.red, color.green, color.blue);
    
    for (int i = radius; i > 0; i--)
    {
        draw.circle(x, y, i);
    }
} 

double getDistanceInLightYears(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double getDistance(Star& first, Star& second) {
    double x2 = 0.0, y2 = 0.0, z2 = 0.0, distance = 0.0;

    x2 = pow(second.gal_x - first.gal_x, 2);
    y2 = pow(second.gal_y - first.gal_y, 2);
    z2 = pow(second.gal_z - first.gal_z, 2);

    distance = sqrt(x2 + y2 + z2);
    return distance;
}

struct Star getClosestStar(int x, int y, struct Star sortedStars[])
{
    
}