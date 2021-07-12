add_library(hiberlite BeanLoader.cpp
		      BeanUpdater.cpp
		      ChildKiller.cpp
		      CppModel.cpp
		      Database.cpp
		      ModelExtractor.cpp
		      Registry.cpp
		      shared_res.cpp
		      sqlite3.c
		      SQLiteStmt.cpp
		      Visitor.cpp
		      )

target_include_directories(hiberlite INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

#install(TARGETS hiberlite DESTINATION lib)
#install(FILES   bean_ptr.h
#		bean_ptr_impl.hpp
#		BeanLoader.h
#		BeanUpdater_impl.hpp
#		ChildKiller.h
#		ChildKiller_impl.hpp
#		common.h
#		CppModel.h
#		Database.h
#		Database_tmpl_impl.hpp
#		db_error.h
#		hiberdefs.h
#		hiberlite.h
#		ModelExtractor.h
#		ModelExtractor_impl.hpp
#		nvp.h
#		Registry.h
#		Registry_impl.hpp
#		shared_res.h
#		some_types.h
#		sqlite3.h
#		SQLiteStmt.h
#		UpdateVisitor_tmpl.hpp
#		Visitor.h
#		Visitor_tmpl_impl.hpp DESTINATION include)