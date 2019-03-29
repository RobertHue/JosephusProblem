if( Boost_FOUND )

	# include_directories(${Boost_INCLUDE_DIRS})  -> is already in root CMakeLists.txt
	add_executable( JosephusTest.exe
		../Josephus.h
		JosephusTest.cc
	)
	target_link_libraries( JosephusTest.exe ${Boost_LIBRARIES} )

endif()

