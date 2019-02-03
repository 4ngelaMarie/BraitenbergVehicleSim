#ifndef LAB03_POINT2_CLASSES_H_
#define LAB03_POINT2_CLASSES_H_

class Point2 {
  public:
    Point2(float x = 0.0, float y = 0.0); //default sets to zero if no input
	float DistanceBetween(Point2 cluster);
	int Quadrant();
	void Print();
  private:
    float position_[2];
  };
#endif /* LAB03_POINT2_CLASSES_H_ */
