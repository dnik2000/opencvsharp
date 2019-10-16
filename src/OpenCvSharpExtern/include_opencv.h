#ifndef _INCLUDE_OPENCV_H_
#define _INCLUDE_OPENCV_H_

//#define ENABLED_CONTRIB
//#undef ENABLED_CONTRIB

#ifdef _MSC_VER
#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(push)
#pragma warning(disable: 4251)
#pragma warning(disable: 4996)
#endif

#define OPENCV_TRAITS_ENABLE_DEPRECATED

#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/shape.hpp>
#include <opencv2/superres.hpp>
#include <opencv2/superres/optical_flow.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/video.hpp>

// opencv_contrib
#ifndef WITHOUT_ARUCO
#include <opencv2/aruco.hpp>
#endif //WITHOUT_ARUCO
#include <opencv2/bgsegm.hpp>
#ifndef WITHOUT_DNN
#include <opencv2/dnn.hpp>
#endif //WITHOUT_DNN
#ifndef WITHOUT_FACE
#include <opencv2/face.hpp>
#endif //WITHOUT_FACE
#include <opencv2/img_hash.hpp>
#include <opencv2/optflow.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/ximgproc.hpp>
#ifndef WITHOUT_XPHOTO
#include <opencv2/xphoto.hpp>
#endif 
#ifndef WITHOUT_TEXT
#include <opencv2/text.hpp>
#endif
#ifndef WITHOUT_QUALITY
#include <opencv2/quality.hpp>
#endif

#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

// Additional types
#include "my_types.h"

// Additional functions
#include "my_functions.h"

#endif
