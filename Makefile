abc:
	flex -o lex.yy.cpp philip.lex
	bison -d -o philip.tab.cpp philip.y
	g++ lex.yy.cpp philip.hpp philip.cpp philip.tab.cpp
	
	
clean:
	
