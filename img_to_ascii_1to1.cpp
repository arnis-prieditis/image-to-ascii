#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(int argc, char** argv){
    ifstream image;
    image.open("image1.ppm");

    ofstream art;
    art.open("ascii_art.txt");

    //get header information
    string type="", width="", height="", rgb="";
    image >> type;
    image >> width;
    image >> height;
    image >> rgb;

    int W=0, H=0, RGB=0;
    stringstream(width) >> W;
    stringstream(height) >> H;
    stringstream(rgb) >> RGB;

    // cout << W << H << RGB << endl;

    string red, green, blue;
    int r, g, b;
    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            image >> red;
            image >> green;
            image >> blue;
            stringstream(red) >> r;
            stringstream(green) >> g;
            stringstream(blue) >> b;
            int sum = r+g+b;
            char c=' ';
            if (sum < 100) c = '.';
            else if (sum < 200) c = '^'; 
            else if (sum < 300) c = '+';
            else if (sum < 400) c = '?';
            else if (sum < 500) c = 'X';
            else if (sum < 600) c = 'O';
            else if (sum < 700) c = '#';
            else c = '@';

            cout << c;
            art << c;
        }
        cout << endl;
        art << "\n";
    }

    image.close();
    art.close();
    return 0;
}