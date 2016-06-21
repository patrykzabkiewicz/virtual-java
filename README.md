# Lightweight Java virtual machine

	Project is intended to provide a lightweight java virtual machine
	Can run both Java and C++ programs on seperate enviroments from underneath platform
	Your program will execute always the same way on every platform
	No JIT compilation and no different behaviour for different data
	Enterprise level of security, ECC checks and bulletprof isolation from outside world
	Perfect for Banking, Finance and Enterprises
	100% compatible with your current java code, but executes it faster and more safetly than JVM

## Description

	Main features are:
	- register based, with stack
	- application isolation, run every app in seperate enviroment
	- no batch memory allocation from kernel
	- dynamic memory allocation outside machine
	- returning memory to kernel after object is destroyed
	- no garbage colletion
	- destroy object and deallocate resources after pointer is released
	- all pointers are smart pointers
	- all refrences are counted to data object
	- no lazy initialization, all resources are initialized
		at the start of the system or dynamicly during runtime
	- no data duplication in memory, copy-on-write, one data, multiple pointers
	- 100% compatible with current java language spec, but executes instructions diffrently
	- continue running after program closed
	- prefetch resources, allocate before it's needed
	- predict resource allocation (no lazy allocation like normal java)
	- resolve dependencies and load them once, use multiple times
	- no cached interpreter of class files (better security)

	Tests:
	- unit tests with mocks
	- thread safty tests
	- memory leaks tests
	- compatibility tests
	- performance tests, how much time it takes the execute certain algorithm on certain data
	- security tests

	Security enhancments:
	- boundy checks
	- bit ecc checks on data types

## Usage

### Compilation:

#### Requirements
	pthreads
	ccache (optional) - speeds up compilation
	distcc (optional) - speeds up compilation with multiple nodes

#### Linux/*nix/BSD/POSIX
	git clone https://github.com/CppArchMasters/lightweight-java-vm.git
	mkdir build-lgjava
	cd build-lgjava
	cmake ../lightweight-java-vm
	make -j4

#### Windows
	git clone https://github.com/CppArchMasters/lightweight-java-vm.git
	mkdir build-lgjava
	cd build-lgjava
	cmake ../lightweight-java-vm
	msbuild lg-java.sln

	or just use Visual Studio to build

### Runing:
	lg-java [your-java-class-filename]

## Author
Author:		Patryk Zabkiewicz
Date: 		2016-03-23

## License
License:	GPL 3.0

