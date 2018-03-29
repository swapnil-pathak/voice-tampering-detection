	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	 
	using namespace std;

	// WAVE PCM soundfile format

	typedef struct header_file
	{
	    char chunk_id[4];
	    int chunk_size;
	    char format[4];
	    char subchunk1_id[4];
	    int subchunk1_size;
	    short int audio_format;
	    short int num_channels;
	    int sample_rate;            // sample_rate denotes the sampling rate.
	    int byte_rate;
	    short int block_align;
	    short int bits_per_sample;
	    char subchunk2_id[4];
	    int subchunk2_size;         // subchunk2_size denotes the number of samples.
	} header;
int bupher1[10000000];
int bupher2[10000000];
	typedef struct header_file* header_p;
	 
	 
int compare(int ch)
{

char filename1[9];
FILE * infile1;
if(ch==1)
{
infile1 = fopen("dude.wav","rb");   // Open wave file in read mode
}
if(ch==2)
{
infile1 = fopen("test.wav","rb");
}

int o=0;
int BUFSIZE = 256;                  // BUFSIZE can be changed according to the frame size required (eg:512)
int count = 0;                      // For counting number of frames in wave file.
short int buff16[BUFSIZE];          // short int used for 16 bit as input data format is 16 bit PCM audio
header_p meta = (header_p)malloc(sizeof(header));   // header_p points to a header struct that contains the wave file metadata fields
int nb;                             // variable storing number of bytes returned



if (infile1)
{
    fread(meta, 1, sizeof(header), infile1);
if(ch==1)
{
cout<<"\nFile 1 details : ";
}
if(ch==2)
{
cout<<"\nFile 2 details : ";
}
    cout << "\n\n Size of Header file is "<<sizeof(*meta)<<" bytes" << endl;
    cout << " Sampling rate of the input wave file is "<< meta->sample_rate <<" Hz" << endl;
    cout << " Number of samples in wave file are " << meta->subchunk2_size << " samples" << endl;
    cout << " The number of channels of the file is "<< meta->num_channels << " channels" << endl;

    while (!feof(infile1))
    {

        nb = fread(buff16,1,BUFSIZE,infile1);    // Reading data in chunks of BUFSIZE
        do{
        for(int a=0;a<=15;a++)
        {
            if(ch==1)
            {
            bupher1[o]=buff16[a];
            o++;
            }
            if(ch==2)
            {            bupher2[o]=buff16[a];
            o++;
            }
        }
        }while(o<1000000);
        count++;                    // Incrementing Number of frames
    }
cout << " Number of frames in the input wave file are " <<count << endl;
}

return 0;
}
	 
	int main()
	 
	{
        compare(1);	//Extract samples from first file
	cout<<"\n";
        compare(2);	//Extract samples from second file

        for(int yo=0;yo<1000000;yo++)
        {
            if(bupher2[yo]==bupher1[yo])
            {
            }
            else
            {
                cout<<"\nTampering detected.\n\n";
                return 0;
            }
        }


            cout<<"\nAuthenticity determined.\n\n";


	return 0;
	}

