#include <ctime>
#include <wiringPi.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
using namespace std;

#define Button 7
int tmp = 0;
int flag = 0;

void setup()
{
	wiringPiSetup();
	pinMode(Button, INPUT);
}

void camcap(raspicam::RaspiCam& C1)
{

	if((digitalRead(Button) == 1) & (flag == 0))
	{
		flag = 1;
	}
	if(flag)
	{
		if(digitalRead(Button) == 0)
		{
			flag = 0;
            cout<<"photoing"<<endl;
			C1.grab();
            unsigned char *data=new unsigned char[  C1.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB )];
    
            //extract the image in rgb format
            C1.retrieve ( data,raspicam::RASPICAM_FORMAT_RGB );//get camera image
    
            //save
            std::ofstream outFile ( "raspicam_image.ppm",std::ios::binary );
            outFile<<"P6\n"<<C1.getWidth() <<" "<<C1.getHeight() <<" 255\n";
            outFile.write ( ( char* ) data, C1.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB ) );
            
            cout<<"Image saved at raspicam_image.ppm"<<endl;
            
            //free resrources    
            delete data;	

            //display
            system("eog /home/pi/Desktop/Mycam/build/raspicam_image.ppm &");
		}
	}
}
 
int main ( int argc,char **argv ) {
    setup();
    raspicam::RaspiCam Camera; //Cmaera object
    
    //Open camera 
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
    
    //wait a while until camera stabilizes
    cout<<"Sleeping for 3 secs"<<endl;
    sleep(3);
    while(1)
    {
      camcap(Camera);  
    }
    return 0;
}