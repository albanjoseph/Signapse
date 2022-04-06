//
// Created by adam on 09/02/2022.
//
#include <opencv2/core.hpp>
#ifndef SIGNAPSE_SCENE_H
#define SIGNAPSE_SCENE_H

//! Struct Scene.
/*!
    Holds the video frame data and additional Signapse metadata.
*/
struct Scene{
    //! Member variable.
    /*!
        OpenCV n-dimensional dense array object.
    */
    cv::Mat frame;
    //! Member variable.
    /*!
        Holds timestamp of when the Scene was created by Populate.
    */
    int timestamp;
    //! Member variable.
    /*!
        A string representing the predicted output from processing with a CNN model.
    */
    std::string result;
    //! Member variable
    /*!
        Region of the frame which frames the user's hand or sign, used to allow cropping for further processing. Variable contains 4 integers, the first two represent the upper-left bounding box coord with the second two representing lower-right. Coordinates are in (column,row) format, units are in pixels.
     */
     int regionOfInterest[4];
};

#endif //SIGNAPSE_SCENE_H