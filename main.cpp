
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"


//Currently only used for testing purposes (on this branch)
int main(void)
{
  bitmap_image newImage(200,200);

  ImageProcessor imgProcessor(newImage);

  rgb_t color;
  color.red = 100;
  color.green = 0;
  color.blue = 0;

  imgProcessor.drawCircleAtPoint(100,100, 20, color);

  imgProcessor.image.save_image("test.bmp");
}
