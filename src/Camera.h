#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

#include "PipelineLink.h"


/*!
 * Simple Pipeline element which integrates frame acquisition from the camera feed.
 */
class Camera: public PipelineLink{
public:
    Camera();
    ~Camera();
    bool getOn();
    void setOn(bool state);
    void Start();
    void Stop();
    
private:
    void postFrame();
    void threadLoop();
    cv::VideoCapture videoCapture;
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
