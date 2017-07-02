#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, const char* argv[])
{
    char a[100];
    char b[100];
    char lat[9],lon[9],spe[6],course[6],day[7],time[7], satellite[3],altituden[5];//lat纬度 lon经度 spe速度 course航向 day年月日 time时间
    FILE *fr,*fw;
    int i,ces=1;//timebig年月日循环变量 timesmile时间循环变量
    int numbig,numsm;//年月日转换变量
    double speed;
    fr = fopen("C:\\Users\\asus\\Desktop\\gps\\GPS170510.log", "r+");
    if(fr==NULL)
        printf("fr文件打开失败\n");

    fw = fopen("C:\\Users\\asus\\Desktop\\gps\\GPS.csv", "w+");
    if(fw==NULL)
        printf("fw文件打开失败\n");
    fprintf(fw,"纬度,经度,速度,航向,日期,时间,卫星数量,海拔高度\n");//weidu jindu sudu hangxiang riqi shijian weixinshuxiang haiba
    while(!feof(fr))
    {

       fscanf(fr, "%s%s",a,b);
        printf("%s\n%s\n",a,b);

        for(i=0;i<8;i++)
            lat[i]=a[i+16];
        lat[8]='\0';
        printf("纬度：%s\n",lat);
            fprintf(fw,"%s,",lat);
        for(i=0;i<8;i++)
            lon[i]=a[i+27];
        lon[8]='\0';
        printf("经度：%s\n",lon);
            fprintf(fw,"%s,",lon);
        for(i=0;i<6;i++)
            spe[i]=a[i+39];
        spe[5]='\0';
        speed = atoi(spe);
        speed = speed*1.852;
        printf("速度(km/h):%.2lf\n",speed);
            fprintf(fw,"%lf,",speed);
        for(i=0;i<6;i++)
            course[i]=a[i+45];
        course[5]='\0';
        printf("航向:%s\n",course);
           fprintf(fw,"%s,",course);
        for(i=0;i<6;i++)
            day[i]=a[i+51];
        day[6]='\0';
        printf("日期utc:%s\n",day);


        numbig = atoi(day);//字符串转换为整数
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
        printf("时间：%d\n",numsm+8000);
                   fprintf(fw,"%d,",numsm);
        for(i=0;i<3;i++)
        satellite[i]=b[i+39];
        satellite[2]='\0';
        printf("卫星数量:%s\n",satellite);
           fprintf(fw,"%s,",satellite);

        for(i=0;i<5;i++)
        altituden[i]=b[i+43];
        altituden[4]='\0';
        printf("海拔高度:%s\n",altituden);
           fprintf(fw,"%s\n",altituden);

      // fprintf(fw,"%s,%s,%lf,%s,%d,%d\n",lat,lon,speed,course,numbig,numsm );
    }
    fclose(fw);
    fclose(fr);
    return 0;
}
