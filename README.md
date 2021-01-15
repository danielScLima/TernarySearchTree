TernarySearchTree
====================
Building with AppVeyor: [![Build status](https://ci.appveyor.com/api/projects/status/udg77gq0810e37es?svg=true)](https://ci.appveyor.com/project/DanielSLima/ternarysearchtree)

Building with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/TernarySearchTree.svg?branch=master)](https://www.travis-ci.com/danielScLima/TernarySearchTree)

This repository has a project with the implementation of a TernarySearchTree.

It is written in C++.

The code of the TernarySearchTree is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the TernarySearchTree (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the TernarySearchTree, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Search;](#markdown-header-emphasis)	
	* [Remove.](#markdown-header-emphasis)
	
- - -

Sample images: 
====================

## This is a image of a tree.

![Alt text](images/sample.png)


Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample.png)



Insertion steps: 
====================

## Initial:

![Alt text](images/insertion/0.png)

## Inserting "home":

![Alt text](images/insertion/1.png)

## Inserting "homeless":

![Alt text](images/insertion/2.png)

## Inserting "love":

![Alt text](images/insertion/3.png)

## Inserting "hi":

![Alt text](images/insertion/4.png)



Removing samples: 
====================

## Initial:

![Alt text](images/remove/0.png)

## Removing "hi":

![Alt text](images/remove/1.png)

## Removing "love":

![Alt text](images/remove/2.png)

## Removing "home":

![Alt text](images/remove/3.png)

## Removing "homeless":

![Alt text](images/remove/4.png)

