#include <bits/stdc++.h>
#include "bmplib.cpp"
#define SIZE 256
using namespace std;
unsigned char pic[SIZE][SIZE];
unsigned char shuffled[SIZE][SIZE];
void loadImage ();
void saveImage ();
void shuffleImage();
int main()
{
    loadImage();
    shuffleImage();
    saveImage ();
    return 0;
}
void loadImage ()
{
    char imageFileName[100];
    cout << "Enter the source image file name (including .bmp): ";
    cin >> imageFileName;
    readGSBMP(imageFileName, pic);
}
void saveImage ()
{
    char imageFileName2[100];
    cout << "Enter the target image file name: (including .bmp): ";
    cin >> imageFileName2;
    writeGSBMP(imageFileName2, shuffled);
}
void moveQuarter(int idx, int i, int j )
{
    int temp = j;
    if (idx==1)
        for (int k=0; k < SIZE/2; i++,k++)
        {
            j = temp;
            for (int z=0; z< SIZE/2; j++,z++)
                shuffled[i][j]=pic[k][z];
        }
    else if (idx==2)
        for (int k = 0; k< SIZE/2; i++,k++)
        {
            j = temp;
            for (int z = SIZE/2; z< SIZE; j++,z++)
                shuffled[i][j]=pic[k][z];
        }
    else if (idx ==3)
        for (int k=  SIZE/2 ; k<SIZE; i++,k++)
        {
            j = temp;
            for (int z=0; z< SIZE/2; j++,z++)
                shuffled[i][j]=pic[k][z];
        }
    else if (idx ==4)
        for (int k =  SIZE/2; k < SIZE; i++,k++)
        {
            j = temp;
            for (int z = SIZE/2; z< SIZE; j++,z++)
                shuffled[i][j]=pic[k][z];
        }
}
void shuffleImage()
{
    int n ;
    cerr<<"Enter the order of quarters you want: ";
    for (int i =0 ; i <4 ; i++)
    {
        cin>>n;
        if (i==0) moveQuarter(n,0,0);
        else if (i==1) moveQuarter(n,0,SIZE/2);
        else if (i==2) moveQuarter(n,SIZE/2,0);
        else if (i==3) moveQuarter(n,SIZE/2,SIZE/2);
    }

}







