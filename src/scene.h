//
// Created by adam on 09/02/2022.
//
#include <opencv2/core.hpp>
#ifndef SIGNAPSE_SCENE_H
#define SIGNAPSE_SCENE_H
//! Struct Result.
/*!
    Holds the values of a sign and its associated confidence level.
*/
struct Result{
    //! Member variable.
    /*!
        Holds the value of the sign of the Result.
    */
    char sign;
    //! Member variable.
    /*!
        Holds the value of the confidence of the Result.
    */
    int conf;
};
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
        Holds the value of the signing task the Scene corresponds with.
    */
    char task;
    //! Member variable.
    /*!
        An array of Result corresponding with the top 10 confidence levels from the output of CNNProcessor.
    */
    Result result[10];
    //! Member variable
    /*!
        Region of the frame which frames the user's hand or sign, used to allow cropping for further processing. Variable contains 4 integers, the first two represent the upper-left bounding box coord with the second two representing lower-right. Coordinates are in column,row format.
     */
     int regionOfInterest[4];
};

#endif //SIGNAPSE_SCENE_H