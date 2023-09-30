ifeq ($(OS),Windows_NT)
	FLAGS = -DCMAKE_SH="CMAKE_SH-NOTFOUND" -G "MinGW Makefiles"
else
	FLAGS = ""
endif

all: clean reformat run

run: reload build exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build:
	cd cmake-build-debug;cmake --build . --target Project

exec:
	./cmake-build-debug/Project

clean:
	rm -rf cmake-build-debug

reload: mkdir_build
	cd cmake-build-debug;cmake $(FLAGS) ..

reformat:
	find src/ -iname "*.cpp" | xargs clang-format -i --style=file
	find include/ -iname "*.h" | xargs clang-format -i --style=file
