#include <stdio.h>
#include <stdlib.h>
//��ֹ���������Զ�����
#pragma pack(1)

/*BMPͼ���ļ����ֳ�4�����֣�
λͼ�ļ�ͷ��Bitmap File Header��
λͼ��Ϣͷ��Bitmap Info Header��
��ɫ��Color Map��
λͼ���ݣ���ͼ�����ݣ�Data Bits��Data Body��
*/ 

//λͼ�ļ�ͷ  ���ȹ̶���14�ֽ� 
typedef struct { 
	unsigned short int type; // λͼ�ļ����ͣ�������0x424D�����ַ�����BM��
	unsigned int size;		 // λͼ�ļ���С��������14���ֽ�
	unsigned short int reserved1;
	unsigned short int reserved2;
	unsigned int offset;	// �ļ�ͷ��ʵ�ʵ�λͼ���ݵ�ƫ���ֽ�����bitmap�ļ�ǰ3������(�ļ�ͷ����Ϣͷ����ɫ��)�ĳ���֮��
} FILEHEADER; 

// λͼ��Ϣͷ  ���ȹ̶���40�ֽ� 
typedef struct { 
	unsigned int size;			//���ṹ�ĳ��ȣ�Ϊ40���ֽ� 
	int width,height;			//λͼ�Ŀ�ߣ���λ�����أ� 

	unsigned short int planes;	// Ŀ���豸�ļ��𣬱�����1��
	unsigned short int bits;	// ÿ��������ռ��λ����bit������ֵ����Ϊ1���ڰ�ͼ�񣩡�4��16ɫͼ����8��256ɫ����24�����ɫͼ�����µ�BMP��ʽ֧��32λɫ��
	unsigned int compression; 	// λͼѹ�����ͣ���Ч��ֵΪBI_RGB��δ��ѹ������BI_RLE8��BI_RLE4...... 
	unsigned int imagesize;		// ʵ�ʵ�λͼ����ռ�õ��ֽ���
	int xresolution,yresolution;// ָ��Ŀ���豸��ˮƽ�ֱ��ʡ���ֱ�ֱ��� ����λ������/�ף� 
	unsigned int ncolours;		// λͼʵ���õ�����ɫ��
	unsigned int importantcolours; 	// λͼ��ʾ��������Ҫ����ɫ��
} INFOHEADER;

void change_bmp(char begin[],char target[],double a);
int main(int argc, char** argv){
	
	double a = atoi(argv[2])/100.0;
	change_bmp(argv[1],argv[3],a);
	printf("ת���ļ����  1.0--->%f",a);
	return 0;
}

void change_bmp(char begin[],char target[],double a){
	FILE *beg;
	FILE *tar;
	//�������ļ���Ŀ���ļ���
	beg = fopen(begin , "rb"); //�����ļ� 
	tar = fopen(target , "wb"); //д���ļ� 
	//�ж϶����ļ��Ƿ�Ϊ�� 
	if(beg == NULL){
		printf("���󣺶����ļ�Ϊ��\n");
		return ;
	}
	FILEHEADER filehead;
	INFOHEADER infohead;
	//��ȡ�����ļ�����Ϣ������
	fread(&filehead , sizeof(filehead) , 1 , beg);//λͼ�ļ�ͷ
	fread(&infohead , sizeof(infohead) , 1 , beg);//λͼ��Ϣͷ
	//��ȡ��Ⱥ͸߶� 
	int width = infohead.width;
	int height = infohead.height;
	//��ȡ������������Ϣ 
	unsigned char *data = (unsigned char*)malloc(sizeof(unsigned char)*width*3*height);
    fseek(beg,54,SEEK_SET);
	fread(data,width*3*height,1,beg);
	
	
	//�µ�ͼƬ�ĸ߶ȺͿ�� 
	int new_width = (int)1.0*a*width;
	int new_height = (int)1.0*a*height;
	//�����ļ�����Ϣͷ��BMP��Ϣͷ 
    filehead.size = new_width*new_height*3+54;
    infohead.height = new_height;
	infohead.width = new_width;
	fwrite(&filehead,sizeof(filehead),1,tar);
	fwrite(&infohead,sizeof(infohead),1,tar);
	//�����µ����ݿռ� 
	unsigned char *new_data = (unsigned char*)malloc(sizeof(unsigned char)*new_width*3*new_height);
	long src_x,src_y;//�ֱ����ԭ�ȵ�x,ԭ�ȵ�y;
	//�������к��Ĵ��룬˼·�ǰѺ�����λ��ӳ�䵽ԭ�ȵ�λ�ã���ԭ�����ص�����д��������ص����� 
	long i,j; 
	for(i=0;i<new_height;i++)
	{
		src_y = (long)1.0*i/a;
		unsigned char *src_row_begin = data + src_y*3*width;//�����ԭ���е���ʼ��; 
		for(j=0;j<new_width;j++)
		{
			src_x = (long)1.0*j/a;
			memcpy(new_data + i*new_width*3+j*3,src_row_begin + src_x * 3,3);
		}
		
	} 
	fseek(tar,54,SEEK_SET);
	fwrite(new_data,new_width*3*new_height,1,tar);
	printf("д���ļ��ɹ���");
	free(data);
	free(new_data);
	fclose(beg);
	fclose(tar);
}
	

