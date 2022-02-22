//
// Created by adam on 09/02/2022.
//

#ifndef SIGNAPSE_CAMERA_H
#define SIGNAPSE_CAMERA_H
#include "reel.h"
#include <opencv2/videoio.hpp>
#include <thread>

//!  Camera class which inherits from Reel.
/*!
    Class for reading web cam data, and creating a reel of scenes.
*/
class Camera: public Reel{
public:
    //! Constructor.
    /*!
        Turns the camera object "ON" and configures the video capture.
    */
    Camera();
    //! Member function.
    /*!
        Reads webcam data, populates a Scene struct and pushes scene on to sceneQueue.
    */
    void Populate();
    //! Member function for setting new signing task.
    /*!
        Updates currentTask with new_task
    */
    void set_current_task(char new_task);
    //! Member function for starting video capturing thread.
    /*!
        Starts "Stream" private member function as a thread.
    */
    void start_thread();

private:
    //! Private member function.
    /*!
        Calls "Populate" member function whilst the camera object is "ON"
    */
    void Stream();
    //! Private member variable.
    /*!
        Holds the value of the current signing task.
    */
    char currentTask;
    //! Private member object.
    /*!
        OpenCV object for reading web cam data.
    */
    cv::VideoCapture videoCapture;
    //! Private member variable containing web cam device ID.
    /*!
        0 = open default camera
        
    */
    int deviceID = 0;
    //! Private member variable containing web cam API ID.
    /*!
        0 = autodetect default API
    */
    int apiID = cv::CAP_ANY;
    //! Private member thread
    std::thread cameraThread;
    //! Private member variable containing camera object status.
    /*!
        false = Camera is off.
        true = Camera is on.
    */
    bool isOn = true;
};


#endif //SIGNAPSE_CAMERA_H
