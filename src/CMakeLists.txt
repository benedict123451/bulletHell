add_library(bullethellLib STATIC 
			${CMAKE_CURRENT_SOURCE_DIR}/graph.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/generationBullet.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/worldcomponent.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/generationMotion.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/generationTransform.cpp)
target_include_directories(bullethellLib
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(mainTest_exe "bulletEnginetest.cpp")
add_executable(mainwindow_exe "main.cpp")

target_link_libraries(mainTest_exe
PRIVATE gtest::gtest
bullethellLib
)
target_link_libraries(mainwindow_exe PUBLIC sfml::sfml bullethellLib
# ou selon les besoins : sfml-system sfml-window sfml-graphics ...
)