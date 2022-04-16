#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *pt=fopen("dict.dic","r");
	char zf;
	char dl[10000]={0};
	int i=0;
	zf=getchar();
    while(zf!=EOF) //将输入的字符存入字符数组 
	{
        dl[i]=zf;
        zf=getchar();
        i++;
    }
    dl[i]='\0';//在字符数组最后一格加入'\0' 
	char gjc[12][12];//将文件里的关键词存入二维数组 
	i=0;
	int j=0;
	int k=0;
	while(!feof(pt)) 
	{
		zf = (char)fgetc(pt);
        while(zf != '\n' && zf != EOF){
            gjc[k][j] = zf;
            zf = (char)fgetc(pt);
            j++;//一个一个字母存 
        }
        j = 0;//刷新第二个方括号 
        k++;
	} 
	int st;
	int fg=1;int m,n;
	char *s;
    while (i < k)//循环k次，k是关键词的个数,循环一次修改一种关键词 
    {
        j = 0;
        s = gjc[i];//提取关键词到s 
        while (dl[j] != '\0')//一直读到段落结束 
        {
            if (dl[j] == s[0])//如果新读入的字母和当前待匹配的关键词首字母相同 
            {
                st = j;//将该单词触发首位置赋值给start 
                for (m = 1; s[m] != '\0'; m++)//循环 当前关键词长度 次 
                {
                    if (s[m] != dl[++j])//一旦有后续词汇不匹配就退出循环，说明不是该单词，给flag赋值为0 
                    {
                        fg = 0;
                        break;  
                    }
                }
                if (fg!=0)//flag不为0.说明当前单词含有关键词 
                {
                    dl[st] = '@';//该单词触发首位置赋值'@' 
                    for (n = st + 1; n <= j; n++)//将该单词触发部分全部替换为'#' 
                        dl[n] = '#';
                    j = j + 1;
                }
                else
                {
                    j = st + 1;
                    fg = 1;//复位flag 
                }
            }
            else 
			j++;
        }
        i++;//一个关键词已检查完毕，开始下一个关键词触发 
    }
    for (i = 0; dl[i] != '\0';)//关键词已替换完毕，开始输出 段落字符数组，并替换输出 已修改的部分 
    {
        if (dl[i] == '@')//检测到'@'，即修改部分首字母，直接输出乱码  
            printf("!@#$%^&*");
        else if(dl[i] != '#')//如果既不是'@'也不是'#'，即正常字母，则输出该字母 
            printf("%c", dl[i]);
        i++;
    }//相当于，遇到'@'输出乱码，遇到'#'什么也不输出(确保乱码长度一样)，遇到正常字母 则正常输出 
    
    fclose(pt);
    return 0;
	


	
}
