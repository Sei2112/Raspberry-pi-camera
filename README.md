# MyCam

This project uses the CSI camera on raspberry pi to take photos. You can put them all in the box to create your own mini camera.

## Table of Contents

* [Background](#Background)
* [Introduction](#Introduction)
  * [Software and hardware](##Software and hardware)
  * [Installation](##Installation)
  * [Usage](##Usage)
  * [Precautions](##Precautions)
* [Contributing](#Contributing)

## Background

This was a c++ test project when I was  testing the CSI camera. 

I found an C++ API that allowed me to control the camera( you can find details here: http://www.uco.es/investiga/grupos/ava/node/40) It's quite useful for those who want to use OpenCV in c++ instead of Python.

## Introduction

### Software and hardware

#### Software

* [Raspberry Pi OS(previously called Raspbian)](https://www.raspberrypi.org/software/)
* [wiringPi](http://wiringpi.com/download-and-install/)

* [RaspiCam](http://www.uco.es/investiga/grupos/ava/node/40)

#### Hardware

* [Raspberry Pi 4 Model B](https://www.raspberrypi.org/products/raspberry-pi-4-model-b/)
* CSI camera

### Installation

* **WiringPi** is a **PIN** based GPIO access library written in C. The installation guide can be found below:

  http://wiringpi.com/download-and-install/

* [RaspiCam](http://www.uco.es/investiga/grupos/ava/node/40) is a C++ API.

### Usage

* connect a key button to GPIO 7
* connect the camera and enable it in ***raspberry pi config***. 

* ```sh
  cd /xxx/Mycam/build
  cmake ..
  make
  ./simpletest_raspicam
  ```

### Precautions

* This is a test program, there might be inaccuracies and programming may not be clever. Discussion is welcomed
*  Since I am using VNC to program, the camera cannot display the preview screen. 
* Be careful when wiring. Static electricity may damage the camera.

### Contributing

@[Sei2112](https://github.com/Sei2112)


