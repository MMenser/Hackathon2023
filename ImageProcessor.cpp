
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

//Calculates a workable ratio for light years to pixels.
void ImageProcessor::getLightyearsPerPixel(struct Star stars[], int numStars)
{
    double min_x = stars[0].gal_x, max_x = min_x,
           min_y = stars[0].gal_y, max_y = min_y;

    //Find the largest and smallest x and y values.
    for (int i = 1; i < numStars; i++)
    {
        if (stars[i].gal_x > max_x)
        {
            max_x = stars[i].gal_x;
        } 
        else if (stars[i].gal_x < min_x)
        {
            min_x = stars[i].gal_x;
        }
        if (stars[i].gal_y > max_y)
        {
            max_x = stars[i].gal_y;
        } 
        else if (stars[i].gal_y < min_y)
        {
            min_x = stars[i].gal_y;
        }
    }

    //Scale the lightyear-pixel ration based on the range of coordinate values.
    
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