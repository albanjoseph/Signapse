mkdir build
cd build
cmake ..
make Signapse
make taskmaster_test
make camera_test
make inference_test