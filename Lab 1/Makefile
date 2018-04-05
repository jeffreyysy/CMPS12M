#Jeffrey Yeung
#jeyyeung
#CMPS 12M
#January 13, 2018
#Compiles HelloUser.java + HelloUser2.java and makes a jarfile Hello

JAVASRC = HelloUser.java HelloUser2.java
SOURCES = README Makefile $(JAVASRC)
MAINCLASS = HelloUser2
CLASSES = HelloUser.class HelloUser2.class
JARFILE = Hello

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-Class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(JAVASRC)
	javac -Xlint $(JAVASRC)
clean:
	rm $(CLASSES) $(JARFILE)
