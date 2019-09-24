SRC:=parseXML.cpp myxml.cpp
CFLAG:=`pkg-config libxml-2.0 --cflag`

SOUR:=myxml
all:$(SOUR)
myxml:parseXML.o myxml.o
	g++ -o $@  $^ `pkg-config libxml-2.0 --libs --cflags`
%.o:%.cpp
	g++ -o $@ -c $^  `xml2-config --cflags`

clean:
	@rm -rf $(SOUR) *.o
