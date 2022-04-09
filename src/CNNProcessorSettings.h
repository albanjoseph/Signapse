#include <stdio.h>
#include "SignapseUtils.h"

#define MOBNET_V2_INPUT_DIM_X 224
#define MOBNET_V2_INPUT_DIM_Y 224
#define MOBNET_V2_PATH "models/asl-mobilenetv2.pb"

struct CNNProcessorSettings {
    CNNProcessorSettings(std::string network = "mobnetv2"){
        if(network == "mobnetv2") {
            ModelPath = MOBNET_V2_PATH;
            InputDim_x = MOBNET_V2_INPUT_DIM_X;
            InputDim_y = MOBNET_V2_INPUT_DIM_Y;
        }
        else{
            ; //space for more default network setups
        }
    }
    std::string ModelPath = "";
    int InputDim_x = 0;
    int InputDim_y = 0;
};


