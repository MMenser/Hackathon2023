
#include "ImageProcessor.hpp"
    
//http://www.partow.net/programming/bitmap/index.html#simpleexample01
    
ImageProcessor::ImageProcessor()
{
    //Create a blank image.
    bitmap_image newImage(200,200);
    image.set_all_channels(255, 150, 50);
    
    this->image = newImage;
}

ImageProcessor::ImageProcessor(bitmap_image newImage)
{
    this->image = newImage;
}

ImageProcessor::ImageProcessor(ImageProcessor& copy)
{
     this->image = copy.image;
}

//Paints Horizontal and Vertical gridlines, alligning at the origin.
void plotSquareGrid(int numVertical, int numHorizontal, rgb_t color)
{
    //TODO: do this
}

//Paints radial gridlines, eminating from the origin.
void plotRadialGrid(int numVertical, int numHorizontal, size_t color)
{
    //TODO: do this
}

//Marks every star location as a colored point on the image.
void plotLocations(struct Star starmap[5], size_t color)
{
    //TODO: do this
}

//Colors everything within radius r of the given point.
void ImageProcessor::drawCircleAtPoint(int x, int y, int radius, rgb_t color)
{
    image_drawer draw(image);
    draw.pen_width(2);
    draw.pen_color(color.red, color.green, color.blue);
    draw.circle(x, y, radius);
}