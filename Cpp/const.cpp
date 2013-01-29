
#include <iostream>
using namespace std;

class test
{
  public:
    double length;
    double breadth;
    double height;

    // Inline initialization
    test(double lv = 1.0, double bv = 1.0, double hv = 1.0):length(lv),
                                                           breadth(bv),
                                                           height(hv)
    {
      cout << "test constructor called" << endl;
    }

    // Function to calculate the volume of a test
    double volume()
    {
      return length * breadth * height;
    }
};

int main()
{
  test firsttest(213.9, 522.29, 342.21);

  // Calculate the volume of the test
  double firsttestVolume = firsttest.volume();
  cout << endl;
  cout << "Size of first test object is "
       << firsttest.length  << " by "
       << firsttest.breadth << " by "
	<< firsttest.height
       << endl;
  cout << "Volume of first test object is " << firsttestVolume
       << endl;

  return 0;
}
