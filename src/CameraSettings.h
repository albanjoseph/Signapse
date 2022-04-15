#ifndef SIGNAPSE_CAMERASETTINGS_H
#define SIGNAPSE_CAMERASETTINGS_H



struct CameraSettings{
    CameraSettings(int dID=0){
        deviceID = dID;
    }
    CameraSettings(const CameraSettings& cpy){
        deviceID = cpy.deviceID;
        apiID = cpy.apiID;
    }
    /*!
     * Member containing device ID, may be modified via the constructor; assigned to 0 by default
     */
    int deviceID = 0;
    //! Member variable containing web cam API ID.
    /*!
        0 = autodetect default API
    */
    int apiID = 0;
};

#endif //SIGNAPSE_CAMERASETTINGS_H
