sudo apt-get update && sudo apt-get upgrade -y
sudo apt install cmake gcc qtbase5-dev qtdeclarative5-dev qt5-default libgtest-dev -y



#Build or install OpenCV
OS="$(uname -a)"

case $OS  in
    *"armv7"*)
        wget "https://github.com/albanjoseph/Signapse/releases/download/v2.0-beta/OpenCV-27b5305-armv7l-dev.deb"
        sudo apt install ./OpenCV-27b5305-armv7l-dev.deb
        ;;
    *"x86"*)
        wget "https://github.com/albanjoseph/Signapse/releases/download/v2.0-beta/OpenCV-016a578-x86_64-dev.deb"
        sudo apt install ./opencv-4.5.1_x86.deb
        ;;
          *)
        printf "Can't download built version, Building OpenCV from source ..."
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
          cmake -D WITH_QT=ON -DCMAKE_BUILD_TYPE=Release ../opencv_src || exit 1
          make || exit 1
          cd ..
        else
          printf " skipped\n"
        fi
esac


