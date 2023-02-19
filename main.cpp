
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"


//Currently only used for testing purposes (on this branch)
int main(void)
{ 
  std::cout << "Hello World X" << std::endl;
 
  bitmap_image newImage(200,200);
  
  ImageProcessor ip(200,200);

  rgb_t color;
  color.red = 100; 
  color.green = 0;
  color.blue = 200;

  image_drawer draw(ip.image);
  draw.pen_width(2);
  draw.pen_color(color.red, color.green, color.blue);
  draw.circle(100, 100, 20);
 
  newImage.save_image("test.bmp");

  return 0;
};
