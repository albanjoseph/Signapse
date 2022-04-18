sudo apt install cmake gcc qtbase5-dev qtdeclarative5-dev qt5-default libgtest-dev -y

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
if [ ! -d "opencv_build" ]; then
  printf "\n"
  mkdir -p opencv_build
  cd opencv_build
  #install with only the nessessary packages - reduces build time
  cmake -DBUILD_LIST=dnn,improc,videoio, -DCMAKE_BUILD_TYPE=Release ../opencv_src || exit 1
  #set make jobs to 4 - reduces build time
  make -j4 || exit 1
  cd ..
else
  printf " skipped\n"
fi


