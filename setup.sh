sudo apt-get update && sudo apt-get upgrade -y
sudo apt install cmake
sudo apt install gcc
sudo apt install qtbase5-dev -y
sudo apt install qtdeclarative5-dev -y


CV_VERSION="69357b1e88680658a07cffde7678a4d697469f03"

## Download OpenCV code
printf "Downloading OpenCV ..."
if [ ! -d "opencv_src" ]; then
  printf "\n"
  wget "https://github.com/opencv/opencv/archive/$CV_VERSION.zip" || exit 1
  unzip -q $CV_VERSION
  mv "opencv-$CV_VERSION" opencv_src
else
  printf " skipped\n"
fi

## Build OpenCV
printf "Building OpenCV ..."
if [ ! -d "opencv_build" ]; then
  printf "\n"
  mkdir -p opencv_build
  cd opencv_build
  cmake -D WITH_QT=ON -DCMAKE_BUILD_TYPE=Release ../opencv_src || exit 1
  make || exit 1
  cd ..
else
  printf " skipped\n"
fi

