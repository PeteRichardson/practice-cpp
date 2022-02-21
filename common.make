CXXFLAGS=-c -g -O0 -std=c++20 -I../common
SOURCE_FILES ?= \
    $(PROG_NAME).cc \
    utils.cc

VPATH=%.cc ../common

BUILDDIR := build
OBJECT_FILES     = $(SOURCE_FILES:%.cc=$(BUILDDIR)/%.o)

SYSLIBROOT	:= /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
LDFLAGS= \
	-demangle \
    -platform_version macos 12.0.0 12.1 \
	-syslibroot $(SYSLIBROOT) \
	-lSystem \
	-lc++ \
	$(EXTRA_LIBS)


all : build .gitignore $(PROG_NAME)

clean :
	rm -f $(PROG_NAME)
	rm -rf $(BUILDDIR)

$(BUILDDIR) : 
	@mkdir -p $(BUILDDIR)

.gitignore :	
	@echo $(PROG_NAME) > .gitignore
	@echo build/ >> .gitignore

.PHONY: all clean 

$(PROG_NAME) : $(OBJECT_FILES)
	$(LD) $(LDFLAGS)  -o $@ $^

$(OBJECT_FILES): $(BUILDDIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

