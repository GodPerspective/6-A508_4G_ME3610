#ifndef _GT20L16P1Y2_H_
#define _GT20L16P1Y2_H_

//---------------------------------------------------------------------------------
// ������ unsigned long unicode_muti_addr( unsigned short unicode)
// ˵����
// ���� �����ġ�ϣ���ġ�������ġ�ϣ�����ġ�̩��
// BaseAdd��˵�������ֿ����ֿ�оƬ�е���ʼ�ֽڵ�ַ��
// unicode����ʾunicode���루16bits��
// Address����ʾ���ֵ�����оƬ�е��ֽڵ�ַ��
//���㷽����
//���к���unsigned char find_zf_tab(unsigned short unicode) �ο����д���

//extern void r_dat_bat(unsigned long ADDRESS,unsigned int len,unsigned char *DZ_Data);


unsigned long unicode_muti_addr( unsigned short unicode,unsigned char *DZ_Data);

//---------------------------------------------------------------------------------
//������unsigned long unicode_alb_addr( unsigned short unicode_alb)
//˵����
//16���󲻵ȿ�������ϵ�ַ�
//BaseAdd��˵�������ֿ����ֿ�оƬ�е���ʼ�ֽڵ�ַ��
//unicode_alb����ʾunicode���루16bits��
//Address����ʾ���ֵ�����оƬ�е��ֽڵ�ַ��
//���㷽����
unsigned long unicode_alb_addr( unsigned short unicode_alb,unsigned char *DZ_Data);

//---------------------------------------------------------------------------------
//������unsigned long GB2312_addr( unsigned char MSB,unsigned char LSB )
//˵����
//15X16 GB2312���뺺���ַ�
//ZFAdd��HZAdd����ʾ�ַ��ͺ��ֵ���ʼ��ַ��
//MSB��LSB����ʾGB2312����ĸ��ֽں͵��ֽڡ�
//GB2312tab����ʾGB2312ת�����ʼ��ַ��
//Address����ʾ���ֵ�����оƬ�е��ֽڵ�ַ��
unsigned long GB2312_addr( unsigned char MSB,unsigned char LSB,unsigned char *DZ_Data);

//---------------------------------------------------------------------------------
//������unsigned long unicode_addr( unsigned short Unicode )
//˵����
//15X16 Unicode���뺺���ַ�
//ZFAdd��HZAdd����ʾ�ַ��ͺ��ֵ���ʼ��ַ��
//Unicode����ʾ���ֵ�unicode���롣
//Unicodetab����ʾunicodeת�����ʼ��ַ��
//Address����ʾ���ֵ�����оƬ�е��ֽڵ�ַ��
unsigned long unicode_addr( unsigned short Unicode,unsigned char *DZ_Data);


#endif

