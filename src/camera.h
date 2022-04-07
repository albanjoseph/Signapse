#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

#include "SceneLinker.h"


//!  Camera class which inherits from Reel.
/*!
    Class for reading web cam data, and creating a Reel of scenes.
*/
class Camera: public SceneLinker{
public:
    //! Constructor.
    /*!
        Turns the camera object "ON" and configures the video capture.
    */
    Camera();
    bool getOn();

    void setOn(bool state);
    
    //! Member function for starting video capturing thread.
    /*!
        Starts "Stream" private member function as a thread.
    */
    void start_thread();
    
    
    
private:
    void postFrame();

    void threadLoop();
    
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
    bool isOn = false;
};
