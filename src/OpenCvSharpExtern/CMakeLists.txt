cmake_minimum_required(VERSION 3.0)

# This options allow to exclude some OpenCv modules from OpenCvSharp
# It helps for custom lightweight builds of OpenCv
# Use this options for your own risk
option(WITH_opencv_aruco "Compile with opencv_aruco module" ON)
option(WITH_opencv_bgsegm "Compile with opencv_bgsegm module" ON)
option(WITH_opencv_dnn "Compile with  opencv_dnn module" ON)
option(WITH_opencv_face "Compile with opencv_face module" ON)
option(WITH_opencv_img_hash "Compile with opencv_img_hash module" ON)
option(WITH_opencv_optflow "Compile with opencv_optflow module" ON)
option(WITH_opencv_tracking "Compile with opencv_tracking module" ON)
option(WITH_opencv_xfeatures2d "Compile with opencv_xfeatures2d module" ON)
option(WITH_opencv_ximgproc "Compile with opencv_ximgproc module" ON)
option(WITH_opencv_ml "Compile with opencv_ml module" ON)
option(WITH_opencv_quality "Compile with opencv_quality module" ON)
option(WITH_opencv_text "Compile with opencv_text module" ON)
option(WITH_opencv_xphoto "Compile with opencv_xphoto module" ON)

find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
	include_directories(${OpenCV_INCLUDE_DIR})
	link_directories(${OpenCV_LIBRARY_DIR} ${OpenCV_LIBRARIES})

	file(GLOB OPENCVSHARP_FILES *.cpp)

	if(NOT WITH_opencv_aruco)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/aruco.cpp$")
	add_definitions(-DWITHOUT_ARUCO)
	message(STATUS "Disable opencv_aruco module")
	endif()
	
	if(NOT WITH_opencv_bgsegm)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/bgsegm.cpp$")
	add_definitions(-DWITHOUT_BGSEGM)
	message(STATUS "Disable opencv_bgsegm module")
	endif()

	if(NOT WITH_opencv_dnn)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/dnn.cpp$")
	add_definitions(-DWITHOUT_DNN)
	message(STATUS "Disable opencv_dnn module")
	endif()

	if(NOT WITH_opencv_face)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/face.cpp$")
	add_definitions(-DWITHOUT_FACE)
	message(STATUS "Disable opencv_face module")
	endif()

	if(NOT WITH_opencv_img_hash)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/img_hash.cpp$")
	add_definitions(-DWITHOUT_IMG_HASH)
	message(STATUS "Disable opencv_img_hash module")
	endif()

	if(NOT WITH_opencv_optflow)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/optflow.cpp$")
	add_definitions(-DWITHOUT_OPTFLOW)
	message(STATUS "Disable opencv_optfow module")
	endif()

	if(NOT WITH_opencv_tracking)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/tracking.cpp$")
	add_definitions(-DWITHOUT_TRACKING)
	message(STATUS "Disable opencv_tracking module")
	endif()

	if(NOT WITH_opencv_xfeatures2d)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/xfeatures2d.cpp$")
	add_definitions(-DWITHOUT_XFEATURES2D)
	message(STATUS "Disable opencv_xfeatures2d module")
	endif()

	if(NOT WITH_opencv_ximgproc)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/ximgproc.cpp$")
	add_definitions(-DWITHOUT_XIMGPROC)
	message(STATUS "Disable opencv_ximgproc module")
	endif()
	
	if(NOT WITH_opencv_ml)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/ml.cpp$")
	add_definitions(-DWITHOUT_ML)
	message(STATUS "Disable opencv_ml module")
	endif() 

	if(NOT WITH_opencv_quality)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/quality.cpp$")
	add_definitions(-DWITHOUT_QUALITY)
	message(STATUS "Disable opencv_quality module")
	endif() 
	
	if(NOT WITH_opencv_text)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/text.cpp$")
	add_definitions(-DWITHOUT_TEXT)
	message(STATUS "Disable opencv_text module")
	endif() 
	
	if(NOT WITH_opencv_xphoto)
	list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/xphoto.cpp$")
	add_definitions(-DWITHOUT_XPHOTO)
	message(STATUS "Disable opencv_xphoto module")
	endif()
	
	include_directories(${OpenCV_INCLUDE_DIRS})
	#set(LIBS ${LIBS} ${OpenCV_LIBRARIES})


	if(CMAKE_GENERATOR MATCHES "Visual Studio")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
		
		set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib")
	endif()

	add_library(OpenCvSharpExtern SHARED ${OPENCVSHARP_FILES})
	target_link_libraries(OpenCvSharpExtern ${OpenCV_LIBRARIES})

	install(TARGETS OpenCvSharpExtern
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
	)
else(OpenCV_FOUND)
	message(FATAL_ERROR "OpenCv not found!")
endif(OpenCV_FOUND)
