#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, const char* argv[])
{
    char a[100];
    char b[100];
    char lat[9],lon[9],spe[6],course[6],day[7],time[7], satellite[3],altituden[5];//latγ�� lon���� spe�ٶ� course���� day������ timeʱ��
    FILE *fr,*fw;
    int i,ces=1;//timebig������ѭ������ timesmileʱ��ѭ������
    int numbig,numsm;//������ת������
    double speed;
    fr = fopen("C:\\Users\\asus\\Desktop\\gps\\GPS170510.log", "r+");
    if(fr==NULL)
        printf("fr�ļ���ʧ��\n");

    fw = fopen("C:\\Users\\asus\\Desktop\\gps\\GPS.csv", "w+");
    if(fw==NULL)
        printf("fw�ļ���ʧ��\n");
    fprintf(fw,"γ��,����,�ٶ�,����,����,ʱ��,��������,���θ߶�\n");//weidu jindu sudu hangxiang riqi shijian weixinshuxiang haiba
    while(!feof(fr))
    {

       fscanf(fr, "%s%s",a,b);
        printf("%s\n%s\n",a,b);

        for(i=0;i<8;i++)
            lat[i]=a[i+16];
        lat[8]='\0';
        printf("γ�ȣ�%s\n",lat);
            fprintf(fw,"%s,",lat);
        for(i=0;i<8;i++)
            lon[i]=a[i+27];
        lon[8]='\0';
        printf("���ȣ�%s\n",lon);
            fprintf(fw,"%s,",lon);
        for(i=0;i<6;i++)
            spe[i]=a[i+39];
        spe[5]='\0';
        speed = atoi(spe);
        speed = speed*1.852;
        printf("�ٶ�(km/h):%.2lf\n",speed);
            fprintf(fw,"%lf,",speed);
        for(i=0;i<6;i++)
            course[i]=a[i+45];
        course[5]='\0';
        printf("����:%s\n",course);
           fprintf(fw,"%s,",course);
        for(i=0;i<6;i++)
            day[i]=a[i+51];
        day[6]='\0';
        printf("����utc:%s\n",day);


        numbig = atoi(day);//�ַ���ת��Ϊ����
        printf("%d\n",numbig);
                   fprintf(fw,"%d,",numbig);
        for(i=0;i<8;i++)
            time[i]=a[i+7];
        time[6]='\0';
        numsm = atoi(time);
        if(numsm>=24000)
        {
            numsm=numsm-24000;
            numbig=numbig+10000;
        }
        printf("ʱ�䣺%d\n",numsm+8000);
                   fprintf(fw,"%d,",numsm);
        for(i=0;i<3;i++)
        satellite[i]=b[i+39];
        satellite[2]='\0';
        printf("��������:%s\n",satellite);
           fprintf(fw,"%s,",satellite);

        for(i=0;i<5;i++)
        altituden[i]=b[i+43];
        altituden[4]='\0';
        printf("���θ߶�:%s\n",altituden);
           fprintf(fw,"%s\n",altituden);

      // fprintf(fw,"%s,%s,%lf,%s,%d,%d\n",lat,lon,speed,course,numbig,numsm );
    }
    fclose(fw);
    fclose(fr);
    return 0;
}
