cmake_minimum_required(VERSION 3.0)

include_directories(${OpenCV_INCLUDE_DIR})
link_directories(${OpenCV_LIBRARY_DIR} ${OpenCV_LIBRARIES})


file(GLOB OPENCVSHARP_FILES *.cpp)
message("OPENCV FILES = " ${OPENCVSHARP_FILES})

list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/aruco.cpp$")
add_definitions(-DWITHOUT_ARUCO)

list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/dnn.cpp$")
add_definitions(-DWITHOUT_DNN)
list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/face.cpp$")
add_definitions(-DWITHOUT_FACE)
list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/ml.cpp$")
add_definitions(-DWITHOUT_ML)
list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/quality.cpp$")
add_definitions(-DWITHOUT_QUALITY)
list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/text.cpp$")
add_definitions(-DWITHOUT_TEXT)
list(FILTER OPENCVSHARP_FILES EXCLUDE REGEX ".*/xphoto.cpp$")
add_definitions(-DWITHOUT_XPHOTO)
message("OPENCV FILES = " ${OPENCVSHARP_FILES})

find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
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
endif(OpenCV_FOUND)
