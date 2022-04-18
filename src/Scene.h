#ifndef SIGNAPSE_SCENE_H
#define SIGNAPSE_SCENE_H


#include <opencv2/core.hpp>

//! Struct Point
/*!
 * Data structure hold point information for integer points
 */
struct Point
{
    int x, y;
    Point() : x(0), y(0) {}
    Point(const Point& cpy) : x(cpy.x), y(cpy.y) {}
    Point(int x, int y) : x(x), y(y) {}
};

//! Struct BoundingBox
/*!
 * Data structure holds bounding box point information for a rectangle in image space.
 */
struct BoundingBox{
    Point UpperLeft;
    Point LowerRight;
    BoundingBox():UpperLeft(), LowerRight(){}
    BoundingBox(int upperLeftX, int upperLeftY, int lowerRightX, int lowerRightY): UpperLeft(upperLeftX, upperLeftY),
                                                                                   LowerRight(lowerRightX, lowerRightY) {}
    BoundingBox(Point upperLeft, Point lowerRight): UpperLeft(upperLeft), LowerRight(lowerRight) {}
};

//! Struct Scene.
/*!
    Holds the video frame data and additional Signapse metadata.
*/
struct Scene{
    Scene(){}
    //! Member variable.
    /*!
        OpenCV n-dimensional dense array object.
    */
    cv::Mat frame;
    //! Member variable.
    /*!
        A string representing the predicted output from processing with a CNN model.
    */
    std::string result = "";
    //! Member variable
    /*!
        Region of the frame which frames the user's hand or sign, used to allow cropping for further processing. Variable contains 4 integers, the first two represent the upper-left bounding box coord with the second two representing lower-right. Coordinates are in (column,row) format, units are in pixels.
     */
     BoundingBox regionOfInterest;
};

#endif