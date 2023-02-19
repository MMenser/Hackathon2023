
#include "RoutePlanner.hpp"
#include "ImageProcessor.hpp"
    
//http://www.partow.net/programming/bitmap/index.html#simpleexample01
    
ImageProcessor::ImageProcessor(int width, int height)
{
    //Create a blank image.
    bitmap_image newImage(width,height);
    newImage.set_all_channels(0, 0, 0);
    image = newImage;
}

ImageProcessor::ImageProcessor(bitmap_image& newImage)
{
    image = newImage;
}

ImageProcessor::ImageProcessor(ImageProcessor& copy)
{
     image = copy.image;
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
void ImageProcessor::plotStarLocations(size_t color)
{
    //TODO: do this
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