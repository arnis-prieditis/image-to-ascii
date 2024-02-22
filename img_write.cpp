#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char** argv){
    // printf("%d\n", argc);
    // for (int i=0; i<argc; i++){
    //     printf("%s\n", argv[i]);
    // }
    ofstream image;
    image.open("image1.ppm");

    image << "P3" <<  endl;
    image << "250 250" << endl;
    image << "255" << endl;

    for(int y=0; y<250; y++){
        for(int x=0; x<250; x++){
            image << (x+y)/2 << " " << (x+y)/2 << " " << (x+y)/2 << endl;
        }
    }

    image.close();
    return 0;
}